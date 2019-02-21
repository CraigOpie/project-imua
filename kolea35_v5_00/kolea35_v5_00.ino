
/********************************************************************
 *   
 *   Kolea35
 *   
 *******************************************************************   
 *******************************************************************
 *   Purpose
 *   
 *   Sketch to deploy a payload using a motor and lead screw                      
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
 *   02/14/19 - Version 5.00 - Craig:
 *   Code sites reference data from kolea38.
 *   - Enhanced code for modularity
 *   - Adds 'Show' and 'Showln' functions to print to both 'Serial' 
 *     and 'Radio' devices
 *   - Renames 'myRadio Serial1' to 'myRadio Serial' in Global 
 *     Variables
 *   - Utilizes String objects vice char arrays
 *   - Created 'raw_input' from 'myRadio' to verify value is within 
 *     the expected range prior to assigning to 'int_input' for 
 *     switch operations
 *   - Added a way to track how many times the mission is executed
 *     using variable 'mission_number'
 *   - Improved readability of transmissions using for loops
 *   - Moved 'mission' to the default 'loop' function
 *   - Implemented a switch statement vice multiple if statements
 *     in 'Mission' function
 *              
 *******************************************************************/


/********************************************************************
 *   Hardware setup
 *   
 *   Metro Mini 328
 *   possible radios to use:
 *   XBee PRO S1 - Note this device requires 3.3V for power input
 *   XBee PRO 900HP - alternate device
 *   3DR Air - needs 5 volts for power input
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
 *   If using the 3DR radio then it needs to be at: 
 *     57600 baud
 *     8 data bits
 *     1 stop bit
 *   
 *******************************************************************/


/********************************************************************
 *   Includes
 *******************************************************************/

#include "headers/conclusion_v1_00.h"
#include "headers/devicestartup_v1_00.h"
#include "headers/mission_v1_00.h"
#include "headers/motortest_v1_00.h"
#include "headers/pitches.h"
#include "headers/radiotest_v1_00.h"
#include "headers/serialtest_v1_00.h"
#include "headers/show_v1_00.h"
#include <Adafruit_MotorShield.h>
#include <Wire.h>


/********************************************************************
 *   Global Variables
 *******************************************************************/

#define speaker 10
#define myRadio Serial

String school = "Honolulu Community College - Spring 2019";
String url = "https://sites.google.com/a/hawaii.edu/honcc-mag-intranet/kolea/kolea35";
String project_name = "kolea35";
String version_ = "5.00";
String build_date = "02/14/19";
String project_id = "kolea35-v5-00";
int mission_number = 1;


/********************************************************************
 *   Setup Object Links/Pointers
 *******************************************************************/

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor = AFMS.getMotor(1); 


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
 
  // Clear screen
  for (int line = 0; line < 50 ; line++) {
    Showln();
  }
  
  // Display Separator
  for (int line = 0; line < 68 ; line++) {
    Show("*");
  }
  
  Showln("Project Imua - Deployment Trigger Ready For Use");
  
  // Display Separator
  for (int line = 0; line < 68 ; line++) {
    Show("*");
  }
 
}


void loop() {
  
  /********************************************************************
   *   Commence Project Mission
   *******************************************************************/
 
  Mission();

  
  /********************************************************************
   *   Report Completion of Project
   *******************************************************************/
 
  Conclusion();

  
  /********************************************************************
   *   Increment Mission Number
   *******************************************************************/
 
  mission_number++;

  
}
