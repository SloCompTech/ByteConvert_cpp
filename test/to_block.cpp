#include <iostream>
#include <memory>

#include <ByteConvert/ByteConvert.hpp>

int main()
{
    std::cout << "Testing to_block function" << std::endl;

    std::cout << "Testing" << std::endl;
    
    // Test int
    int int_var = 1;
    size_t int_size;
    std::unique_ptr<uint8_t[]> int_res(ByteConvert::to_block(int_var,&int_size));
    for (size_t i = 0; i < int_size; i++) {
        if (i != int_size - 1 && int_res[i] != 0x00) {
            std::cout << "Expected: 0 Got: " << unsigned(int_res[i]) << std::endl;
        } else if (i == int_size - 1 && int_res[i] != 0x01) {
            std::cout << "Expected: 1 Got: " << unsigned(int_res[i]) << std::endl;
        }
    }

    int int_var1 = -1;
    size_t int_size1;
    std::unique_ptr<uint8_t[]> int_res1(ByteConvert::to_block(int_var1,&int_size1));
    for (size_t i = 0; i < int_size1; i++) {
        if (int_res1[i] != 0xff) {
            std::cout << "Expected: 255 Got: " << unsigned(int_res1[i]) << std::endl;
        }
    }

    // Test uint8_t
    uint8_t uint8_var = 2;
    size_t uint8_size;
    std::unique_ptr<uint8_t[]> uint8_res(ByteConvert::to_block(uint8_var,&uint8_size));
    for (size_t i = 0; i < uint8_size; i++) {
        if (uint8_res[i] != 0x02) {
            std::cout << "Expected: 2 Got: " << unsigned(uint8_res[i]) << std::endl;
        }
    }
   

    std::cout << "Done" << std::endl;
    
    return 0;
}