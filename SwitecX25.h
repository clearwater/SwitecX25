/*
 *  SwitecX25 Arduino Library
 *  Guy Carpenter, Clearwater Software - 2012
 *
 *  Licensed under the BSD2 license, see license.txt for details.
 *
 *  All text above must be included in any redistribution.
 */

#ifndef SwitecX25_h
#define SwitecX25_h
#include <Arduino.h>

class SwitecX25
{
 public:
   static const unsigned char pinCount = 4;
   static const unsigned char stateCount = 6;
   unsigned char pins[pinCount];
   unsigned char currentState;    // 6 steps 
   unsigned int currentStep;      // step we are currently at
   unsigned int targetStep;       // target we are moving to
   unsigned int steps;            // total steps available
   unsigned long time0;           // time when we entered this state
   unsigned int microDelay;       // microsecs until next state
   unsigned short (*accelTable)[2]; // accel table can be modified.
   unsigned int maxVel;           // fastest vel allowed
   unsigned int vel;              // steps travelled under acceleration
   signed char dir;                      // direction -1,0,1  
   boolean stopped;               // true if stopped
   
   SwitecX25(unsigned int steps, unsigned char pin1, unsigned char pin2, unsigned char pin3, unsigned char pin4);
  
   void stepUp();
   void stepDown();
   void zero();
   void update();
   void updateBlocking();
   void setPosition(unsigned int pos);
  
 private:
   void advance();
   void writeIO();
};


#endif

