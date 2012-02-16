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

