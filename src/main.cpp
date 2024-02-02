/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Redwood Robotics                                          */
/*    Created:      1/27/2024, 10:39:17 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/
/* NAME                               PORT                         CART/TYPE   */
/* fl                                   1                          600 BLUE    */
/* fr                                   2                          600 BLUE    */
/* ml                                   3                          600 BLUE    */
/* mr                                   4                          600 BLUE    */
/* bl                                   5                          600 BLUE    */
/* br                                   6                          600 BLUE    */
/* bat                                  A                          PNEUMATIC   */
/* wing                                 B                          PNEUMATIC   */
/* intake                               4                          200 GREEN   */
/* cata                                 5                          200 GREEN   */
/* inert                                6                          INERTIAL    */
/* mash                               MAIN                         CONTROLLER  */
/* L                                  fl, ml, bl                   MOTOR GROUP */
/* R                                  fr, mr, br                   MOTOR GROUP */
/* Radio                                21                         RADIO       */
/* Brain                               -----                       BRAIN       */
/*-----------------------------------------------------------------------------*/


#include "vex.h"
#include "autons.hpp"
#include "functions.hpp"

using namespace vex;
using namespace std;

// A global instance of competition
competition Competition;

bool atnslct = 0;
bool hot = 0;
bool checkhot = 0;
bool set = 1; // calibration check


// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton(void) {
  vexcodeInit();
  setstop();
  fold();
  inert.calibrate();
  waitUntil(!inert.isCalibrating());
  while (!atnslct) {
    autonslctr();
    if (mash.ButtonB.pressing()) atnslct = 1;
    wait(10,msec);
  }
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}



/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.

  if (auton == 1) {
    auton1();
  } else if (auton == 2) {
    auton2();
  } else if (auton == 3) {
    auton3();
  } else if (auton == 4) {
    auton4();
  } else if (auton == 5) {
    auton5();
  } else {
    cout << "ERROR: auton not selected" << endl;
  }
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
  // User control code here, inside the loop

  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // wings
    mash.ButtonY.pressed(wingaction);
    mash.ButtonY.released(flap);

    // catapult
    mash.ButtonX.pressed(punching);
    mash.ButtonX.released(pullback);

    // intake
    intaking();

    // tempcheck
    if (fl.temperature(celsius) > 45 || fr.temperature(celsius) > 45 || ml.temperature(celsius) > 45 || mr.temperature(celsius) > 45 || bl.temperature(celsius) > 45 || br.temperature(celsius) > 45 || cata.temperature(celsius) > 45 || intake.temperature(celsius) > 45) {
      hot = 1;
    }
    if (hot && !checkhot) {
      printing("HOT");
      checkhot = 1;
    }


    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(10, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  Competition.bStopAllTasksBetweenModes = 0;
  // Run the pre-autonomous function.
  pre_auton();
  arcade();
  // Prevent main from exiting with an infinite loop.
  while (1) {
    wait(10, msec);
  }
}