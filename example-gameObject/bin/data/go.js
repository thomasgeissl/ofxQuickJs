// import * as std from "std";

let x = 0;
let y = 0;
let width = 100;
let height = 100;
function setup() {
  console.log("js -> setup");
  console.log(`vars set from oF: ${testInt}, ${testFloat}, ${testString}`);
  of.setClipboardString("js -> setup");
  of.setFrameRate(60);
}

function update() {
  // console.log("js -> update");
  // console.log(of.getFrameRate());
  x = (x + 1) % of.getWidth();
  y = (y + 1) % of.getHeight();
}

function draw() {
  // console.log("js -> draw");
  const frameNum = of.getFrameNum();
  of.setColor(frameNum % 255, 0, frameNum % 255);
  of.drawRectangle(x, y, width, height);
}
function exit() {
  console.log("js -> exit");
}

function keyPressed(key) {
  console.log(`js -> key pressed - ${key}`);
}

function keyReleased(key) {
  console.log(`js -> key released - ${key}`);
  testInt++;
}

function mouseMoved(x, y) {
  // console.log(`js -> mouse moved - (${x}, ${y})`);
}

function mouseDragged(x, y) {
  console.log(`js -> mouse dragged - (${x}, ${y})`);
}

function mousePressed(x, y, button) {
  console.log(`js -> mouse pressed - ((${x}, ${y}), ${button})`);
}

function mouseReleased(x, y, button) {
  console.log(`js -> mouse released - ((${x}, ${y}), ${button})`);
}

function mouseEntered(x, y) {
  console.log(`js -> mouse entered - (${x}, ${y})`);
}

function mouseEntered(x, y) {
  console.log(`js -> mouse exited - (${x}, ${y})`);
}

function windowResized(width, height) {
  console.log(`js -> windowResized (${width}, ${height})`);
}

function dragEvent(x, y, files) {
  console.log(`js -> dragEvent (${x}, ${y})`);
  files.forEach((file) => {
    console.log(file);
  });
}
