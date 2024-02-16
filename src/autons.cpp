#include "vex.h"
#include "autons.hpp"
#include "functions.hpp"
using namespace vex;


/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
*/

// Right Side AWP 4 triballs
void auton1() {
  setv(36);
  Fwd(29);
  rgt(90);
  msp(intake,1,90);
  wait(100,msec);
  rgt(135);
  msp(intake,0);
  Fwd(20);
  wait(300,msec);
  setv(10);
  Rev(0.4);
  rgt(170);
  setv(36);
  msp(intake,1);
  wait(100,msec);
  lft(60);
  wait(100,msec);
  msp(intake,0);
  Fwd(4);
  R.spin(fwd);
  wait(1,sec);
  R.stop();
  msc(intake);
  spread();
  Rev(20);
  wait(100,msec);
  Fwd(5);
  wait(100,msec);
  Rev(5);
  wait(100,msec);
  Fwd(5);
  rgt(180);
  msp(intake,1,90);
  wait(100,msec);
  Fwd(5);
  wait(100,msec);
  Rev(5);
}

// Left Side AWP
void auton2() {
  setv(50);
  wing.open();
  wait(300,msec);
  lft(45);
  wait(40,msec);
  wing.close();
  rgt(10); 
  msp(intake,1,90);
  setv(100);
  Fwd(12);
  wait(750,msec);
  Rev(1);
  lft(78);
  msc(intake);
  setv(40);
  Rev(35);
  wing.open();
  lft(25);
}

// Left Side Elims
void auton3() {
  Rev(20);
  Fwd(5);
  Rev(15);
  Fwd(5);
  Rev(15);
}

// skills
void auton4() {
  timer t;
  t.clear();
  msp(cata);
  waitUntil(t.time(sec) >= 30);
  msc(cata);
  setv(50);
  lft(13);
  Rev(63);
  L.stop();
  R.stop();
  rgt(120);
  Rev(25);
  wait(100,msec);
  lft(40);
  Rev(17);
  spread();
  lft(90);
  L.spin(rev,50,pct);
  R.spin(rev,50,pct);
  wait(1,sec);
  L.stop();
  R.stop();
  fold();
  Fwd(10);
  spread();
  Rev(10);
  fold();
  Fwd(10);
  rgt(90);
  Rev(10);
  spread();
  lft(90);
  Rev(15);
  fold();
  Fwd(10);
  spread();
  Rev(10);
  fold();
  Fwd(10);
  lft(50);
  Fwd(10);
  rgt(45);
  spread();
  L.spin(rev);
  R.spin(rev);
  wait(1.5,sec);
  L.stop();
  R.stop();
  Fwd(5);
}

// drivetrain test
void auton5 () {
  rgt(90);
  wait(10,sec);
  msp(fr);
  wait(1,sec);
  msc(fr);
  msp(bl);
  wait(1,sec);
  msc(bl);
  msp(ml);
  wait(1,sec);
  msc(ml);
  msp(fl);
  wait(1,sec);
  msc(fl);
  msp(mr);
  wait(1,sec);
  msc(mr);
  msp(br);
  wait(1,sec);
  msc(br);
}