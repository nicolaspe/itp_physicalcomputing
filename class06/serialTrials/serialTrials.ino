
void setup() {
  // initialize Serial communication
  Serial.begin(9600);
  Serial.flush();
}

void loop() {
  
//  if(Serial.available() > 0){
//    
//    // read, BYTE by BYTE! (char by char)
////    int fromSerial = Serial.read();
//    
//    // to read AS A NUMBER
//    int fromSerial = Serial.parseInt();
//
//    // print message
//    Serial.print("The message is: ");
//    Serial.println(fromSerial);
//  }

  int bytesSent = Serial.write("hello");
  Serial.print(" "); 
  Serial.println(bytesSent);
  
  delay(500);
}

