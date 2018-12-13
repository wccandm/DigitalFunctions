// include library
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

// define IO
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin    = 13; // the number of the LED pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // initialize serial monitor
  Serial.begin(9600);
  Serial.println("--- Start Serial Monitor SEND_RCVE ---");
}

void loop() {
  while (true){
    // read the state of the button
    bi 	 = digitalRead(buttonPin);
	
	// output bool-on and bool-off
	bon  = Switch01.IsOn();
	boff = Switch01.IsOff();
	Serial.print("Value for Switch01.IsOn() is............: ");
	Serial.println(bon);
	Serial.print("Value for Switch01.IsOff() is...........: ");
	Serial.println(boff);
  
	// output sr-flipflop rs-flipflop
	setC = bi && tog;
	resC = !v=bi && !tog;
	sr1 = Switch01.SR();
	sr2 = Switch01.RS();
	Serial.print("Value for Switch01.SR() is..............: ");
	Serial.println(sr1);
	Serial.print("Value for Switch01.RS() is..............: ");
	Serial.println(sr2);
  
	// output puls on rising and falling edge
	br  = Switch01.RisingPuls();
	bf  = Switch01.FallingPuls();
	Serial.print("Value for Switch01.RisingPuls() is......: ");
	Serial.println(br);
	Serial.print("Value for Switch01.FallingPuls() is.....: ");
	Serial.println(bf);
  
	// output to toggle
	tog = Switch01.Toggle();
	Serial.print("Value for Switch01.Toggle() is..........: ");
	Serial.println(tog);
	digitalWrite(ledPin, tog);
	
	// delay the program for 1 second to see the serial monitor
	delay(1000);
  }
}
