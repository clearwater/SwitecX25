//----------------------------------------------------------------------
// https://github.com/clearwater/SwitecX25
// 
// This is a minimal example of SwitchX25 library.
// It zero's the motor, sets the position to mid-range
// and calls update repeatedly to move to motor
// to the center position.
// 
// You should add calls to motor1.setPosition() to change
// the motor position, but be sure to leave update() in
// place.
// 
// Note that the maximum speed of the motor will be determined
// by how frequently you call update().  If you put a big slow
// serial.println() call in the loop below, the motor will move
// very slowly!
//----------------------------------------------------------------------

#include <SwitecX25.h>

// standard X25.168 range 315 degrees at 1/3 degree steps
#define STEPS (315*3)

// For motors connected to pins 3,4,5,6
SwitecX25 motor1(STEPS,3,4,5,6);

void setup(void)
{
  // run the motor against the stops
  motor1.zero();
  // start moving towards the center of the range
  motor1.setPosition(STEPS/2);
}

void loop(void)
{
  // the motor only moves when you call update
  motor1.update();
}

