#include "control_loop.h"

using namespace std;

//the goal is to implement a simple PID controller, 
//running on input value to reach the desired one

// Sense: read a value from keyboard
// Plan:  generate the correct input
// Act:   set the input

int main(int argc, char** argv) {
  CONTROLLER c(0.1, 0.03, 0.02);

    double y;
    do{
        cout << "Insert value ";
        cin >> y;
        c.set_xdes(y);

    }
    while( true ) ;



    return 0;
}
