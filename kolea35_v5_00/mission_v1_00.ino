/********************************************************************
 *   
 *   Mission
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose
 *   
 *   Inform the user all of the accepted commands.  
 *   
 *   Prevent out-of-range errors by verifing the 'raw_input' received
 *   from the Radio tranmission is within the required range before
 *   assigning the value to 'int_input'.
 *   
 *   Provide a method for the user to control motor functions on the
 *   deployment trigger.  This is accomplished using a 'switch' 
 *   statement with the following cases:
 *   - 'T' is used as the testing trigger.  This causes the unit
 *     to beep in four second intervals.
 *   - 'L' is used as the loading trigger.  This allows the user
 *     to drive the motor in the reverse direction for loading 
 *     the payload.  The status lasts for five seconds.
 *   - 'D' is used as the deployment trigger.  This allows the user
 *     to deploy the payload by running the motor in the forward 
 *     direction for thirty seconds.
 *   - 'X' is used to end the mission.
 *   - Everything else provides a rest status for the trigger.
 *   
 *   02/14/19 - Start Date
 *              
 ******************************************************************/


void Mission() {

  /********************************************************************
   *   Local variables
   *******************************************************************/

  bool condition = true;
  char char_input;
  int event = 1;
  int int_input = 65;
  int raw_input = 0;

  
  /********************************************************************
   *   Display Mission Screen
   *******************************************************************/
 
  Showln("Commencing Mission:");
  Showln();
  Showln("Enter T to beep in 4 sec intervals");
  Showln("Enter L to load");
  Showln("Enter D to deploy for 30 sec");
  Showln("Enter X to end mission");
  Showln("Please input a command:");
  Showln();

  
  /********************************************************************
   *   Mission Loop
   *******************************************************************/
 
  while (condition) {
    /********************************************************************
     *   Print Event Info
     *******************************************************************/
 
    Show("Event: #");
    Showln((String)event);

    
    /********************************************************************
     *   Check If Input Is Present and Stores ASCII DEC Value
     *******************************************************************/
 
    if (myRadio.available ( ) > 0) {
      raw_input = myRadio.read();
      if (raw_input >= 65 && raw_input <= 90) {
        int_input = raw_input;
        char_input = int_input;
      }
    }

    
    /********************************************************************
     *   Perform Function Based on Input
     *******************************************************************/
  
    switch (int_input) {
      
      /********************************************************************
       *   If the User Presses 'T'
       *******************************************************************/
      case 84:
        /********************************************************************
         *   Run Diagnostics to Verify Proper Operation
         *******************************************************************/
        Showln("Test Command Received.");
        Show("Your input: ");
        Showln((String)char_input);
        tone(speaker,NOTE_C7);
        delay(4000);
        noTone(speaker);
        delay(4000);
        break;

        
      /********************************************************************
       *   If the User Presses 'L'
       *******************************************************************/
      case 76:
        /********************************************************************
         *   Run Payload Loading Procedure
         *******************************************************************/
        Showln("Loading Payload Command Received (5 seconds).");
        Show("Your input:");
        Showln((String)char_input);
        myMotor -> run(RELEASE);
        delay(500);
        myMotor -> run(BACKWARD);
        delay(5000);
        myMotor -> run(RELEASE);
        delay(500);
        break;

        
      /********************************************************************
       *   If the User Presses 'D'
       *******************************************************************/
      case 68:
        /********************************************************************
         *   Run Payload Deployment Procedure
         *******************************************************************/
        Showln("Deployment Command Received (30 seconds.");
        myMotor -> run(RELEASE);
        delay(500);
        myMotor -> run(FORWARD);
        delay(30000);
        myMotor -> run(RELEASE);
        delay(500);
        break;

        
      /********************************************************************
       *   If the User Presses 'X'
       *******************************************************************/
      case 88:
        /********************************************************************
         *   Produces a False Condition Stopping the While Loop 
         *******************************************************************/
        condition = false;
        break;

        
      /********************************************************************
       *   If the User Presses Anything Else
       *******************************************************************/
      default:
        /********************************************************************
         *   Run Payload Deployment Procedure
         *******************************************************************/
        Showln("Trigger idle.");
        Show("Your input: ");
        Showln((String)char_input);
        tone(speaker, NOTE_F7);
        delay(1000);
        noTone(speaker);
        delay(1000);
        break;
    }

    
    /********************************************************************
     *   Increment The Event Number
     *******************************************************************/
  
    event++;

    
  }
}
