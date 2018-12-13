# DigitalFunctions

Arduino - Library for digital functions on bools.

Created and started by Wim Cranen, December 13, 2018.

Version 1.0 initial release.

#### Functions:
- bool IsOn()
- bool IsOff()
- bool SR()
- bool RS()
- bool RisingPuls()
- bool FallingPuls()
- bool Toggle()

#### Input variables:
- bool input (bool for input)
- int debounceTime (debounce time in ms)
- bool setCondition (set condition for output)
- bool resetCondition (reset condition for output)

#### Definition example:
DigitalFunctions Switch01(input, debounceTime, setCondition, resCondition);

#### Usage example:
- bool = Switch01.IsOn();
- bool = Switch01.IsOff();
- bool = Switch01.SR();
- bool = Switch01.RS();
- bool = Switch01.RisingPuls();
- bool = Switch01.FallingPuls();
- bool = Switch01.Toggle();

## Function descriptions:
### IsOn()
Check if condition is ON and implement a debounce time

Returns HIGH if input condition is HIGH, else LOW
### IsOff()
Check if condition is OFF and implement a debounce time

Returns HIGH if input condition is LOW, else LOW 
### SR()
SR flipflop where SET has priority

Returns HIGH if SET condition was HIGH, LOW if RESET condition was HIGH
### RS()
SR flipflop where RESET has priority

Returns HIGH if SET condition was HIGH, LOW if RESET condition was HIGH
### RisingPuls()
If the input changes from LOW to HIGH, an impuls will be given on the output

Returns HIGH for one cycle if there was a change from LOW to HIGH on the input
### FallingPuls()
If the input changes from HIGH to LOW, an impuls will be given on the output

Returns HIGH for one cycle if there was a change from HIGH to LOW on the input
### Toggle()
Toggle output every time theinput state changes from LOW to HIGH

Returns a switched status from LOW to HIGH on the output every time the input changes from LOW to HIGH
