<p align="center"><img src="extras/graphics/512.png" alt="Byteconvert" height="200px"></p>

# ByteConvert

[![Build Status](https://travis-ci.org/SloCompTech/ByteConvert_cpp.svg?branch=master)](https://travis-ci.org/SloCompTech/ByteConvert_cpp)
[![Packagist](https://img.shields.io/packagist/l/doctrine/orm.svg)]()    

## What's about ?

Have you ever wanted to transmit `int`,`short`,`long` or any other numeric type over I2C,SPI,serial or other protocol or bus, but you converted variable to string to be able to transmit it char by char. This library enables you to convert any numeric value to bytes or other way around and you can also print array of bytes.

## What you need to consider, when you are using this library

When you are using this library, you need to consider variable byte size, because if you are using different platforms, then there may be some errors, because int on platform 1 has 4 bytes and int on platform 2 may has 2 bytes.

## What you need to install this project ?

You need [python3](https://www.python.org/), [ninja](https://ninja-build.org/) and [meson](http://mesonbuild.com).

```bash
sudo apt-get install python3 python3-pip ninja-build
sudo pip3 install meson
```

## Installing
```bash
meson build
ninja -C build
ninja -C build test
ninja -C build install

# Or simply
make
sudo make install
```

If you have problems, that library can't be found run `sudo ldconfig /usr/local/lib/x86_64-linux-gnu/` if you haven't changed prefix, else modify path.

## How to include library to your c or c++ project ?

It's simple. At the top of your source file include library:

```c++
#include <ByteConvert/ByteConvert.hpp>
```

And when you compile add flag `-lbyteconvert`, example `g++ -std=c++11 MyProject.cpp -lbyteconvert -o MyProject`.

## Examples

See [**examples folder**](https://github.com/SloCompTech/ByteConvert_cpp/tree/master/examples)