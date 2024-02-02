#include "vex.h"
#include "functions.hpp"

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
        intake.spin(rev,100,pct);
        b = 1;
      } else if (mash.ButtonR2.pressing()) {
        intake.spin(fwd,100,pct);
        b = 2;
      }
    } else if (b==1) {
      if(mash.ButtonR1.pressing()) {
        intake.stop(coast);
        b = 0;
      } else if (mash.ButtonR2.pressing()) {
        intake.spin(fwd,100,pct);
        b = 2;
      }
    } else if (b==2) {
      if (mash.ButtonR2.pressing()) {
        intake.stop(coast);
        b = 0;
      } else if (mash.ButtonR1.pressing()) {
        intake.spin(rev,100,pct);
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

void frwd(double dist, double adjust) {
  double target = dist/(adjust*atan(1)*4)*360;
  L.spinFor(fwd,target,deg,0);
  R.spinFor(fwd,target,deg);  
}

void rvrs(double dist, double adjust) {
  double target = dist/(adjust*atan(1)*4)*360;
  L.spinFor(rev,target,deg,0);
  R.spinFor(rev,target,deg);  
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
    R.spin(fwd,20 + error*adjust,pct);
    L.spin(rev,20 + error*adjust,pct);
  }
  L.stop();
  R.stop();
}

void rgt(double ang, double adjust) {
  setstop(1);
  inert.setRotation(0,deg);
  while(fabs(inert.rotation(deg)) < ang) {
    double error = ang - fabs(inert.rotation(deg));
    R.spin(rev,20 + error*adjust,pct);
    L.spin(fwd,20 + error*adjust,pct);
  }
  L.stop();
  R.stop();
}

void batmobile() {
}

void arcade() {
  while (1) {
    double leftspeed = (mash.Axis3.position() + mash.Axis4.position())*(abs(mash.Axis3.position() + mash.Axis4.position()))/100;
    double rightspeed = (mash.Axis3.position() - mash.Axis4.position())*(abs(mash.Axis3.position() - mash.Axis4.position()))/100;
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
  }
  this_thread::sleep_for(10);
}

void tank() {
  if(mash.ButtonL1.pressing() && mash.ButtonL2.pressing()) {
    L.spin(fwd,100,pct);
    R.spin(fwd,100,pct);
}
  else if(mash.ButtonL1.pressing()) {
    L.spin(fwd,100,pct);
    R.spin(fwd,0,pct);
  } else if (mash.ButtonL2.pressing()) {
    L.spin(fwd,0,pct);
    R.spin(fwd,100,pct);
  }
  else {
    double leftspeed = mash.Axis3.position()*abs(mash.Axis3.position())/100;
    double rightspeed = mash.Axis2.position()*abs(mash.Axis2.position())/100;
    L.spin(fwd,leftspeed,pct);
    R.spin(fwd,rightspeed,pct);
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