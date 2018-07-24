#include <cstdint>
#include <cstring>
#include <memory>

#include <ByteConvert/ByteConvert.hpp>

int main()
{
    // Variable we will change into bytes
    int val = 2;
    // Array of bytes we expect to get back
    uint8_t block[sizeof(int)];
    memset(block,0,sizeof(int)-1);
    block[sizeof(int)-1] = 2;

    // Convert variable to bytes
    size_t result_size = 0; // Size of block, we get back (you can pass nullptr if you know size of result)
    uint8_t* result = ByteConvert::to_block(val, &result_size);

    // Check result
    if (result_size != sizeof(int)) {
        // Error
        delete[] result;
        return -1;
    }
    for (size_t i = 0; i < result_size; i++) {
        if (result[i] != block[i]) {
            // Error: result and expected result don't match
            delete[] result;
            return -2;
        }
    }
    // Clear result !!! It was allocated to heap so we need to manualy free it !!!!!!
    delete[] result;

    // Same as above, just implemented with smart pointers, which is safer
    std::unique_ptr<uint8_t[]> result1(ByteConvert::to_block(val, &result_size));
    // Check result
    if (result_size != sizeof(int)) {
        // Error
        return -3;
    }
    for (size_t i = 0; i < result_size; i++) {
        if (result1[i] != block[i]) {
            // Error: result and expected result don't match
            return -4;
        }
    }
    // No need to free result1, because it clears itself when it goes out of scope

    // Success
    return 0;
}