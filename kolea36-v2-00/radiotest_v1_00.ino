/********************************************************************
 *   
 *   Radio Test
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose
 *   
 *   Verifies connection with the Radio device by printing 
 *   information about the project.
 *   
 *   02/20/19 - Start Date
 *              
 ******************************************************************/
void RadioTest() {
  
  /********************************************************************
   *   Perform Print Statements to Test Radio Connection
   *******************************************************************/
 
  myRadio.print("*** ");
  myRadio.print(school);
  myRadio.print(" ***");
  myRadio.println();
  
  myRadio.print("*** ");
  myRadio.print(project_name);
  myRadio.print(" ***");
  myRadio.println();
  
  myRadio.print("*** ");
  myRadio.print("Version: ");
  myRadio.print(version_);
  myRadio.print(" ***");
  myRadio.println();
  
  myRadio.print("*** ");
  myRadio.print("Build date: ");
  myRadio.print(build_date);
  myRadio.print(" ***");
  myRadio.println();

  myRadio.print("*** ");
  myRadio.print("URL: ");
  myRadio.print(url);
  myRadio.print(" ***");
  myRadio.println();

}
