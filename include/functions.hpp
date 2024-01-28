#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

extern int auton;
extern bool flapping;
extern int b;
extern bool punch;

void autonslctr();
void msc(motor m);
void msp(motor m, bool dir = 1, double speed = 100);
void spread();
void fold();
void wingaction();
void flap();
void intaking();
void setstop(int mode = 0);
void setv(double vel);
void frwd(double dist, double adjust = 4);
void rvrs(double dist, double adjust = 4);
void lft(double ang, double adjust =  0.1);
void rgt(double ang, double adjust = 0.1);
void batmobile();
void arcade();
void tank();
void punching();
void pullback();
void printing(std::string text);

#endif // FUNCTIONS_HPP