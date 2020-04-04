/*
 * Program for forwarding from COM to BT and BT to COM 
 * via Controllino with HC-06 BT module
 */

String incomingStringBT;
String incomingStringCPU;
char charZero = '0';

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial2.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {

  //check for received data from BT module
  if(Serial2.available() > 0)
  {
    //Read the input as string
    incomingStringBT = Serial2.readString();

    //Echo the BT to Serial Comm terminal, return for clarity in terminal
    Serial.println("From Bluetooth: " + incomingStringBT);
  }

  //check for message from computer serial 
  if(Serial.available() > 0)
  {
    //Read the input as string
    incomingStringCPU = Serial.readString();

    //Echo the BT to Serial Comm terminal
    Serial.println("To Bluetooth: " + incomingStringCPU);

    //Echo the BT message back to BT, don't add newline
    Serial2.println(incomingStringCPU);
  }
  
}
