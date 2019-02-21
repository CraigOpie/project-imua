/********************************************************************
 *   
 *   Serial Test
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose
 *   
 *   Verifies connection with the Serial device by printing 
 *   information about the project.
 *   
 *   02/20/19 - Start Date
 *              
 ******************************************************************/

void SerialTest() {
  
  /********************************************************************
   *   Perform Print Statements to Test Serial Connection
   *******************************************************************/
 
  Serial.print("*** ");
  Serial.print(school);
  Serial.print(" ***");
  Serial.println();
  
  Serial.print("*** ");
  Serial.print(project_name);
  Serial.print(" ***");
  Serial.println();
  
  Serial.print("*** ");
  Serial.print("Version: ");
  Serial.print(version_);
  Serial.print(" ***");
  Serial.println();
  
  Serial.print("*** ");
  Serial.print("Build date: ");
  Serial.print(build_date);
  Serial.print(" ***");
  Serial.println();

  Serial.print("*** ");
  Serial.print("URL: ");
  Serial.print(url);
  Serial.print(" ***");
  Serial.println();

}
