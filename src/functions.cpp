#include "vex.h"
#include "functions.hpp"
#include <string>
#include <cmath>
using namespace vex;
using namespace std;
using namespace chrono;

int auton = 1;
bool flapping = 0;
int b = 0; // intake control
bool punch = 0;

void autonslctr() {
  if (mash.ButtonRight.pressing()) {
      auton++;
      wait(200,msec);
  } else if (mash.ButtonLeft.pressing()) {
      auton--;
      wait(200,msec);
  }
  if (auton > 5) {
      auton = 1;
  } else if (auton < 1) {
      auton = 5;
  }
  if (auton == 1) {
      printing("RAWP");
  } else if (auton == 2) {
      printing("LAWP");
  } else if (auton == 3) {
      printing("ELIM");
  } else if (auton == 4) {
      printing("SKILLS");
  } else if (auton == 5) {
      printing("TEST");
  }
}

// motor coast
void msc(motor m) {
  m.stop(coast);
}

// motor spin
void msp(motor m, bool dir, double speed) {
  if (dir) {
      m.spin(fwd,speed,pct);
  } else {
      m.spin(rev,speed,pct);
  }
}

void spread() {
  bat.open();
  wing.open();
}

void fold() {
  bat.close();
  wing.close();
}

void wingaction() {
  if (flapping) {
    fold();
  } else {
      spread();
  }
}

steady_clock::time_point lastFlap;

void flap() {
  auto now = steady_clock::now();
  auto durLastFlap = duration_cast<milliseconds>(now - lastFlap).count();
  if (durLastFlap > 200) {
      wingaction();
      flapping = !flapping;
      lastFlap = now;
  }
}

steady_clock::time_point printake; // time last intake pressing

// intake thing
void intaking() {
  auto now = steady_clock::now(); // current time
  auto durLastTake = duration_cast<milliseconds>(now-printake).count();
  if(durLastTake > 150) {
    if (b==0) {
      if (mash.ButtonR1.pressing()) {
        intake.spin(rev,400,rpm);
        b = 1;
      } else if (mash.ButtonR2.pressing()) {
        intake.spin(fwd,400,rpm);
        b = 2;
      }
    } else if (b==1) {
      if (mash.ButtonR1.pressing()) {
        intake.stop(coast);
        b = 0;
      } else if (mash.ButtonR2.pressing()) {
        intake.spin(fwd,400,rpm);
        b = 2;
      }
    } else if (b==2) {
      if (mash.ButtonR2.pressing()) {
        intake.stop(coast);
        b = 0;
      } else if (mash.ButtonR1.pressing()) {
        intake.spin(rev,400,rpm);
        b = 1;
      }
    }
    printake = now;
  }
}

void setstop(int mode) {
  if (!mode) {
    L.setStopping(coast);
    R.setStopping(coast);
  } else if (mode == 1) {
    L.setStopping(brake);
    R.setStopping(brake);
  } else if (mode == 2) {
    L.setStopping(hold);
    R.setStopping(hold);
  }
}

void setv(double vel) {
  L.setVelocity(vel,pct);
  R.setVelocity(vel,pct);
}

void Fwd(double dist) {
  L.spinFor(fwd,dist*18,deg,0);
  R.spinFor(fwd,dist*18,deg);
}

void Rev(double dist) {
  L.spinFor(rev,dist*18,deg,0);
  R.spinFor(rev,dist*18,deg);
}

void lft(double ang, double adjust) {
  setstop(1);
  inert.setRotation(0,deg);
  while(fabs(inert.rotation(deg)) < ang) {
    double error = ang - fabs(inert.rotation(deg));
    R.spin(fwd,5 + error*adjust,pct);
    L.spin(rev,5 + error*adjust,pct);
  }
  L.stop();
  R.stop();
}

