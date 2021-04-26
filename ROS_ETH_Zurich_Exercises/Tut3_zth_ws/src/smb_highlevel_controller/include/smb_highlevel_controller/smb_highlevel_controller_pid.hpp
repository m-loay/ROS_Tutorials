#include "math.hpp"

namespace smb_highlevel_controller
{

    /*!
    * Main class for the node to handle the ROS interfacing.
    */
    class SmbHighLevelControllerPID
    {
        private:
        /*data*/
        //! proportional gain.
        float Kp_;

        //! Inegeral gain.
        float Ki_;

        //! Derivative gain.
        float Kd_;

        //! Maximum Allowed Output.
        float maxOutput_;

        //! Minimum Allowed output.
        float minOutput_;

        //! Controller output.
        float output_;

        //! Error(difference between set value & actual output).
        float error_;

        //! The Controller integeral part.
        float integeral_;

        //! The Controller derivative part.
        float derivative_;

        /*!
        * limitControllerOutput Limit the controller output according to limits.
        * @param msg range distances of all laser scanner.
        * @return void.
        */
        float limitControllerOutput(const float &valOutput);

        public:
        /*!
        * Constructor.
        */
        SmbHighLevelControllerPID();

        /*!
        * Constructor.
        * @param kp  proportional gain.
        * @param ki  Inegeral gain.
        * @param kd  Derivative gain.
        * @param max Maximum Allowed Output.
        * @param min Minimum Allowed output.
        */
        SmbHighLevelControllerPID(const float &kp, const float &ki, const float &kd, const float &max, const float &min);

        /*!
        * controllerInit.
        * @param kp  proportional gain.
        * @param ki  Inegeral gain.
        * @param kd  Derivative gain.
        * @param max Maximum Allowed Output.
        * @param min Minimum Allowed output.
        */
        void controllerInit(const float &kp, const float &ki, const float &kd, const float &max, const float &min);


        /*!
        * limitControllerOutput Limit the controller output according to limits.
        * @param msg range distances of all laser scanner.
        * @return void.
        */
        float controllerUpdate(const float &setPoint, const float &feedBack, const float &dt);
        /*!
        * Destructor.
        */
        ~SmbHighLevelControllerPID() = default;
    };
}
