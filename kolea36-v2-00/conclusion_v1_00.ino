/********************************************************************
 *   
 *   Conclusion
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose
 *   
 *   Return the motors to a known state (LOW-LOW), which is a rest 
 *   position (RELEASE).
 *   
 *   Inform everyone that the mission is complete.
 *   
 *   02/20/19 - Start Date
 *              
 ******************************************************************/


void Conclusion() {

  /********************************************************************
   *   Set Motor to Known Condition and Report Completion
   *******************************************************************/
 
  // Initialize Motors to 'low-low' State
  Showln("Initializing Motor State (LOW-LOW).");
  stbdMotor->run(RELEASE); 
  portMotor->run(RELEASE);
  delay(500);
  
  // Report Status of Mission Completion
  Showln("Mission completed successfully.");
  Showln();

}
