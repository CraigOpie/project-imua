/********************************************************************
 *   
 *   Output (Serial and Radio)
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose 
 *   
 *   This module is used to streamline the printing process allowing
 *   a single command to print to both the Serial device and the 
 *   Radio device.  
 *   
 *   02/14/19 - Start Date
 *              
 ******************************************************************/


/********************************************************************
 *   Arguments
 *   
 *   Defaults to a blank space.
 *   Accepts String inputs to display
 *   
 *******************************************************************/


void Show() {
  
  Show(" ");
  
}

void Showln() {
  
  Showln(" ");
  
}


void Show(String message) {

  message = ((message == "") ? " " : message);
  
  /********************************************************************
   *   Perform Print Statements using Serial Connection
   *******************************************************************/
 
  Serial.print(message);

  
  /********************************************************************
   *   Perform Print Statements using Radio Connection
   *******************************************************************/
 
  myRadio.print(message);

}


void Showln(String message) {
  
  message = ((message == "") ? " " : message);
  
  /********************************************************************
   *   Perform Println Statements using Serial Connection
   *******************************************************************/
 
  Serial.println(message);

  
  /********************************************************************
   *   Perform Println Statements using Radio Connection
   *******************************************************************/
 
  myRadio.println(message);

}
