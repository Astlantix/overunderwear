#include "vex.h"
#include "autons.hpp"
#include "functions.hpp"
using namespace vex;
using namespace std;

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
  timer t;
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
  R.spinFor(fwd,360,deg);
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
  cout << t.time() << endl;
  lft(75);
  /*msp(intake,1);
  wait(200,msec);
  lft(135);
  msp(intake);
  Fwd(20);
  wait(350,msec);
  Rev(25);
  rgt(135);
  msp(intake,1);
  wait(100,msec);
  Fwd(12);
  wings.open();
  lft(90);
  wings.close();
  rgt(45);
  msc(intake);
  wait(100,msec);
  Fwd(8.2);
  wait(100,msec);
  Rev(8.2);
  lft(73);
  msp(intake);
  Fwd(29);
  wait(100,msec);
  rgt(85);
  msp(intake,1);
  wait(100,msec);
  msp(intake);
  lft(40);
  Fwd(10);
  wait(100,msec);
  msc(intake);
  lft(90);
  wingactiona();
  Rev(17);
  Fwd(5);
  wingactionb();
  rgt(180);
  msp(intake,1,90);
  Fwd(5);*/
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
  msp(intake,1,90);
  Fwd(15);
}

// skills
void auton4() {
  timer t;
  t.clear();
  msp(cata);
  waitUntil(t.time(sec) >= 40);
  msc(cata);
  setv(90);
  lft(13);
  Rev(58);
  L.stop();
  R.stop();
  rgt(120);
  Rev(25);
  wait(100,msec);
  lft(30);
  Rev(15);
  spread();
  lft(90);
  Rev(15);
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