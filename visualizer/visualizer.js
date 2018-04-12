var win = {
    w : Math.max(document.documentElement.clientWidth, window.innerWidth || 0),
    h : Math.max(document.documentElement.clientHeight, window.innerHeight || 0),
};

var bars = [];
var vals = [];

var canvas;
var nb_x;
var step;
var b_width;
var x_pad = 0.05 * win.w;
var y_pad = 0;
var h_fact;

class Bar {
	constructor(val, pos) {
		this.val = val;
		this.x = x_pad + b_width * pos;
		this.y = y_pad + h_fact * val;
	}
	display() {
        strokeWeight(4);
        stroke('green');
        fill(0);
        rect(30, 20, this.x, this.y);
	}
}

function setup() {
    let pos = 0;
    let min = Math.min(vals);
    let max = Math.max(vals);
    canvas = createCanvas(win.w, win.h);
    nb_x = vals.length;
    h_fact = height * 0.65 / (max - min);
    step = 0.9 * width / nb_x;
    for (let i = 0; i < nb_x; i++)
        bars[i] = new Bar(vals[i] - min, ++pos);
}

function canvas_resize() {
    win.w = Math.max(document.documentElement.clientWidth, window.innerWidth || 0);
    win.h = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);
    resizeCanvas(win.w, win.h, true);
}

function set_origin() {
    translate(0, height / 5 * 4); //set bottom left as origin
}

function draw() {
    canvas_resize();
    set_origin();
    background(1);
    fill(255);
    for (let i = 0; i < nb_x; i++)
        bars.display
}
