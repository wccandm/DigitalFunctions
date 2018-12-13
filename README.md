# DigitalFunctions

Arduino - Library for digital functions on bools.

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
