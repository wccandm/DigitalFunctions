#include <DigitalFunctions.h>

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

DigitalFunctions Switch01(bi, debT, setC, resC);

void setup() {
}

void loop() {
  bon   = Switch01.IsOn();
  boff  = Switch01.IsOff();
  
  sr1 = Switch01.SR();
  sr2 = Switch01.RS();
  
  br  = Switch01.RisingPuls();
  bf  = Switch01.FallingPuls();
  
  tog = Switch01.Toggle();
}
