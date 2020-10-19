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

vex::motor RightFront = vex::motor(vex::PORT4); 
vex::motor LeftFront = vex::motor(vex::PORT3, true);
vex::motor RightBack = vex::motor(vex::PORT5); 
vex::motor LeftBack = vex::motor(vex::PORT2, true); 

vex::motor LeftIntake = vex::motor(vex::PORT6); 
vex::motor RightIntake = vex::motor(vex::PORT7, true); 
vex::motor Intake = vex::motor(vex::PORT10);

vex::controller primaryController (vex::controllerType::primary);
vex::controller secondaryController (vex::controllerType::partner);



void drive (float time, timeUnits units, bool reverse=false) {
  if (reverse) {
    RightFront.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
    RightBack.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
    LeftFront.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
    LeftBack.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  } else {
    RightFront.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
    RightBack.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
    LeftFront.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
    LeftBack.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  }
  wait(time, units);
  RightFront.stop();
  RightBack.stop();
  LeftFront.stop();
  LeftBack.stop();
}
void moveBackward(int travelDistance){
    int currentRotation = (RightFront.rotation(vex::rotationUnits::deg) + LeftFront.rotation(vex::rotationUnits::deg) + RightBack.rotation(vex::rotationUnits::deg) + LeftBack.rotation(vex::rotationUnits::deg))/4;
    int goalRotation = currentRotation - travelDistance;
    while(currentRotation > goalRotation){
      RightFront.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
      RightBack.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
      LeftFront.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
      LeftBack.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
      currentRotation = (RightFront.rotation(vex::rotationUnits::deg) + LeftFront.rotation(vex::rotationUnits::deg) + RightBack.rotation(vex::rotationUnits::deg) + LeftBack.rotation(vex::rotationUnits::deg))/4;
    }
}
void drive (bool reverse=false) {
  if (reverse) {
    RightFront.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
    RightBack.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
    LeftFront.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
    LeftBack.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  } else {
    RightFront.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
    RightBack.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
    LeftFront.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
    LeftBack.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  }
}

void driveStop () {
  RightFront.stop();
  RightBack.stop();
  LeftFront.stop();
  LeftBack.stop();
}

void intakeClaws (float time, timeUnits units, bool reverse=false) {
  if (reverse) {
    RightIntake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
    LeftIntake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  } else {
    RightIntake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
    LeftIntake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  }
  wait(time, units);
  RightIntake.stop();
  LeftIntake.stop();
}

void intakeClaws (bool reverse=false) {
  if (reverse) {
    RightIntake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
    LeftIntake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  } else {
    RightIntake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
    LeftIntake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  }
}

void clawsStop () {
  RightIntake.stop();
  LeftIntake.stop();
}

void intakeWheels (float time, timeUnits units, bool reverse=false) {
  if (reverse) {
    Intake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  } else {
    Intake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  }
  wait(time, units);
  Intake.stop();
}

void intakeWheels (bool reverse=false) {
  if (reverse) {
    Intake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  } else {
    Intake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  }
}

void wheelsStop () {
  Intake.stop();
}

void turnRight (float time, timeUnits units) {
  RightFront.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  RightBack.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  LeftFront.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  LeftBack.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  wait(time, units);
  RightFront.stop();
  RightBack.stop();
  LeftFront.stop();
  LeftBack.stop();
}

void turnRight () {
  RightFront.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  RightBack.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  LeftFront.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  LeftBack.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
}

void turnLeft (float time, timeUnits units) {
  RightFront.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  RightBack.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  LeftFront.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  LeftBack.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  wait(time, units);
  RightFront.stop();
  RightBack.stop();
  LeftFront.stop();
  LeftBack.stop();
}

void turnLeft () {
  RightFront.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  RightBack.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
  LeftFront.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  LeftBack.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
}

int fixDeadSpot () {
  intakeClaws(500, vex::timeUnits::msec, true);
  intakeClaws(500, vex::timeUnits::msec);
  return (1);
}


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

  Intake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
  wait(200, vex::timeUnits::msec);
  Intake.stop();

  turnRight(400, vex::timeUnits::msec);
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

    RightFront.spin(vex::directionType::fwd, (primaryController.Axis3.value()
     - primaryController.Axis1.value()), vex::velocityUnits::rpm);
    RightBack.spin(vex::directionType::fwd, (primaryController.Axis3.value())
     - primaryController.Axis1.value(), vex::velocityUnits::rpm);
    LeftFront.spin(vex::directionType::fwd, (primaryController.Axis3.value())
     + primaryController.Axis1.value(), vex::velocityUnits::rpm);
    LeftBack.spin(vex::directionType::fwd, (primaryController.Axis3.value())
     + primaryController.Axis1.value(), vex::velocityUnits::rpm);

    //These if statements are for the intakes. 
    if (secondaryController.ButtonL1.pressing()) {
      //L1 intakes the "claws"
      // Intake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
      intakeWheels();
    } 
    else if (secondaryController.ButtonL2.pressing()) {
      //L2 outtakes the "claws"
      Intake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
      
    }
    else {
      Intake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
      
    }

    if (secondaryController.ButtonA.pressing()) {
      vex::task Task = vex::task(fixDeadSpot);
    } else if (secondaryController.ButtonR1.pressing()) {
      //R1 intakes the "wheels"
      RightIntake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
      LeftIntake.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
    } 
    else if (secondaryController.ButtonR2.pressing()) {
      //R2 outtakes the "wheels"
      RightIntake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
      LeftIntake.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
    }
    else {
     RightIntake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
     LeftIntake.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
    }

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
