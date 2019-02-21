/********************************************************************
 *   
 *   Motor Test
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose
 *   
 *   Place the motors in a known state (LOW-LOW), which is a rest 
 *   position (RELEASE).  
 *   
 *   Tests the motor functionality by operating the motor in the 
 *   forward direction for five seconds, then the reverse direction
 *   for five seconds, and then placing the motor back in the rest
 *   position.
 *   
 *   02/20/19 - Start Date
 *              
 ******************************************************************/
void MotorTest() {

  /********************************************************************
   *   Perform Print Statements to Test Serial Connection
   *******************************************************************/
 
  // Initialize Motors to 'low-low' State
  Showln("Initializing Motor State (LOW-LOW).");
  stbdMotor -> run(RELEASE); 
  portMotor -> run(RELEASE); 
  delay(500);

  // Test Stbd Motor in forward direction
  Showln("Testing Stbd Motor in the Forward Direction.");
  stbdMotor -> run(FORWARD);
  delay(5000);
  stbdMotor -> run(RELEASE); 
  delay(500);
  
  // Test Port Motor in forward direction
  Showln("Testing Port Motor in the Forward Direction.");
  portMotor -> run(FORWARD);
  delay(5000);
  portMotor -> run(RELEASE); 
  delay(500);

  // Test Stbd Motor in reverse direction
  Showln("Testing Stbd Motor in the Reverse Direction.");
  stbdMotor -> run(BACKWARD);
  delay(5000);
  stbdMotor -> run(RELEASE); 
  delay(500);

  // Test Port Motor in reverse direction
  Showln("Testing Port Motor in the Reverse Direction.");
  portMotor -> run(BACKWARD);
  delay(5000);
  portMotor -> run(RELEASE); 
  delay(500);
  
  // Motor Test Complete
  Showln("Motor Test completed satisfactorily.");

}
