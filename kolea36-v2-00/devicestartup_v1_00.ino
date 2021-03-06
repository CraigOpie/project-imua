/********************************************************************
 *   
 *   Device Startup
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose
 *   
 *   Set the baud rate for the serial and radio devices to allow
 *   proper communication to the controllers.
 *   
 *   Start the motor shield which allows control of the drive motor.
 *   
 *   Set the motor speed by adjusting the Pulse Width Modulation to
 *   the DC motor.
 *   
 *   Provide a delay to ensure all handshake operations are complete
 *   before transmitting crucial information over Radio.
 *   
 *   02/20/19 - Start Date
 *              
 ******************************************************************/


void DeviceStartup() {

  /********************************************************************
   *   Set Baud Rate
   *******************************************************************/
 
  Serial.begin(9600);
  myRadio.begin(9600);


  
  /********************************************************************
   *   Set Pin Modes for Sonar
   *******************************************************************/
 
  pinMode(sonar_ping, OUTPUT);
  pinMode(sonar_echo, INPUT);
  digitalWrite(sonar_ping, LOW);
  pulseIn(sonar_echo, LOW);
  


  /********************************************************************
   *   AdaFruit Motor Shield Startup
   *******************************************************************/
 
  AFMS.begin();


  
  /********************************************************************
   *   Set Pulse Width Modulation Speed for Motor
   *******************************************************************/
 
  stbdMotor -> setSpeed(150);
  portMotor -> setSpeed(150);
  
  
  
  /********************************************************************
   *   Provide Time for the Radio Devices to Complete Handshakes
   *******************************************************************/

  Showln("Device startup is in progress.  Please allow 15 seconds for handshake to complete.");
  Showln();
  
  for (int delay_ = 0; delay_ < 15 ; delay_++) {
    Show("*");
    delay(1000);
  }
  Showln();

}
