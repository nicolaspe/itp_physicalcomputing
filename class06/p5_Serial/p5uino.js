var serial;          // variable to hold an instance of the serialport library
var portName = '/dev/cu.usbmodem1421';  // fill in your serial port name here
var fromSerial = 0;
var rectSize = 100;

function setup() {
  serial = new p5.SerialPort();       // make a new instance of the serialport library
  serial.on('list', printList);  // set a callback function for the serialport list event
  serial.on('connected', serverConnected); // callback for connecting to the server
  serial.on('open', portOpen);        // callback for the port opening
  serial.on('data', serialEvent);     // callback for when new data arrives
  serial.on('error', serialError);    // callback for errors
  serial.on('close', portClose);      // callback for the port closing

  serial.list();                      // list the serial ports
  serial.open(portName);              // open a serial port

	createCanvas(400, 400);
	noStroke();
	rectMode(CENTER);
}

function draw(){
	background(0);
	fill(255);
	rect(fromSerial, mouseY, rectSize, 20);
}

// get the list of ports:
function printList(portList) {
	// portList is an array of serial port names
	for (var i = 0; i < portList.length; i++) {
		// Display the list the console:
		print(i + " " + portList[i]);
	}
}

function serverConnected() {
  print('connected to server.');
}
function portOpen() {
  print('the serial port opened.')
}
function serialEvent() {
	// read everything until the end of the line
	let stringFromSerial = serial.readLine();
	// check if it is something valid, if there's something there
	if(stringFromSerial.length > 0){
		var trimmedString = trim(stringFromSerial);
		fromSerial = Number(trimmedString);
		print(fromSerial);
		fromSerial = map(fromSerial, 0, 1023, rectSize/2, width-rectSize/2);
	}
}
function serialError(err) {
  println('Something went wrong with the serial port. ' + err);
}
function portClose() {
  print('The serial port closed.');
}
