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
    //These if statements are for the intakes. I think there is a better way to do this
    if (secondaryController.ButtonL1.pressing()) {
      //L1 intakes the "claws"
      LeftIntake.spin(vex::directionType::fwd);
      RightIntake.spin(vex::directionType::fwd);
    } else {
      
    }
  }
  //Intake.spin(vex::directionType::fwd);
  // RightIntake.spin(vex::directionType::fwd);
  // LeftIntake.spin(vex::directionType::fwd);
  // RightFront.spin(vex::directionType::fwd);
  // LeftFront.spin(vex::directionType::fwd);
  // RightBack.spin(vex::directionType::fwd);
  // LeftBack.spin(vex::directionType::fwd);
}