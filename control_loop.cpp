#include "control_loop.h"
#include <iostream>
#include <fstream>

//We can use the class constructor to set parameters
CONTROLLER::CONTROLLER(double kp_, double kd_, double ki_) {
    _kp = kp_;
    _ki = ki_;
    _kd = kd_;

    _s = 0.001;
    
    _initvalue = false;

    CONTROLLER::system_start();
    
    boost::thread loop_t( &CONTROLLER::loop, this );  

}


//Sense: get input to change the state of our System
void CONTROLLER::set_xdes(double x) {
    _xdes = x;

    _initvalue = true;
 
}


//Random initial value
void CONTROLLER::system_start() {
    srand((unsigned)(time(NULL)));
    _x = rand() % 100 +1;
}

void CONTROLLER::loop() {
    ofstream myfile;

    do {
        usleep(0.1*1e6);
    }
    while( !_initvalue );


    myfile.open ("results.txt");
    myfile << "reference= " << _xdes << "\n";
    myfile.close();
    
    _xdes == _x; 


    double e = 0.0;
    double ep = 0.0;
    double de = 0.0;
    double ie = 0.0;

    double pid = 0.0;
    double output = 0.0;
    double dt = 1.0/100.0;

    do{
        //errors
        e = _xdes - _x;
        de = (e - ep) / dt;
        ie += e*dt;

        pid = _kp*e+ _kd*de + _ki*ie;

        output = pid;

        cout << "Error= " << e << "\nOutput= " << output << endl;
        myfile.open ("results.txt", ios::app);
        myfile << "Error= " << e << "\nOutput= " << output << endl;
        myfile.close();

        if(abs(e)<_s) break;
        usleep(10000); 

        _x = output;     
    }

    while( true ); 

}


