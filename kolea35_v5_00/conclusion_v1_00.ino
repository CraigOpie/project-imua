/********************************************************************
 *   
 *   Conclusion
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose
 *   
 *   Return the motor to a known state (LOW-LOW), which is a rest 
 *   position (RELEASE).
 *   
 *   Inform everyone that the mission is complete.
 *   
 *   02/14/19 - Start Date
 *              
 ******************************************************************/


void Conclusion() {

  /********************************************************************
   *   Set Motor to Known Condition and Report Completion
   *******************************************************************/
 
  // Initialize Motor to 'low-low' State
  Showln("Initializing Motor State (LOW-LOW).");
  myMotor->run(RELEASE); 
  delay(500);
  
  // Report Status of Mission Completion
  Showln("Mission completed successfully.");
  Showln();

}
