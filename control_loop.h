#include <iostream>
#include "boost/thread.hpp"

using namespace std;

class CONTROLLER {
    public:
        CONTROLLER(double kp_, double kd_, double ki_);
        
        void loop();                //Main loop function        
        void system_start();       //start the system
        void set_xdes(double x);   //member to set the desired value

    private:
      double _xdes; 
        double _x; 

        double _s; 
        
        double _kp; // Proportional gain
        double _kd; // Derivative gain
        double _ki; // Intefral gain

        bool _initvalue;
};
