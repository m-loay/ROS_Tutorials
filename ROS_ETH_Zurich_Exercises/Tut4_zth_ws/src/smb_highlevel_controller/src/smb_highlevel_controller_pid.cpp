#include"smb_highlevel_controller/smb_highlevel_controller_pid.hpp"

namespace smb_highlevel_controller
{
    SmbHighLevelControllerPID::SmbHighLevelControllerPID()
    :Kp_(0.0f),Ki_(0.0f),Kd_(0.0f),maxOutput_(0.0f),minOutput_(0.0f),output_(0.0f),
     error_(0.0f),integeral_(0.0f),derivative_(0.0f)
    {

    }

    SmbHighLevelControllerPID::SmbHighLevelControllerPID(const float &kp, const float &ki, const float &kd, const float &max, const float &min)
    :Kp_(kp),Ki_(ki),Kd_(kd),maxOutput_(max),minOutput_(min),output_(0.0f),
     error_(0.0f),integeral_(0.0f),derivative_(0)
    {

    }

    void SmbHighLevelControllerPID::controllerInit(const float &kp, const float &ki, const float &kd, const float &max, const float &min)
    {
        Kp_ = kp;
        Ki_ = ki;
        Kd_ = kd;
        maxOutput_ = max;
        minOutput_ = min;
    }

    float SmbHighLevelControllerPID::limitControllerOutput(const float &valOutput)
    {
        float result;
        if(valOutput > maxOutput_)
        {
            result = maxOutput_;
        }
        else if (valOutput < minOutput_)
        {
            result = minOutput_;
        }
        else
        {
            result = valOutput;
        }
        return result;
    }

    float SmbHighLevelControllerPID::controllerUpdate(const float &setPoint, const float &feedBack, const float &dt)
    {
        float lastError(error_);
        float lastIntegeral(integeral_);

        //error part
        error_ = setPoint - feedBack;

        //Integeral Part
        integeral_ = limitControllerOutput(lastIntegeral + (error_ * dt));

        //derivative part
        derivative_ = limitControllerOutput((error_ - lastError)/dt);

        //final part
        output_ = limitControllerOutput((Kp_ * error_) + (Ki_ * integeral_) + (Kd_ * derivative_));

        return output_;
    }

} //smb_highlevel_controller