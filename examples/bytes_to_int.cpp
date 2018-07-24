#include <cstdint>
#include <cstring>

#include <ByteConvert/ByteConvert.cpp>

int main()
{
    // Create array of bytes that represent 1 (type: int)
    uint8_t block[sizeof(int)];
    memset(block,0,sizeof(int)-1);
    block[sizeof(int)-1] = 1;

    int val = ByteConvert::to_variable<int>(block); // Convert array of bytes to int
    if (val != 1) { // Check if we got, what we expected to get
        // Error, something went wrong
        return -1;
    }
    
    // Success
    return 0;
}