/**
 * @file ByteConvert.cpp
 * 
 * @authors Martin Dagarin
 * @date 22/07/2018
 * 
 * @brief Source file of ByteConvert module
 */

#include "ByteConvert.hpp"

namespace ByteConvert 
{
  std::string byte_to_hex(const uint8_t& byte)
  {
    std::string buffer("");
    uint8_t val;

    for (uint8_t i = 0; i < 2; i++) {
      if (i == 0)
        val = (byte >> 4);
      else
        val = byte & 0x0f;
      if (val >= 16)
        buffer += '?';
      else if (val < 10)
        buffer += ('0' + val);
      else
        buffer += ('W' + val);
    }
    return buffer;
  }

  uint8_t hex_to_byte(const std::string& hex)
  {
    uint8_t val = 0x00;
    uint8_t pos = (hex.size() > 1) ? hex.size() - 2 : hex.size() - 1;
    char c;
    for (; pos < hex.size(); pos++) {
      c = hex[pos];
      if (c >= 'A' && c <= 'F')
        val += (c - '7');
      else if (c >= 'a' && c <= 'f')
        val += (c - 'W');
      else if (c >= '0' && c <= '9')
        val += (c - '0');
      else
        val += '?';
      if (pos == 0 && hex.size() > 1)
        val = (val << 4);
    }
    return val;
  }

  std::string block_to_hex_string(const uint8_t* const block, const size_t& size)
  {
    std::string buffer("");
    for (size_t i = 0; i < size; i++) {
      buffer += byte_to_hex(block[i]);
    }
    return buffer;
  }

  uint8_t* hex_string_to_block(const std::string& hex_string, size_t* const size)
  {
    size_t block_size = hex_string.size()/2 + ((hex_string.size() % 2 == 1) ? 1 : 0);
    uint8_t* block = new uint8_t[block_size];
    int offset = 0;
    for (size_t i = 0;i < block_size; i++) {
      if (i == 0 && hex_string.size() % 2 == 1) {
        offset = -1;
        block[i] = hex_to_byte(std::string("0") + hex_string[0]);
        continue;
      }
      block[i] = hex_to_byte(std::string(1,hex_string[i*2 + offset]) + hex_string[i*2 + 1 + offset]);  
    }
    if (size != nullptr)
      *size = block_size;
    return block;
  }  
}
