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
  setv(36);
  frwd(26.84);
  rgt(90);
  msp(intake,1,90);
  wait(250,msec);
  rvrs(5);
  rgt(137);
  msp(intake);
  frwd(6.25);
  wait(200,msec);
  rgt(165);
  msp(intake,1);
  wait(600,msec);
  lft(30);
  msp(intake);
  frwd(1.5);
  setv(25);
  R.spinFor(fwd,360,deg);
  wingactionopen();
  wait(250,msec);
  setv(100);
  msc(intake);
  rvrs(17);
  frwd(5);
  wingactionclose();
  rgt(180);
  msp(intake,1,90);
  frwd(5);
  wait(100,msec);
  rvrs(5);
  wait(100,msec);
  frwd(5);
  wait(100,msec);
  rvrs(5);
  lft(55);
  msc(intake);
  rvrs(27);
  bat.open();
  lft(40);
  /*msp(intake,1);
  wait(200,msec);
  lft(135);
  msp(intake);
  frwd(20);
  wait(350,msec);
  rvrs(25);
  rgt(135);
  msp(intake,1);
  wait(100,msec);
  frwd(12);
  wings.open();
  lft(90);
  wings.close();
  rgt(45);
  msc(intake);
  wait(100,msec);
  frwd(8.2);
  wait(100,msec);
  rvrs(8.2);
  lft(73);
  msp(intake);
  frwd(29);
  wait(100,msec);
  rgt(85);
  msp(intake,1);
  wait(100,msec);
  msp(intake);
  lft(40);
  frwd(10);
  wait(100,msec);
  msc(intake);
  lft(90);
  wingactiona();
  rvrs(17);
  frwd(5);
  wingactionb();
  rgt(180);
  msp(intake,1,90);
  frwd(5);*/
}

// Left Side AWP
void auton2() {
  bat.open();
  wait(300,msec);
  lft(45);
  wait(40,msec);
  bat.close();
  rgt(20); 
  msp(intake,1,90);
  setv(100);
  frwd(12);
  wait(750,msec);
  rvrs(1);
  lft(90);
  msc(intake);
  setv(40);
  rvrs(35);
  bat.open();
  lft(25);
}

// Left Side Elims
void auton3() {
  rvrs(7.5);
  wait(10,msec);
  frwd(7.5);
  wait(10,msec);
  lft(30);
  msp(intake,1);
  frwd(20);
  wait(20,msec);
  rvrs(17);
}

// skills
void auton4() {
  timer t;
  t.clear();
  punching();
  waitUntil(t.time() >= 40);
  pullback();
  rgt(25);
  rvrs(20);
  lft(90);
  rvrs(10);
  wait(100,msec);
  frwd(5);
  rgt(90);
  frwd(100);
  rgt(90);
  frwd(7.5);
  lft(90);
  wingactionopen();
  rvrs(7.5);
  wait(100,msec);
  frwd(7.5);
  lft(90);
  frwd(10);
  rgt(90);
  setv(40);
  frwd(5);
}

// drivetrain test
void auton5 () {
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