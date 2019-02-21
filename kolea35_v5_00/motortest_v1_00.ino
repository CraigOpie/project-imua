/********************************************************************
 *   
 *   Motor Test
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose
 *   
 *   Place the motor in a known state (LOW-LOW), which is a rest 
 *   position (RELEASE).  
 *   
 *   Tests the motor functionality by operating the motor in the 
 *   forward direction for five seconds, then the reverse direction
 *   for five seconds, and then placing the motor back in the rest
 *   position.
 *   
 *   02/14/19 - Start Date
 *              
 ******************************************************************/
void MotorTest() {

  /********************************************************************
   *   Perform Print Statements to Test Serial Connection
   *******************************************************************/
 
  // Initialize Motor to 'low-low' State
  Showln("Initializing Motor State (LOW-LOW).");
  myMotor->run(RELEASE); 
  delay(500);

  // Test Motor in forward direction
  Showln("Testing Motor in the Forward Direction.");
  myMotor->run(FORWARD);
  delay(5000);
  myMotor->run(RELEASE); 
  delay(500);

  // Test Motor in reverse direction
  Showln("Testing Motor in the Reverse Direction.");
  myMotor->run(BACKWARD);
  delay(5000);
  myMotor->run(RELEASE); 
  delay(500);

  // Motor Test Complete
  Showln("Motor Test completed satisfactorily.");

}
