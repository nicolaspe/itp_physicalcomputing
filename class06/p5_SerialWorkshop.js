var portName = '/dev/cu.usbmodem1421';
var serial;
var bg = 0;
var col = 255;
var button = 1:

function setup(){
	createCanvas(640, 420);
	noStroke();

	serial = new p5.SerialPort();
	serial.open(portName);
	serial.on('data', parseData);			// function to read incomming data
	serial.on('error', serialError);	// function to catch errors
}

function draw(){
	background(bg);
	if (button == 0){
		fill(col);
		ellipse(width/2, height/2, 200);
	}
}

function parseData(){
	var inData = serial.readLine();
	if (inData.length > 0){
		var values = inData.split(',');
		// readLine() returns Strings! convert it to int to use it
		button = int(values[0])
		bg  = int(values[1]);
		col = int(values[2]);
	}

	// read a single value
}
function serialError(err){
	console.log(err);
}
