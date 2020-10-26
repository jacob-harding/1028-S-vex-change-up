/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

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
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

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

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
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

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       francesca                                                 */
/*    Created:      Mon Oct 05 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

//vex::brain Brain;

vex::motor RightFront = vex::motor(vex::PORT4); 
vex::motor LeftFront = vex::motor(vex::PORT3, true);
vex::motor RightBack = vex::motor(vex::PORT5); 
vex::motor LeftBack = vex::motor(vex::PORT2, true); 

vex::motor LeftIntake = vex::motor(vex::PORT6); 
vex::motor RightIntake = vex::motor(vex::PORT7, true); 
vex::motor Intake = vex::motor(vex::PORT10);

vex::controller primaryController (vex::controllerType::primary);
vex::controller secondaryController (vex::controllerType::partner);

void drive (int time, bool reverse=false) {
  //Drives the robot for a certain period of time
  //Drives forward if reverse is false, backwards if reverse is true (defaults to false)

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
 
  vexcodeInit();
  while (true) {
    RightFront.spin(vex::directionType::fwd, (primaryController.Axis3.value() - primaryController.Axis4.value()), vex::velocityUnits::rpm);
    RightBack.spin(vex::directionType::fwd, (primaryController.Axis3.value()) - primaryController.Axis4.value(), vex::velocityUnits::rpm);
    LeftFront.spin(vex::directionType::fwd, (primaryController.Axis3.value()) + primaryController.Axis4.value(), vex::velocityUnits::rpm);
    LeftBack.spin(vex::directionType::fwd, (primaryController.Axis3.value()) + primaryController.Axis4.value(), vex::velocityUnits::rpm);
    //These if statements are for the intakes. 
    if (secondaryController.ButtonL1.pressing()) {
      //L1 intakes the "claws"
      Intake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
      
    } 
    else if (secondaryController.ButtonL2.pressing()) {
      //L2 outtakes the "wheels"
      Intake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
      
    } else {
      Intake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
      
    }

    if (secondaryController.ButtonR1.pressing()) {
      //L1 intakes the "claws"
      RightIntake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
      LeftIntake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
    } 
    else if (secondaryController.ButtonR2.pressing()) {
      //L2 outtakes the "wheels"
      RightIntake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
      LeftIntake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
    } else {
     RightIntake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
     LeftIntake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
      
    }
  
   LeftFront.spin(vex::directionType::fwd, (primaryController.Axis3.value()) + primaryController.Axis4.value(), vex::velocityUnits::rpm);
    LeftBack.spin(vex::directionType::fwd, (primaryController.Axis3.value()) + primaryController.Axis4.value(), vex::velocityUnits::rpm);
    //These if statements are for the intakes. I think there is a better way to do this
    if (secondaryController.ButtonL1.pressing()) {
      //L1 intakes the "claws"
    if (secondaryController.ButtonR1.pressing()) {
      //R1 intakes the "claws"
      LeftIntake.spin(vex::directionType::fwd);
      RightIntake.spin(vex::directionType::fwd);
    } else {

      LeftIntake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
      RightIntake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
    }

    if (secondaryController.ButtonR2.pressing()) {
      //R2 outtakes the "claws"
      LeftIntake.spin(vex::directionType::rev);
      RightIntake.spin(vex::directionType::rev);
    } else {
      LeftIntake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
      RightIntake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
    }

    if (secondaryController.ButtonL1.pressing()) {
      //L1 intakes the "wheels"
      Intake.spin(vex::directionType::fwd);
    } else {
      Intake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
    }

    if (secondaryController.ButtonL2.pressing()) {
      //L2 outtakes the "wheels"
      Intake.spin(vex::directionType::rev);
    } else {
      Intake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
    }
  }
  //Intake.spin(vex::directionType::fwd);

  }

  
  //Intake.spin(vex::directionType::fwd);
  // RightIntake.spin(vex::directionType::fwd);
  // LeftIntake.spin(vex::directionType::fwd);
  // RightFront.spin(vex::directionType::fwd);
  // LeftFront.spin(vex::directionType::fwd);
  // RightBack.spin(vex::directionType::fwd);
  // LeftBack.spin(vex::directionType::fwd);
}

 