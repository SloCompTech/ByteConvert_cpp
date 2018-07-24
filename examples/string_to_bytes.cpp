#include <cstdint>
#include <cstring>
#include <string>
#include <memory>

#include <ByteConvert/ByteConvert.hpp>

int main()
{
    // String that we will convert to bytes
    std::string example_string = "facaceca";
    // Array of bytes we expect to get
    uint8_t expected[4] = {0xfa, 0xca, 0xce, 0xca};

    // Convert string to bytes
    size_t result_size = 0;
    uint8_t* result = ByteConvert::hex_string_to_block(example_string, &result_size);

    // Check result
    if (result_size != 4) {
        // Error, unexpected size of result
        delete[] result;
        return -1;
    }
    for (size_t i = 0; i < result_size; i++) {
        if (expected[i] != result[i]) {
            // Error, result not expected
            delete[] result;
            return -2;
        }
    }

    // Clear result !!! It was allocated to heap so we need to manualy free it !!!!!!
    delete[] result;

    // Same as above, just implemented with smart pointers, which is safer
    std::unique_ptr<uint8_t[]> result1(ByteConvert::hex_string_to_block(example_string, &result_size));
    
    // Check result
    if (result_size != 4) {
        // Error, unexpected size of result
        return -1;
    }
    for (size_t i = 0; i < result_size; i++) {
        if (expected[i] != result1[i]) {
            // Error, result not expected
            return -2;
        }
    }


    // No need to free result1, because it clears itself when it goes out of scope

    // Success
    return 0;
}