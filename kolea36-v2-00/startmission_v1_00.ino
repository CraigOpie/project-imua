/********************************************************************
 *   
 *   Start Mission
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose 
 *   
 *   This module is used to commence or abort the mission.  
 *   
 *   02/20/19 - Start Date
 *              
 ******************************************************************/


bool StartMission() {

  /********************************************************************
   *   Local Variables
   *******************************************************************/
  
  bool abort_status = false;
  bool condition = true;
  char char_input;
  int int_input = 65;
  int raw_input = 0;

  /********************************************************************
   *   Report Status of Startup Process and Display New Screen
   *******************************************************************/
 
  // Clear screen
  for (int line = 0; line < 50 ; line++) {
    Showln();
  }
  
  // Display Separator
  for (int line = 0; line < 68 ; line++) {
    Show("*");
  }
  
  Showln("Project Imua - Rover Ready For Use");
  
  // Display Separator
  for (int line = 0; line < 68 ; line++) {
    Show("*");
  }


  /********************************************************************
   *   Wait for Mission Commencement Trigger
   *******************************************************************/
 
  Showln("Waiting for Mission Commencement Trigger");
  Showln();
  Showln("Enter A to abort mission");
  Showln("Enter C to commence mission");
  Showln("Waiting for your command:");
  Showln();

  while (condition) {
    /********************************************************************
     *   Update Screen to Let User Know Process is Running
     *******************************************************************/
 
    Show("*");

    
    /********************************************************************
     *   Check If Input Is Present and Stores ASCII DEC Value
     *******************************************************************/
 
    if (myRadio.available() > 0) {
      raw_input = myRadio.read();
      if (raw_input >= 65 && raw_input <= 90) {
        int_input = raw_input;
        char_input = int_input;

        /********************************************************************
         *   Perform Function Based on Input
         *******************************************************************/
      
        switch (int_input) {
          
          /********************************************************************
           *   If the User Presses 'A'
           *******************************************************************/
          case 65:
            /********************************************************************
             *   Abort Mission
             *******************************************************************/
            Showln();
            Showln("Abort Mission Command Received.");
            abort_status = true;
            condition = false;
            break;
    
            
          /********************************************************************
           *   If the User Presses 'C'
           *******************************************************************/
          case 67:
            /********************************************************************
             *   Commence Mission 
             *******************************************************************/
            Showln();
            Showln("Commence Mission Command Received.");
            condition = false;
            break;
    
            
          /********************************************************************
           *   If the User Presses Anything Else
           *******************************************************************/
          default:
            /********************************************************************
             *   Run Payload Deployment Procedure
             *******************************************************************/
            Showln();
            Showln((String)char_input + " is an invalid input.");
            Showln();
            Showln("Enter A to abort mission");
            Showln("Enter C to commence mission");
            Showln("Waiting for your command:");
            Showln();
            break;
        }
      }
    }

    delay(5000);
    
  }


  /********************************************************************
   *   Return the abort status
   *******************************************************************/
 
  return(abort_status);

}
