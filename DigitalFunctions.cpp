/*
  DigitalFunctions.cpp - Library for digital functions on bools.
  Created and started by Wim Cranen, December 13, 2018.
  Version 1.0 initial release.
*/

// for basic declarations and functions
#include <Arduino.h>
#include "DigitalFunctions.h"

// Constructor
// Function that handles the creation and setup of instances
DigitalFunctions::DigitalFunctions(bool ic, int dt, bool set, bool reset){
	// Do whatever is required to initialize the library
	_ic = ic;		// input condition
	_dt = dt;		// debounce time
	_set = set;		// set condition
	_reset = reset;	// reset condition
}

// Public methods
////////////////////////////////////////////////////////////////////
// Functions available in wiring sketches, this library, and other libraries
/*------------------------------------------------------------------------------------------------+
| Function    : IsOn                                                                              |
| Returnvalue : bool is HIGH if input condition is HIGH, else LOW                                 |
| Description : Check if condition is ON and implement a debounce time                            |
| Version     : v1.0 - Wim Cranen - Initial release                                               |
| History     : v1.0 - 13 dec 2018                                                                |
+------------------------------------------------------------------------------------------------*/
bool DigitalFunctions::IsOn(void) {
	// read actual input condition
	OnActStatus = _ic;
	// input conditions changed?
	if (OnActStatus != OnPrevStatus) {
		// input condition has changed
		if (OnActStatus == HIGH) { OnOut = HIGH; }
		else { OnOut = LOW; }
		// debounce
		delay(_dt);
	}
	// save the current status als last status for next loop
	OnPrevStatus = OnActStatus;
	// return output
	return OnOut;
}

/*------------------------------------------------------------------------------------------------+
| Function    : IsOff                                                                             |
| Returnvalue : bool is HIGH if input condition is LOW, else LOW                                  |
| Description : Check if condition is OFF and implement a debounce time                           |
| Version     : v1.0 - Wim Cranen - Initial release                                               |
| History     : v1.0 - 13 dec 2018                                                                |
+------------------------------------------------------------------------------------------------*/
bool DigitalFunctions::IsOff(void) {
	// read actual input condition
	OffActStatus = _ic;
	// input conditions changed?
	if (OffActStatus != OffPrevStatus) {
		// input condition has changed
		if (OnActStatus == LOW) { OffOut = HIGH; }
		else { OffOut = LOW; }
		// debounce
		delay(_dt);
	}
	// save the current status als last status for next loop
	OffPrevStatus = OffActStatus;
	// return output
	return OffOut;
}

/*------------------------------------------------------------------------------------------------+
| Function    : SR                                                                                |
| Returnvalue : bool is HIGH if SET condition was HIGH, LOW if RESET condition was HIGH           |
| Description : SR flipflop where SET has priority                                                |
| Version     : v1.0 - Wim Cranen - Initial release                                               |
| History     : v1.0 - 13 dec 2018                                                                |
+------------------------------------------------------------------------------------------------*/
bool DigitalFunctions::SR(void) {
	if (_reset) { SRout = LOW; }
	if (_set) { SRout = HIGH; }
	// return output
	return SRout;
}

/*------------------------------------------------------------------------------------------------+
| Function    : RS                                                                                |
| Returnvalue : bool is HIGH if SET condition was HIGH, LOW if RESET condition was HIGH           |
| Description : SR flipflop where RESET has priority                                              |
| Version     : v1.0 - Wim Cranen - Initial release                                               |
| History     : v1.0 - 13 dec 2018                                                                |
+------------------------------------------------------------------------------------------------*/
bool DigitalFunctions::RS(void) {
	if (_set) { RSout = HIGH; }
	if (_reset) { RSout = LOW; }
	// return output
	return RSout;
}

/*------------------------------------------------------------------------------------------------+
| Function    : RisingPuls                                                                        |
| Returnvalue : bool is HIGH for one cycle if there was a change from LOW to HIGH on the input    |
| Description : if the input changes from LOW to HIGH, an impuls will be given on the output      |
| Version     : v1.0 - Wim Cranen - Initial release                                               |
| History     : v1.0 - 13 dec 2018                                                                |
+------------------------------------------------------------------------------------------------*/
bool DigitalFunctions::RisingPuls(void) {
	if (_ic && !REremember) { REout = HIGH; }
	REremember = _ic;
	// debounce
	delay(_dt);
	// return output
	return REout;
}

/*------------------------------------------------------------------------------------------------+
| Function    : FallingPuls                                                                       |
| Returnvalue : bool is HIGH for one cycle if there was a change from HIGH to LOW on the input                  |
| Description : if the input changes from HIGH to LOW, an impuls will be given on the output      |
| Version     : v1.0 - Wim Cranen - Initial release                                               |
| History     : v1.0 - 13 dec 2018                                                                |
+------------------------------------------------------------------------------------------------*/
bool DigitalFunctions::FallingPuls(void) {
	if (!_ic && !FEremember) { FEout = HIGH; }
	FEremember = !_ic;
	// debounce
	delay(_dt);
	// return output
	return FEout;
}

/*------------------------------------------------------------------------------------------------+
| Function    : Toggle                                                                            |
| Returnvalue : bool is switched from LOW to HIGH or v.v. on input condition change               |
| Description : Toggle output every time theinput state changes from LOW to HIGH                  |
| Version     : v1.0 - Wim Cranen - Initial release                                               |
| History     : v1.0 - 13 dec 2018                                                                |
+------------------------------------------------------------------------------------------------*/
bool DigitalFunctions::Toggle(void) {
	// read actual input condition
	tActStatus = _ic;
	// input conditions changed?
	if (tActStatus != tPrevStatus) {
		if (tActStatus == HIGH) { tOut = !tOut; }
		// debounce
		delay(_dt);
	}
	// save the current status als last status for next loop
	tPrevStatus = tActStatus;
	// return output
	return tOut;
}
