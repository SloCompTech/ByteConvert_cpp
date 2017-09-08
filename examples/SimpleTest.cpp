#include <iostream>
#include <cstdlib>
// Use: #include <ByteConvert/ByteConvert.hpp>
// For testing
#include "../libbyteconvert/ByteConvert.hpp"

using namespace std;

int main() {
  cout << "Simple test" << endl;
  cout << "size(short): " << sizeof(short) << endl;
  cout << "size(int): " << sizeof(int) << endl;
  cout << "size(float): " << sizeof(float) << endl;
  cout << "size(char): " << sizeof(char) << endl;
  cout << "size(uint8_t): " << sizeof(uint8_t) << endl;
  cout << "valToHex: 9->" << ByteConvert::valToHex(0x09) << endl;
  cout << "valToHex: b->" << ByteConvert::valToHex(0x0b) << endl;
  cout << "byteToHexString: fa->" << ByteConvert::byteToHexString(0xfa) << endl;

  uint8_t array1[] = {0xfa,0xca,0xde,0xda};
  cout << "facadeda -> " << ByteConvert::arrayToString(4,array1) << endl;

  size_t s2 = 0;
  uint8_t *array2 = ByteConvert::stringToArray(s2,"bedababa");
  cout << "Size(bedababba): " << s2 << endl;
  cout << "bedababba -> " << ByteConvert::arrayToString(s2,array2) << endl;

  delete array2;

  int in = 5;
  cout << "Orig: 5 -> " << in << endl;
  size_t s3 = 0;
  uint8_t *array3 = ByteConvert::varToArray<int>(s3,in);
  cout << "00000005 -> " << ByteConvert::arrayToString(s3,array3) << endl;
  cout << "5 -> " << ByteConvert::arrayToVar<int>(array3) << endl;

  delete array3;

  return 0;
}