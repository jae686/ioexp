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

#include <Wire.h>
#include "IOexp.h"



IOexp::IOexp(int address) 
{
	__address = address;
	__IN_status = 0x0 ; // initialize as 0x0
	__OUT_status = 0x0 ; // Its allways a good practice to initialize this....
	debug = 5 ;
}


void IOexp::init()
{
	Wire.begin(); // just for convenience's sake
}

int IOexp::fullread() // reads a byte, with the status of the inputs.
{
  int data;
  Wire.beginTransmission(__address);
  Wire.requestFrom(__address, 1);
  
  if(Wire.available() )
  {
    data = Wire.read();
  }

  else
  {
    data = 0x00;
  }
    
    Wire.endTransmission();
    __IN_status = data;
    return data;
}

void IOexp::fullwrite(int to_write)
{
  Wire.beginTransmission(__address);
  Wire.write(to_write);
  debug = Wire.endTransmission();
  __OUT_status = to_write;
}

bool IOexp::read(int IO_pin)
{
 IOexp::fullread(); // this is required to update the class __IN_Status var!!!!

 int check_var = 0x0;
 check_var = IO_pin & __IN_status; // this byte wise operation will return IO_pin if it matches the current IO status
 if(check_var != 0x0)
	{ 
	 return true;
	}
 else
	{
	 return false;
	}

}

bool IOexp::read_OUT(int IO_pin) // necessary since i cant "read" the outputs from IOexp::read() just swaped __IN_status with __OUT_status
{
 int check_var = 0x0;
 check_var = IO_pin & __OUT_status; // this byte wise operation will return IO_pin if it matches the current IO status
 if(check_var != 0x0)
	{ 
	 return true;
	}
 else
	{
	 return false;
	}

}

void IOexp::write(int IO_pin, bool SET_to)
{
  int result;
  if(SET_to == true)
	{
	 result = __OUT_status | IO_pin ; // its enough to set a given bit to 1.
	}
  else
	{
	 result = __OUT_status & ~IO_pin ; // sets th IO_pin we want to 0, and leave the rest untouched.... 	
	}
  
  IOexp::fullwrite(result); // fullwrite updates the  __OUT_status variable and sets the IO IC
}

void IOexp::toggle(int IO_pin)
{
  
  if( IOexp::read_OUT(IO_pin)  == true )
	{
	 IOexp::write(IO_pin, false);
	}
  else
	{
	 IOexp::write(IO_pin, true);
	}
 
 // the IOexp::write already updates the __IO_status
}



