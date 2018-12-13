// invlude library
#include <DigitalFunctions.h>

// create test bools
bool bon;         // output is on
bool boff;        // output is off
bool br;          // output rising puls
bool bf;          // output falling puls
bool sr1;         // output set/reset
bool sr2;         // output reset/set
bool tog;         // output toggle
bool bi;          // input bool
bool setC;        // input set condition
bool resC;        // input reset condition
int  debT = 50;   // input debounce time

// define switch
DigitalFunctions Switch01(bi, debT, setC, resC);

void setup() {
}

void loop() {
  // output bool-on and bool-off
  bon   = Switch01.IsOn();
  boff  = Switch01.IsOff();
  
  // output sr-flipflop rs-flipflop
  sr1 = Switch01.SR();
  sr2 = Switch01.RS();
  
  // output puls on rising and falling edge
  br  = Switch01.RisingPuls();
  bf  = Switch01.FallingPuls();
  
  // output to toggle
  tog = Switch01.Toggle();
}
