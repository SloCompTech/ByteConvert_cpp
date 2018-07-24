/**
 * @file ByteConvert.hpp
 * 
 * @authors Martin Dagarin
 * @date 22/07/2018
 * 
 * @brief Header of ByteConvert module
 */

#ifndef _ByteConvert_hpp_
#define _ByteConvert_hpp_

#include <string>
#include <cstdint>


/**
 * @brief Namespace which holds all ByteConvert functions
 */
namespace ByteConvert {
  /**
   * @brief Converts single byte to hex string
   * 
   * @param[in] byte Byte to convert to hex string
   * @return Hex string
   */
  std::string byte_to_hex(const uint8_t& byte);

  /**
   * @brief Converts hex string (1 or 2 chars) to byte
   * 
   * @param[in] hex Hex string (1 or 2 chars) to convert to byte
   * @return Byte
   */
  uint8_t hex_to_byte(const std::string& hex);

  /**
   * @brief Converts array of bytes to hex string
   * 
   * @param[in] block Array of bytes
   * @param[in] size Size of block
   * @return Hex string
   */
  std::string block_to_hex_string(const uint8_t* const block, const size_t& size);

  /**
   * @brief Converts hex string to array of bytes
   * 
   * @param[in] hex_string Hex string
   * @param[out] size Size of returned array
   * @return Array of bytes
   */
  uint8_t* hex_string_to_block(const std::string& hex_string,size_t* const size);  
  
  /**
   * @brief Converts numeric without floating point variables (uses sizeof()) to array of bytes 
   * 
   * @param[in] variable Variable to convert to bytes
   * @param[out] size Size of array (if pointer specifed)
   * @return Array of bytes
   */
  template<class T>
  uint8_t* to_block(T variable,size_t* const size)
  {
    uint8_t block_size = sizeof(T)/sizeof(uint8_t);
    uint8_t *block = new uint8_t[block_size];
    for (size_t i = 0; i < block_size; i++) {
      if (i != 0) variable >>= 8;
      block[block_size - 1 - i] = (uint8_t)(variable & 0xff);
    }
    if (size != nullptr)
      *size = block_size;
    return block;
  }

  /**
   * @brief Converts byte to variable
   * 
   * @param[in] block Array of bytes
   * @return Variable
   */
  template<class T>
  T to_variable(const uint8_t* block)
  {
    size_t var_size = sizeof(T)/sizeof(uint8_t);
    T var = 0x00;
    for (size_t i = 0; i < var_size; i++) {
      if (i != 0) var <<= 8;
      var |= block[i];
    }
    return var;
  }

  /**
   * @brief Converts byte to variable
   * 
   * @param[in] block Array of bytes
   * @return Variable
   */
  template<class T>
  T to_variable(const uint8_t* block, const size_t& block_size)
  {
    T var = 0x00;
    for (size_t i = 0; i < block_size; i++) {
      if (i != 0) var <<= 8;
      var |= block[i];
    }
    return var;
  }
}

#endif
