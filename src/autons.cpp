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
  pid(430);
  rgt(60);
  wait(200,msec);
  msp(intake,1,40);
  wait(200,msec);
  wait(300,msec);
  lft(150);
  msp(intake,0,100);
  pid(225);
  wait(100,msec);
  rgt(160);
  msp(intake,1,100);
  lft(50);
  msp(intake,0,100);
  pid(185);
  wait(100,msec);
  rgt(55);
  msp(intake,1,100);
  wait(100,msec);
  lft(170);
  spread();
  pid(-250);
  msp(intake,0,100);
  pid(100);
  L.spin(rev,100,pct);
  R.spin(rev,100,pct);
  wait(1,sec);
  L.stop();
  R.stop();
  pid(100);
  fold();
  msc(intake);
}

// Left Side AWP
void auton2() {
  setv(50);
  wing.open();
  wait(300,msec);
  lft(45);
  wait(40,msec);
  wing.close();
  wait(750,msec);
  rgt(135);
  setv(40);
  msp(intake,1);
  Fwd(27);
  wait(1,sec);
  msc(intake);
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
  /*timer t;
  t.clear();
  msp(cata);
  waitUntil(t.time(sec) >= 30);
  msc(cata);
  setv(50);
  lft(13);
  Rev(63);
  setv(40);
  L.stop();
  R.stop();
  rgt(120);
  Rev(34);
  wait(100,msec);
  lft(40);
  Rev(13);
  spread();
  lft(90);
  L.spin(rev,50,pct);
  R.spin(rev,50,pct);
  wait(2,sec);
  L.stop();
  R.stop();
  fold();
  Fwd(10);
  spread();
  L.spin(rev,50,pct);
  R.spin(rev,50,pct);
  wait(2,sec);
  L.stop();
  R.stop();
  fold();
  Fwd(10);
  rgt(90);
  Rev(10);
  spread();
  lft(90);
  L.spin(rev,50,pct);
  R.spin(rev,50,pct);
  wait(2,sec);
  L.stop();
  R.stop();Rev(15);
  fold();
  Fwd(10);
  spread();
  L.spin(rev,50,pct);
  R.spin(rev,50,pct);
  wait(2,sec);
  L.stop();
  R.stop();
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
  Fwd(10);*/
  timer t;
  t.clear();
  msp(cata);
  waitUntil(t.time(sec) >= 30);
  msc(cata);
  setv(50);
  lft(13);
  Rev(63);
  rgt(40);
  wing.open();
  L.spin(rev,75,pct);
  R.spin(rev,75,pct);
  wait(1.5,sec);
  L.stop();
  R.stop();
  wing.close();
  Fwd(10);
  lft(90);
  Fwd(25);
  rgt(30);
  spread();
  L.spin(rev);
  R.spin(rev);
  wait(1.5,sec);
  L.stop();
  R.stop();
  fold();
  Fwd(5);
  lft(20);
  Fwd(20);
  rgt(20);
  spread();
  L.spin(rev);
  R.spin(rev);
  wait(1.5,sec);
  L.stop();
  R.stop();
  fold();
  Fwd(20);
  lft(20);
  rgt(30);
  spread();
  L.spin(rev);
  R.spin(rev);
  wait(1.5,sec);
  L.stop();
  R.stop();
  fold();
  Fwd(20);
  lft(20);
  spread();
  L.spin(rev);
  R.spin(rev);
  wait(1.5,sec);
  L.stop();
  R.stop();
  fold();
  Fwd(5);
}

// drivetrain test
void auton5 () {
  setstop();
  setv(100);
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