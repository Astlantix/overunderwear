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
void Fwd(double dist);
void Rev(double dist);
void lft(double ang, double adjust =  0.1);
void rgt(double ang, double adjust = 0.1);
void batmobile();
void arcade();
void tank();
void punching();
void pullback();
void printing(std::string text);
double temp(motor m);
void pid(double target);
void tipping();

#endif // FUNCTIONS_HPP