void rgt(double ang, double adjust) {
  setstop(1);
  inert.setRotation(0,deg);
  while(fabs(inert.rotation(deg)) < ang) {
    double error = ang - fabs(inert.rotation(deg));
    R.spin(rev,5 + error*adjust,pct);
    L.spin(fwd,5 + error*adjust,pct);
  }
  L.stop();
  R.stop();
}

void batmobile() {
  while (1) {
    double speed;
    if(mash.ButtonB.pressing()) {

    }
  }
}

void arcade() {
  while (1) {
    double leftspeed = pow((mash.Axis3.position() + mash.Axis4.position()), 3)/1000;
    double rightspeed = pow((mash.Axis3.position() - mash.Axis4.position()), 3)/1000;
    if(mash.ButtonL1.pressing() && mash.ButtonL2.pressing()) {
      L.spin(fwd,100,pct);
      R.spin(fwd,100,pct);
    } else if(mash.ButtonL1.pressing()) {
      L.spin(fwd,100,pct);
      R.spin(fwd,0,pct);
    } else if (mash.ButtonL2.pressing()) {
      L.spin(fwd,0,pct);
      R.spin(fwd,100,pct);
    } else {
      L.spin(fwd,leftspeed,pct);
      R.spin(fwd,rightspeed,pct);
    }
    if(mash.ButtonRight.pressing()) {
      msc(cata);
      setv(90);
      lft(13);
      Rev(55);
      rgt(135);
      setstop();
    }
  }
  this_thread::sleep_for(10);
}

void tank() {
  while (1) {
    if(mash.ButtonL1.pressing() && mash.ButtonL2.pressing()) {
      L.spin(fwd,100,pct);
      R.spin(fwd,100,pct);
    } else if(mash.ButtonL1.pressing()) {
      L.spin(fwd,100,pct);
      R.spin(fwd,0,pct);
    } else if (mash.ButtonL2.pressing()) {
      L.spin(fwd,0,pct);
      R.spin(fwd,100,pct);
    } else {
      double leftspeed = pow(mash.Axis3.position(), 3)/1000;
      double rightspeed = pow(mash.Axis2.position(), 3)/1000;
      L.spin(fwd,leftspeed,pct);
      R.spin(fwd,rightspeed,pct);
    }
  }
}

steady_clock::time_point lastHit;

void punching() {
  if (punch) {
    msp(cata);
  } else {
    msc(cata);
  }
}

void pullback() {
  auto now = steady_clock::now();
  auto durLastHit = duration_cast<milliseconds>(now - lastHit).count();
  if (durLastHit > 200) {
    punch = !punch;
    lastHit = now;
  }
}

void printing(string text) {
  mash.Screen.clearScreen();
  mash.Screen.setCursor(2,10);
  mash.Screen.print(text.c_str());
}

double temp(motor m) {return m.temperature(celsius);}

void pid(double target) {
  double kp = 5;
  double ki = 0;
  double kd = 0;
  double integral = 0;
  double derivative = 0;
  double lastError = 0;
  double error = target - (L.position(deg) + R.position(deg)) / 2;
  while (fabs(error) > 1) {
    integral += error;
    derivative = error - lastError;
    double speed = kp*error + ki*integral + kd*derivative;
    fl.spin(fwd,speed,pct);
    fr.spin(fwd,speed,pct);
    bl.spin(fwd,speed,pct);
    br.spin(fwd,speed,pct);
    ml.spin(fwd,speed,pct);
    mr.spin(fwd,speed,pct);
    lastError = error;
    error = target - (L.position(deg) + R.position(deg)) / 2;
  }
  L.stop();
  R.stop();
}

int tip() {
  if (inert.roll() > 15) {
    return 1; // go forward
  } else if (inert.roll() < 15) {
    return 2; // go backward
  } else {
    return 0;
  }
}

void tipping() {
  if (tip() == 1) {
    L.spin(fwd,100,pct);
    R.spin(fwd,100,pct);
  } else if (tip() == 2) {
    L.spin(rev,100,pct);
    R.spin(rev,100,pct);
  }
}