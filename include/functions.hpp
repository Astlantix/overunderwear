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
void lwing();
void rwing();
void lwings();
void rwings();
void flap();
void intaking();
void setstop(int mode = 0);
void setv(double vel);
void Fwd(double dist);
void Rev(double dist);
void lft(double ang, double adjust =  0.1);
void rgt(double ang, double adjust = 0.1);
void Right(double ang, double adjust = 0.1);
void Left(double ang, double adjust = 0.1);
void arcade();
void splitarcade();
void tank();
void punching();
void pullback();
void printing(std::string text);
double temp(motor m);
int pid(double target);
int ppid(double target);

#endif // FUNCTIONS_HPP