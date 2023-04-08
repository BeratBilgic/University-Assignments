//All of these codes were used in the browser console panel.
var doc = document.getElementById("paragraph");
doc.textContent = "Hello Word";

var elemant = document.createElement('p');
elemant.textContent = "Hello Word!";
document.body.appendChild(elemant);

var list = document.getElementById("t1");
var newItem = document.createElement("li");
var newText = document.createTextNode("Hello Word!");
list.appendChild(newItem);
newItem.appendChild(newText);

//"When using alert, promt, and confirm, there is no need to write window.alert, just writing .alert is enough."
window.alert("Hello Word");
alert("Hello Word");

var age = prompt("How old are you?");
console.log(age);
prompt("How old are you?", "0");

var result = confirm("Are you sure?");

//Using the DOM API(with graphical text: Canvas, SVG, or image file)
var canvas = document.createElement('canvas');
canvas.width = 500;
canvas.height = 250;
var ctx = canvas.getContext('2d');
ctx.font = '30px Cursive';
ctx.fillText("Hello Word!", 50, 50);
document.body.appendChild(canvas);

var img = new Image();
img.src = '../Week03-HTML_CSS/PepeLaugh.jpeg';
document.body.appendChild(img);