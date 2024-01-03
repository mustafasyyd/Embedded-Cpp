#include"pid.h"

/*----------------------------------------------------------*/
/**
 * @brief
 * @implements
 * @param
*/
class PIDImpl
{
public:
    PIDImpl( double dt, double max, double min , double kp , double ki , double kd );
    ~PIDImpl();
    double pid_calculate(double setpoint , double pv);

private:
    private:
    double m_dt;
    double m_max;
    double m_min;
    double m_kp;
    double m_ki;
    double m_kd;
    double m_pre_error;
    double m_integral;
};

/**
 * @brief
 * @implements
 * @param
*/
PID::PID( double dt, double max, double min , double kp , double ki , double kd )
{
    pidimpl->new PIDImpl(dt,max,min,kp,ki,kd);
}

/**
 * @brief
 * @implements
 * @param
*/
PID::~~PID()
{
    delete pidimpl;
}

/**
 * @brief
 * @implements
 * @param
*/
double PID::pid_calculate(double setpoint , double pv)
{ 
    return pidimpl->pid_calculate(setpoint,pv);
}

/*----------------------------------------------------------*/
/**
 * @brief
 * @implements
 * @param
*/
PIDImpl::PIDImpl( double dt, double max, double min , double kp , double ki , double kd )
    : m_dt        (dt) 
    , m_max       (max)
    , m_min       (min)
    , m_kp        (kp)
    , m_ki        (ki)
    , m_kd        (kd)
    , m_pre_error (0)
    , m_integral  (0)

/**
 * @brief
 * @implements
 * @param
*/
PIDImpl::~PIDImpl()
{

}

/**
 * @brief
 * @implements
 * @param
*/
double PIDImpl::pid_calculate(double setpoint , double pv)
{
    double error, P , I , derivative , D , Out; 
    
    error       =  setpoint -pv             ; 
    P           =  m_kp * error             ;

    m_integral += error*m_dt                ; 
    I           =  m_ki * m_integral        ;

    derivative  = (error-m_pre_error)/m_dt  ;   
    D           =  m_kd * derivative        ;

    Out         = P + I + D                 ;

    if (Out > m_max)        Out=m_max       ;
    else if (Out < m_min)   Out = m_min     ;
}
