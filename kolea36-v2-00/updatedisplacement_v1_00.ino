/********************************************************************
 *   
 *   Update Displacement
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose 
 *   
 *   This module is used to update displacement information.  
 *   
 *   02/20/19 - Start Date
 *              
 ******************************************************************/


double * UpdateDisplacement(double bearing, double distance, double vector_1[]) {

  /********************************************************************
   *   Local Variables
   *******************************************************************/
  
  double x = 0.0;
  double y = 0.0;
  double hypotenuse = distance;
  double vector_new[2];
  double vector_2[2];


  /********************************************************************
   *   Trigonomic Calculation
   *******************************************************************/

  x = (cos(bearing) * hypotenuse);
  y = (sin(bearing) * hypotenuse);
  
  vector_2[0] = x;
  vector_2[1] = y;
  
  /********************************************************************
   *   Update Vector_1[]
   *******************************************************************/

  for (int i = 0; i < 2; i++) {
    vector_new[i] = vector_1[i] + vector_2[i];
    
  }

  return(vector_new);

  
}
