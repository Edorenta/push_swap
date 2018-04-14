/* THE FOLLOWING FUNCTION MAKES THE SPEED FOLLOW THE BAR THUMB */

var win = {
    w : Math.max(document.documentElement.clientWidth, window.innerWidth || 0),
    h : Math.max(document.documentElement.clientHeight, window.innerHeight || 0),
};
var bar_w;

/* THE FOLLOWING FUNCTION CODE USES P5JS FOR CANVAS RENDERING AND IS THE COREOF THE VISUALIZER */

var max;
var min;
var mult;
var data;
var stacks = [];
var it = 0;
var canvas;
var nb_data;
var x_g_pad = win.w / 9.2;
var x_pad = x_g_pad / 4;
var looping = false;

Array.prototype.max = function() {
    return Math.max.apply(null, this);
};

Array.prototype.min = function() {
    return Math.min.apply(null, this);
};

class Stacks {
    constructor(pass) {
        this.a = [];
        this.b = [];
        this.op = pass.op;
        this.na = Object.keys(pass.a).length;
        this.nb = Object.keys(pass.b).length;
        this.nx = this.na + this.nb;
        this.step = (win.w / 2.2) / Math.max(this.na, this.nb);
        for (let i = 0; i < this.na; i++) 
            this.a[i] = pass.a[i] - min;
        for (let i = 0; i < this.nb; i++)
            this.b[i] = pass.b[i] - min;
    }
    display() {
        let x;
        let y;
        let moved_a = [];
        let moved_b = [];
        switch (this.op) {
            case 'sa':
                moved_a[0] = 0;
                moved_a[1] = 1;
                break;
            case 'sb':
                moved_b[0] = 0;
                moved_b[1] = 1;
                break;
            case 'ss':
                moved_a[0] = 0;
                moved_a[1] = 1;
                moved_b[0] = 0;
                moved_b[1] = 1;
                break;
            case 'pa':
                moved_a[0] = 0;
                moved_b[0] = 0;
                break;
            case 'pb':
                moved_a[0] = 0;
                moved_b[0] = 0;
                break;
            case 'ra':
                moved_a[0] = this.na - 1;
                break;
            case 'rb':
                moved_b[0] = this.nb - 1;
                break;
            case 'rr':
                moved_a[0] = this.na - 1;
                moved_b[0] = this.nb - 1;
                break;
            case 'rra':
                moved_a[0] = 0;
                break;
            case 'rrb':
                moved_b[0] = 0;
                break;
            case 'rrr':
                moved_a[0] = 0;
                moved_b[0] = 0;
                break;
            default:
                moved_a[0] = this.na;
                moved_a[1] = this.na;
                moved_b[0] = this.nb;
                moved_b[1] = this.nb;
        }
        strokeWeight(1);
        stroke(color(211,140,0));
        fill(color(50,50,50));
        for (let i = 0; i < this.na; i++) {
            y = this.a[i] * mult;
            x = x_pad + (this.step) * i;
            if (i == moved_a[0] || i == moved_a[1]) {
                fill(color(211,140,0));
                stroke(color(50,50,50));
                rect(x, -y, this.step - 2, y);
                stroke(color(211,140,0));
                fill(color(50,50,50));
            }
            else rect(x, -y, this.step - 2, y);
        }
        stroke(color(0,180,0));
        fill(color(50,50,50));
        for (let i = 0; i < this.nb; i++) {
            y = this.b[i] * mult;
            x = (win.w / 2) + x_pad + (this.step) * i;
            if (i == moved_b[0] || i == moved_b[1]) {
                fill(color(0,180,0));
                stroke(color(50,50,50));
                rect(x, -y, this.step - 2, y);
                stroke(color(0,180,0));
                fill(color(50,50,50));
            }
            else rect(x, -y, this.step - 2, y);
        }
    }
}

function refresh_box() {
  speed_box.style.left = Math.round(((bar_w - 14) * (speed_slider.value) / 100) - 21, 0) + 'px';
  set_speed();
}

function setup() {
    noLoop();
    var speed_slider = document.getElementById('speed_slider');
    var speed_box = document.getElementById('speed_box');
    var container = document.getElementById('speed_set');
    var commands = document.getElementById('commands').innerHTML;
    bar_w = container.offsetWidth;
    speed_slider.addEventListener('input', refresh_box);
    speed_box.addEventListener('input', refresh_box);
    //document.getElementById("title_div").className '+=' "rubberBand animated";
    data = JSON.parse(commands).Stacks;
    nb_data = Object.keys(data).length;
    console.log(data);
    max = Math.max(data[0].a.max(), data[0].b.max());
    min = Math.min(data[0].a.min(), data[0].b.min());
    mult = (win.h / 1.5) / (max - min);
    for (let pass = 0; pass < nb_data; pass++)
        stacks[pass] = new Stacks(data[pass]);
    canvas = createCanvas(win.w, win.h);
}

function canvas_resize() {
    win.w = Math.max(document.documentElement.clientWidth, window.innerWidth || 0);
    win.h = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);
    resizeCanvas(win.w, win.h, true);
}

function set_origin() {
    translate(0, height / 6 * 5); //set bottom left as origin
    background(0);
    stroke(255);
    strokeWeight(1);
    line(0, 0, win.w, 0);
    line(win.w / 2, 0, win.w / 2, -win.h / 6 * 4);
}

function set_speed() {
    frameRate(speed_box.value * 60 / 100);
}

function draw() {
    canvas_resize();
    set_origin();
    set_speed();
    stacks[it].display();
    if (it < nb_data - 1) it++;
    if (looping && it == nb_data) _switch();
}

function _reset() {
    it = 0;
    redraw();
    looping == false ? noLoop() : 0;
}

function _next() {
    redraw();
    noLoop();
}

function _switch() {
    document.getElementById('bt1').innerHTML = looping ? "START" : "STOP";
    looping ? noLoop() : loop();
    looping = looping ? 0 : 1;
}
