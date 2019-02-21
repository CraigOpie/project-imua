
/********************************************************************
 *   
 *   Kolea36
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose
 *   
 *   Sketch to drive rover unit                      
 *                                                                  
 *   This uses two data streams                                
 *   Serial - to whatever is connected to the unit, normally        
 *            will not be available during a mission (Serial)       
 *   Radio  - main data stream (myRadio)       
 *                                                                  
 *   Program editors:                                               
 *     Craig Opie                                                   
 *                                                                  
 *******************************************************************/


/********************************************************************
 *   Editing history
 *   
 *   02/20/19 - Version 2.00 - Craig:
 *   Code sites reference data from kolea36.
 *   - Enhanced code for modularity
 *   - Utilizes String objects vice char arrays
 *              
 *******************************************************************/


/********************************************************************
 *   Hardware setup
 *   
 *   24LC series of EEPROM
 *   25LC series of EEPROM
 *   3DR air radio
 *   555 timer
 *   Adafruit 9-DOF IMU L3GD20H+LSM303
 *   Adafruit ADXL326 breakout board
 *   Adafruit BMP280 breakout board
 *   Adafruit LIS3DH accelerometer
 *   Adafruit Metro Mini 328
 *   Adafruit Micro SD breakout board
 *   Arduino Uno R3
 *   Battery voltage monitor
 *   GE DC-DC SHHD003A0A
 *   Generic sheet for devices in to 92-3 cases
 *   SparkFun OpenLog breakout
 *   
 *******************************************************************/


/********************************************************************
 *   IO assignments
 *   
 *   digital 2 <-- XBee DOUT (not needed for hookup)
 *   digital 3 --> XBee DIN
 *   
 *******************************************************************/


/********************************************************************
 *   Other information
 *   
 *   This also needs a ground station with another XBee radio.
 *   For now both need to be at: 
 *     9600 baud 
 *     8 data bits 
 *     1 stop bit
 *   
 *******************************************************************/


/********************************************************************
 *   Includes
 *******************************************************************/

#include "headers/conclusion_v1_00.h"
#include "headers/devicestartup_v1_00.h"
#include "headers/motortest_v1_00.h"
#include "headers/moveforward_v1_00.h"
#include "headers/radiotest_v1_00.h"
#include "headers/serialtest_v1_00.h"
#include "headers/show_v1_00.h"
#include "headers/startmission_v1_00.h"
#include "headers/correctcourse_v1_00.h"
#include "headers/updatedisplacement_v1_00.h"
#include "headers/usesonar_v1_00.h"
#include <Adafruit_MotorShield.h>
#include <Servo.h>
#include <Wire.h>


/********************************************************************
 *   Global Variables
 *******************************************************************/

#define sonar_ping 9                // Sonar output.
#define sonar_echo 10               // Sonar input.
#define myRadio Serial

bool abort_mission = false;
bool blocked = false;
bool turn_port = true;
double angle_adjustment = 10.0;     // Measured in degrees.
double bearing = 0.00;              // Measured in degrees.
double displacement = 0.0;          // Total distance (inches) from starting point.
double distance_constant = 0.004;   // Constant used to change calculated distance.
double focal_length = 24.0;         // Used for determining when an object is too close.
double *vector_1;                   // Rovers vector coordinates with regard to starting point.
int travel_time = 5000;             // Length of time the Rover will move during forward motion.

// Calculated distance traveled during forward motion.
double distance = (distance_constant * travel_time);

// Project Identifiaction
String school = "Honolulu Community College - Spring 2019";
String url = "https://sites.google.com/a/hawaii.edu/honcc-mag-intranet/kolea/kolea36";
String project_name = "kolea36";
String version_ = "2.00";
String build_date = "02/20/19";
String project_id = "kolea36-v2-00";


/********************************************************************
 *   Setup Object Links/Pointers
 *******************************************************************/

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *stbdMotor = AFMS.getMotor(1);  
Adafruit_DCMotor *portMotor = AFMS.getMotor(2); 


/********************************************************************
 *   Main Function
 *******************************************************************/
 
void setup() {

  /********************************************************************
   *   Startup Devices and Initialize Radio Handshakes
   *******************************************************************/
 
  DeviceStartup();
  
  
  /********************************************************************
   *   Verify Serial Communications Work Correctly
   *******************************************************************/
 
  SerialTest();
  
  
  /********************************************************************
   *   Verify Radio Communications Work Correctly
   *******************************************************************/
 
  RadioTest();
  
  
  /********************************************************************
   *   Verify Motor Shield and Drivers Work Correctly
   *******************************************************************/
 
  MotorTest();
  
 
  /********************************************************************
   *   Report Status of Startup Process and Display New Screen
   *******************************************************************/
 
  abort_mission = StartMission();
 
}


void loop() {
  
  /********************************************************************
   *   Check if the Mission is Aborted
   *******************************************************************/
  
  if (abort_mission) {
    Conclusion();
  }
  
  /********************************************************************
   *   Move the Rover
   *******************************************************************/
  
  MoveForward(travel_time);

  
  /********************************************************************
   *   Update the Displacement Vector from Start
   *******************************************************************/
 
  vector_1 = UpdateDisplacement(bearing, distance, vector_1);

  
  /********************************************************************
   *   Calculate Total Displacement
   *******************************************************************/
   
  // Calculate displacement using Pathagorean's Theorem.
  displacement = sqrt(sq(vector_1[0]) + sq(vector_1[1]));
  Show((String)displacement);

  // End mission if Rover is greater than 11 feet from starting point.
  if (displacement > 132.0) {
    Show("Rover is greater than 10 feet from vehicle.");
    Conclusion();
  }

  
  /********************************************************************
   *   Check for Objects in Front of the Rover
   *******************************************************************/
 
  do {
    /********************************************************************
     *   Use Sonar to Check for Objects
     *******************************************************************/
    
    blocked = UseSonar(focal_length);
    
    
    /********************************************************************
     *   Correct the Rover's Course Due to Object
     *******************************************************************/
    
    if (blocked) {
      if (bearing >= 100.0) {
        turn_port = false;
        bearing -= angle_adjustment;
      }
      if (bearing <= -100.0) {
        turn_port = true;
        bearing += angle_adjustment;
      }
      CorrectCourse(angle_adjustment, turn_port);
    }

  } while (blocked);

}
