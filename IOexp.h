/**

I2C IO expander libary for the pfc8574
Jaerder "Jae686" Sousa 21.06.2012
e-mail : jaerder@videmogroup.org
website : http://jaerder.videmogroup.org

version 0.9 - 2nd release


**/


#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
  #else
  #include "WProgram.h"
  #endif
//#include "WProgram.h"

#ifndef IOexp_h
#define IOexp_h

// Definition of the byte that corresponds to a given IO on the IC.
#define P0 0x1
#define P1 0x2
#define P2 0x4
#define P3 0x8
#define P4 0x10
#define P5 0x20
#define P6 0x40
#define P7 0x80

class IOexp
{
	public:
	 IOexp(int address); // It creates a instance for the IO expander with its 7 bit adress
	 void init(); // inits the wire interface...... this will probably be removed...
	 int fullread(); // returns a byte read from the IO expander.
	 void fullwrite(int to_write); // writes the specified byte to the IO expander.
	 bool read(int IO_pin); // returns a BOOL, TRUE if 1, FALSE if 0
	 bool read_OUT(int IO_pin); // needed for the toogle function
	 void toggle(int IO_pin); // toggle an IO to ON or OFF, 
	 void write(int IO_pin, bool status); // sets a IO to 1 (TRUE) or 0 (FALSE)
	 byte debug; // debug variable

	private:
	 int __address; //  I2C IO expander address
	 int __OUT_status; // byte with the current output status 
	 int __IN_status; // byte with the input status.

};

#endif
	 
