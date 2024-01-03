#ifndef PID_H
#define PID_H

class PIDImpl;
class PID
{
/**
 *  Kp -  proportional gain
 *  Ki -  Integral gain
 *  Kd -  derivative gain
 *  dt -  loop interval time
 *  max - maximum value of manipulated variable
 *  min - minimum value of manipulated variable
*/
public:
    PID( double dt, double max, double min , double kp , double ki , double kd );
    ~PID();
    double pid_calculate(double setpoint , double pv);

private:
    PIDImpl *pidimpl;
};


#endif  /*PID_H*/