#include "vex.h"
using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain Brain;

controller ultrasense = controller(primary);
motor fl = motor(PORT15, ratio18_1, 1);
motor fr = motor(PORT17, ratio18_1, 0);
motor ml = motor(PORT3, ratio18_1, 0);
motor mr = motor(PORT7, ratio18_1, 1);
motor bl = motor(PORT4, ratio18_1, 1);
motor br = motor(PORT10, ratio18_1, 0);
motor_group L = motor_group(fl, ml, bl);
motor_group R = motor_group(fr, mr, br);
motor intake = motor(PORT12, ratio6_1, 1);
motor cata = motor(PORT2, ratio36_1, 1);
limit plush = limit(Brain.ThreeWirePort.B);
pneumatics bat = pneumatics(Brain.ThreeWirePort.A); // right wing
pneumatics wing = pneumatics(Brain.ThreeWirePort.H); // left wing
inertial spidey = inertial(PORT16);

bool remoteControlCodeEnabled = 1;

void vexcodeInit(void) {
  // Nothing to initialize
}