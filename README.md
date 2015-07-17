# README #

This README would normally document whatever steps are necessary to get your application up and running.

### What is this repository for? ###

The IOexp libary is a simple libary that it makes easier to work with the pcf8574 IO expander.
Current Version : 0.9

* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### How do I get set up? ###

* Installation Procedure : It is installed in the same way as any regular library. 

Usage:
  
Include the IOexp.h and Wire.h to your sketch
  
Declare a IOexp instance before the setup() function.
example : IOexp myIOexpander(address);
note : The address must be 7 bit. For a pfc8574P with A2 A1 and A0 set to 0 you could define it as (0x4 << 3 | 0x0)
  
note : dont forget to add the Wire.begin(); to your setup function!!
note 2 : when a function requests a pin, you should use the datasheet definition (P0 though P7) !
    
After the above steps, you will have several functions avaliable to set and read the IO's of your IO expander.
these are ( for simplicity sake in this examples i use myIOexpander, but this should be replaced by the instance name you used then you declared your IOexp instance...)


```
#!c++
bool read(int pin); // it returns false if the the IO is HIGH of false if LOW. 

```
    
example : to read the P0 IO (check the datasheet!) you should type 


```
#!c++

myIOexpander.read(P0);

```

to read the P5 IO you use 


```
#!c++
myIOexpander.read(P5);

```


      
void write(int pin, bool status); - it sets the given pin to HIGH is status == true or to LOW if status == false

example : to set P0 to HIGH you would use myIOexpander.write(P0, true);
void toggle(int pin); - if the pin is HIGH, the funciont set's the pin as LOW. If the pin is LOW, it set's the pin as HIGH.
     
                       
int fullread(); - it return a byte read from the IC.
example : some_int = myIOexpander.fullread();
     
void fullwrite(int to_write); - it writes to the IO expander the byte specified.
example : myIOexpander(0x0); - it sets all IO's to LOW



* Configuration
* Dependencies
* Database configuration
* How to run tests
* Deployment instructions

### Contribution guidelines ###

* Writing tests
* Code review
* Other guidelines

### Who do I talk to? ###

* Repo owner or admin
* Other community or team contact