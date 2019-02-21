/********************************************************************
 *   
 *   Correct Course
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose 
 *   
 *   This module is used to change course due to an object.  
 *   
 *   02/20/19 - Start Date
 *              
 ******************************************************************/


void CorrectCourse(double angle_adjustment, bool turn_port) {

  /********************************************************************
   *   Turn the vehicle to the port side
   *******************************************************************/
 
  if (turn_port == true) {
    Showln("Turning " + (String)angle_adjustment + " degrees to the Port Side.");
    stbdMotor -> run(RELEASE); 
    portMotor -> run(BACKWARD); 
    delay(50 * angle_adjustment);
    portMotor -> run(RELEASE); 
    delay(500);
  } 

  /********************************************************************
   *   Turn the vehicle to the stbd side
   *******************************************************************/

  if (turn_port == false) {
    Showln("Turning " + (String)angle_adjustment + " degrees to the Stbd Side.");
    stbdMotor -> run(BACKWARD); 
    portMotor -> run(RELEASE); 
    delay(50 * angle_adjustment);
    stbdMotor -> run(RELEASE); 
    delay(500);
  }

}
