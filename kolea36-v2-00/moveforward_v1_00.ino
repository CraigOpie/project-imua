/********************************************************************
 *   
 *   Move Forward
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose
 *   
 *   Move the Rover forward for a specified amount of time.
 *   
 *   02/20/19 - Start Date
 *              
 ******************************************************************/


void MoveForward(int msec) {

    /********************************************************************
     *   Move the Rover Forward
     *******************************************************************/

    Showln("Moving Forward.");
    stbdMotor -> run(FORWARD); 
    portMotor -> run(FORWARD); 
    delay(msec);
    stbdMotor -> run(RELEASE); 
    portMotor -> run(RELEASE); 
    delay(100);
  
    
}
