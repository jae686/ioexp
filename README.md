# README #


### What is this repository for? ###

The IOexp libary is a simple libary that it makes easier to work with the pcf8574 IO expander.
Current Version : 0.9

* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### How do I get set up? ###

* Installation Procedure : It is installed in the same way as any regular arduino library. 

### Usage ###
  
Include the IOexp.h and Wire.h to your sketch
  
Declare a IOexp instance before the setup() function.

Usage : 

```
#!c++
IOexp myIOexpander(address);

```

The address must be 7 bit. For a pfc8574P with A2 A1 and A0 set to 0 you could define it as 

```
#!c++
#define (0x4 << 3 | 0x0)

```
  
* Don't forget to add the Wire.begin(); to your setup function!!
* When a function requests a pin, you should use the datasheet definition (P0 though P7) !
    
After the above steps, you will have several functions avaliable to set and read the IO's of your IO expander.
these are ( for simplicity sake in this examples i use myIOexpander, but this should be replaced by the instance name you used then you declared your IOexp instance...)

Refer to the IOExp.h for the all the functions definitions.
An example is also provided with the library.


The following function allows to read a single pin's status (it returns true if the the IO is HIGH of false if LOW).
```
#!c++
bool read(int pin); 

```
    
Example : to read the P0 IO (check the datasheet!) you should type 

```
#!c++

myIOexpander.read(P0);

```

To read the P5 IO you use 

```
#!c++
myIOexpander.read(P5);

```

The following function sets the given pin to HIGH is status == true or to LOW if status == false
```
#!c++
void write(int pin, bool status);

```

example : to set P0 to HIGH you would use 


```
#!c++
myIOexpander.write(P0, true);

```


The toggle(int pin); function just toggles a given pin status (If the pin is HIGH, the function set's the pin as LOW. If the pin is LOW, it set's the pin as HIGH).
```
#!c++
void toggle(int pin);

```

The fullread and fullwrite functions allows to read and write to all IO's an the same time. Useful to get a byte with the IO status to perform byte wise operations on.

The following function returns a byte read from the IC's IO pins.

```
#!c++
int fullread();

```
     
Example : 

```
#!c++
some_int = myIOexpander.fullread();

```

The following function sets the IC's IO according to a supplied byte.     

```
#!c++
void fullwrite(int to_write);

```

Example (it sets all IO's to LOW) : 

```
#!c++
myIOexpander.fullwrite(0x0);

```



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