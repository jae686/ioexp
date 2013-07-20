// Teste I2C - IO Expander pcf8574P
// by Jaerder Sousa
// Example code for the IOexp libary

// Analog In 5 - SCL
// Analog In 4 - SDA
// Endere\u00e7o I2C 0 0 0 A2 A1 A0

/**
The IOexp libary is a simple libary that it makes easier to work with the pcf8574
or another IO expander with a similar read / write method.

Usage:
  Include the IOexp.h and Wire.h to your sketch
  
  Declare a IOexp instance before the setup() function.
    example : IOexp myIOexpander(address);
    note : The address must be 7 bit.For a pfc8574P with A2 A1 and A0 set to 0 you could define it as (0x4 << 3 | 0x0)
    
    note : dont forget to add the Wire.begin(); to your setup function!!
    note 2 : when a function requests a pin, you should use the datasheet definition (P0 though P7) !
    
    After the above steps, you will have several fuctions avaliable to set and read the IO's of your IO expander.
    these are ( for simplicity sake in this examples i use myIOexpander, but this should be replaced by the 
    instance name you used then you declared your IOexp instance...)
    
    bool read(int pin); - it returns false if the the IO is HIGH of false if LOW. 
      example : to read the P0 IO (check the datasheet!) you should type myIOexpander.read(P0); 
                to read the P5 IO you use myIOexpander.read(P5);
      
    void write(int pin, bool status); - it sets the given pin to HIGH is status == true or to LOW if status == false
      example : to set P0 to HIGH you would use myIOexpander.write(P0, true);
   
    void toggle(int pin); - if the pin is HIGH, the funciont set's the pin as LOW. 
                            If the pin is LOW, it set's the pin as HIGH.
     
                       
    int fullread(); - it return a byte read from the IC.
      example : some_int = myIOexpander.fullread();
     
    void fullwrite(int to_write); - it writes to the IO expander the byte specified.
      example : myIOexpander(0x0); - it sets all IO's to LOW
**/


#include <IOexp.h>
#include <Wire.h>
#define IO_ADDR (0x4 << 3 | 0x0)

#include "WProgram.h"
void setup();
void loop();
IOexp myIOexpander(IO_ADDR);

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
  
}

/**

On this example, P5 and P6 have a LED each, and P2 and P3 have a push button each.
**/


void loop()
{
  int data;
  bool bool1, bool2; // the bool vars bool1 and bool2 are to store the status of the Inputs we wish to read.
  Serial.print("teste ! ");
  myIOexpander.write( P5, true);
  myIOexpander.write( P6, false);
  delay(200);
  delay(200);
  data = myIOexpander.fullread();
  Serial.print(data, BIN);
  Serial.print(" -- ");
  myIOexpander.toggle(P5);
  myIOexpander.toggle(P6);
  delay(200);
   
  bool1 = myIOexpander.read(P2);
  bool2 = myIOexpander.read(P1);
  Serial.print(bool1);
  Serial.print(" ");
  Serial.print(bool2);
  Serial.print(" \n ");
  delay(500);
}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

