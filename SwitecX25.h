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
   typedef struct {
	 unsigned short steps;
	 unsigned short time;    // in microseconds
   } AccelTable;

   static const unsigned char pinCount = 4;
   static const unsigned char stateCount = 6;
   unsigned char pins[pinCount];
   unsigned char currentState;    // 6 steps 
   unsigned int currentStep;      // step we are currently at
   unsigned int targetStep;       // target we are moving to
   unsigned int steps;            // total steps available
   unsigned long time0;           // time when we entered this state
   unsigned int microDelay;       // microsecs until next state
   AccelTable *accelTable;        // accel table can be modified.
   unsigned char accelTableSize;  // How many rows in the acceleration table
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
   template<typename T, size_t N> void setAccelTable(T (&table)[N]) {
	 accelTable = table;
	 accelTableSize = N;
	 maxVel = accelTable[accelTableSize - 1].steps;
   };
   short getAccel(int vel);
  
 private:
   void advance();
   void writeIO();
};


#endif

