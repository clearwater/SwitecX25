Switec X25 library
==================

This is an Arduino library for driving Switec X25 miniature 
stepper motors. It was written specifically for the Switec X25.168,
and compatible steppers from other manufacturers including the 
VID29 and MCR1108.

For more information including [datasheets](http://clearwater.github.com/gaugette/resources) see the [Gaugette blog](http://clearwater.github.com/gaugette/).

Usage Notes
-----------
This library assumes you are driving the X25 directly from
the Arduino IO lines, not through an intermediate controller circuit.
A motor can be connected to any 4 Arduino digital output lines.
The Arduino Uno has 14 I/O lines, limiting you to three motors.
The Mega boards have more.

The rate at which these miniature stepper motors 
can accelerate is dependent upon the inertia
of the needle you are using.  You may need to tune the acceleration
tables in the library for your needle.


Using the Library
-----------------

```C++
#import "SwitecX25.h"

// 315 degrees of range = 315x3 steps = 945 steps
// declare motor1 with 945 steps on pins 4-7
SwitecX25 motor2(315*3, 4,5,6,7);

// declare motor2 with 945 steps on pins 8-11
SwitecX25 motor1(315*3, 8,9,10,11);

void setup(void) {
  Serial.begin(9600);
  Serial.println("Go!");

  // run both motors against stops to re-zero
  motor1.zero();   // this is a slow, blocking operation
  motor2.zero();  
  motor1.setPosition(427);
  motor2.setPosition(427);
}

void loop(void) {
  // update motors frequently to allow them to step
  motor1.update();
  motor2.update();

  // do stuff...
}

```












