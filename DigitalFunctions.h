/*
  DigitalFunctions.h - Library for digital functions on bools.
  Created and started by Wim Cranen, December 12, 2018.
  Released into the public domain.
*/

#ifndef DigitalFunctions_h
#define DigitalFunctions_h

#include "Arduino.h"

// Library interface description
class DigitalFunctions {
	// user-accessible "public" inteface
	public:
		// DigitalFunctions with inputs:
		//		- sw is input condition
		//		- dt is debounce time in ms
		//		- set is set condition
		//		- reset is reset condition
		DigitalFunctions(bool ic, int dt, bool set, bool reset);
		bool IsOn(void);
		bool IsOff(void);
		bool SR(void);
		bool RS(void);
		bool RisingPuls(void);
		bool FallingPuls(void);
		bool Toggle(void);

  // library-accassible "private" interface
  private:
    // Inputs of the DigitalFunctions class
	bool _ic;				// input condition
	int	 _dt;				// debounce time
	bool _set;				// set condition
	bool _reset;			// reset condition
	
	// IsOn private variables
	bool OnActStatus;		// actual input condition
	bool OnPrevStatus;		// previous input condition
	bool OnOut;				// return value
	
	// IsOff private variables
	bool OffActStatus;		// actual input condition
	bool OffPrevStatus;		// previous input condition
	bool OffOut;			// return value
	
	// SR private variables
	bool SRout;				// return value
	
	// RS private variables
	bool RSout;				// return value
    
	// RisingPuls private variables
	bool REremember;		// remember rising edge
	bool REout;				// return value
	
	// FallingPuls private variables
	bool FEremember;		// remember falling edge
	bool FEout;				// return value
	
	// Toggle private variables
	bool tActStatus;		// actual input condition
	bool tPrevStatus;		// previous input condition
	bool tOut;				// toggle status
	
	//void  DoSomeThingSecret(void);
};

#endif
