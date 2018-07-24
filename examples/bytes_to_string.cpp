#include <cstdint>
#include <cstring>
#include <string>

#include <ByteConvert/ByteConvert.hpp>

int main()
{
    // Set array of bytes which we will convert to string
    uint8_t block[8] = {0xfa, 0xca, 0xba, 0xba, 0xde, 0xda, 0xce, 0xca};
    // Set expected string
    std::string expected_string = "facababadedaceca";

    // Convert bytes to string (8 is size of block)
    std::string converted_string = ByteConvert::block_to_hex_string(block, 8);

    // Check the result
    if (converted_string != expected_string) {
        // Error
        return -1;
    }
    
    // Success
    return 0;
}