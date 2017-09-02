# ByteConvert
[![Build Status](https://travis-ci.org/SloCompTech/ByteConvert_cpp.svg?branch=master)](https://travis-ci.org/SloCompTech/ByteConvert_cpp)
[![Packagist](https://img.shields.io/packagist/l/doctrine/orm.svg)]()    

## What's about ?
Have you ever wanted to transmit `int`,`short`,`long`,`double` or any other numeric type over I2C,SPI,serial or other protocol or bus, but you converted variable to string to be able to transmit it char by char. This library enables you to convert any numeric value to bytes or other way around and you can also print array of bytes.

## What you need to consider, when you are using this library
When you are using this library, you need to consider variable byte size, because if you are using different platforms, then there may be some errors, because int on platform 1 has 4 bytes and int on platform 2 may has 2 bytes.

## What you need to install this project ?
You need [python3](https://www.python.org/), [ninja](https://ninja-build.org/) and [meson](http://mesonbuild.com).

```
$ sudo apt-get install python3 python3-pip ninja-build
```

## How to install
```
$ cd <library_directory>
$ mkdir build
$ meson build && cd build
$ ninja
$ sudo ninja install
```

If you have problems, that library can't be found run `sudo ldconfig /usr/local/lib/x86_64-linux-gnu/` if you haven't changed prefix, else mofidy path.

## How to include library to your c or c++ project ?
It's simple. At the top of your source file include library:
``` c++
#include<ByteConvert/ByteConvert.hpp>
```

And when you compile add flag `-lbyteconvert`, example `g++ -std=c++11 MyProject.cpp -lbyteconvert -o MyProject`.
## Examples
Convert numeric variable for eg. `int`,`short`,`float`,`double` to array of bytes.
``` c++
int somevar = 5;
size_t blk_size = 0;
uint8_t *block = ByteConvert::varToArray<int>(blk_size,somevar);

// Use array

delete block; // Don't forget to free memory, when you don't need array any more
```

Convert array of bytes to numeric variable.
``` c++
uint8_t *block; // Predefined byte array with size of int
int somevar = ByteConvert::arrayToVar<int>(block);

// Use block & somevar

delete block; // Don't forget to free memory, when you don't need array any more

// Use somevar
```

Convert array of bytes to string of hex characters
``` c++
size_t blk_size; // Predefined size of byte array
uint8_t *block; // Predefined byte array with size of int
String somevar = ByteConvert::arrayToString(blk_size,block);

// Use block & somevar

delete block; // Don't forget to free memory, when you don't need array any more

// Use somevar
```

Convert string of hex characters to array of bytes
``` c++
String somevar = ""; // Predefined string
size_t blk_size = 0; 
uint8_t *block = ByteConvert::stringToArray(blk_size,somevar);

// Use block 

delete block; // Don't forget to free memory, when you don't need array any more
```