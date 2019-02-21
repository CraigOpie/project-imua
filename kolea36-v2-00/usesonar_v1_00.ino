/********************************************************************
 *   
 *   Use Sonar
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose 
 *   
 *   This module is used to activate sonar with a default frequency
 *   of 1.6 KHz.
 *   
 *   02/20/19 - Start Date
 *              
 ******************************************************************/


bool UseSonar(double focal_length) {

  /********************************************************************
   *   Local Variables
   *******************************************************************/

  double time_lapsed = 0.0;
  double range = 0.0;
  
  
  /********************************************************************
   *   Go Active on Sonar to Find Objects
   *******************************************************************/

  digitalWrite(sonar_ping, HIGH);
  delay(10);
  digitalWrite(sonar_ping, LOW);

  time_lapsed = pulseIn(sonar_echo, HIGH);
  range = ((time_lapsed * 0.034 / 2) / 2.54);

  Show("Object is " + (String)range + " inches away.");

  if (range <= focal_length) {
    return(true);
  } else {
    return(false);
  }
  
}
