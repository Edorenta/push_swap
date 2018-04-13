var win = {
    w : Math.max(document.documentElement.clientWidth, window.innerWidth || 0),
    h : Math.max(document.documentElement.clientHeight, window.innerHeight || 0),
};

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
var h_fact;
var looping = false;
var stop_next = false;

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
        strokeWeight(1);
        stroke(color(211,140,0));
        fill(color(50,50,50));
        for (let i = 0; i < this.na; i++) {
            y = this.a[i] * mult;
            x = x_pad + (this.step) * i;
            rect(x, -y, this.step, y);
        }
        stroke(color(0,180,0));
        fill(color(50,50,50));
        for (let i = 0; i < this.nb; i++) {
            y = this.b[i] * mult;
            x = (win.w / 2) + x_pad + (this.step) * i;
            rect(x, -y, this.step, y);
        }
        if (stop_next == true) {
            noLoop();
            stop_next = false;
        }
    }
}

function setup() {
    noLoop();
    //document.getElementById("title_div").className += "rubberBand animated";
    let commands = document.getElementById('commands').innerHTML;
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

function draw() {
    canvas_resize();
    set_origin();
    stacks[it].display();
    if (it < nb_data - 1)
        it++;
}

function _reset() {
    it = 0;
}

function _next() {
    stop_next = true;    
    loop();
}

function _switch() {
    document.getElementById('bt1').innerHTML = looping ? "START" : "STOP";
    looping ? noLoop() : loop();
    looping = looping ? 0 : 1;
}
