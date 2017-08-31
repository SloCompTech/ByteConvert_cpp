#include "ByteConvert.hpp"
namespace ByteConvert {
  char valToHex(uint8_t val) {
    if ((val & 0x0f) < 10)
      return ('0' + val);
    else
      return ('a' + (val - 10));
  }
  uint8_t hexToVal(char c) {
    if (c >= 'a')
      return (15 - ('f' - c));
    else
      return (9 - ('9' - c));
  }
  std::string byteToHexString(uint8_t b) {
    std::string buffer = "";
    buffer += valToHex(b & 0x0f);
    b >>= 4;
    buffer = valToHex(b & 0x0f) + buffer;
    return buffer;
  }
  uint8_t hexStringToByte(std::string block) {
    if (block.length() != 2)
      return 0x00;
    return 16*hexToVal(block.at(0))+hexToVal(block.at(1));
  }

  std::string arrayToString(size_t size,uint8_t *src) {
    std::string buffer = "";
    for (size_t i = 0;i < (size);i++)
      buffer += byteToHexString(src[i]);
    return buffer;
  }
  uint8_t* stringToArray(size_t &size,std::string src) {
    // Length of src must be odd !!
    if (src.length() % 2 == 1)
      src = "0" + src;
    size = src.length()/2;
    uint8_t *dst = new uint8_t[size]; // Allocate memory space
    std::string buff = "";
    for (size_t i = 0;i < (size);i++) {
      buff = src.at(i*2);
      buff += src.at(i*2+1);
      dst[i] = hexStringToByte(buff);
    }
    return dst;
  }
}
