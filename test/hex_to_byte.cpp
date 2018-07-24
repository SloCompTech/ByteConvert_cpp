#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <sstream>

#include <ByteConvert/ByteConvert.hpp>

int main()
{
    std::cout << "Testing hex_to_byte function" << std::endl;

    // Generate all posible values for 1 byte
    std::cout << "Generating all posibilities" << std::endl;
    
    std::vector<std::pair<uint8_t, std::string>> test_values;
    test_values.reserve(256);
    std::stringstream ss("");

    for (uint8_t i = 0; i <= 0xff; i++) {
        ss << std::hex << unsigned(i);
        test_values.push_back(std::make_pair(i,(ss.str().size()==2)? ss.str() : "0" + ss.str()));
        ss.str("");
        if (i == 0xff)
            break;    
    }

    // Test function
    std::cout << "Testing" << std::endl;

    uint8_t value;
    for (uint8_t i = 0; i <= 0xff; i++) {
        value = ByteConvert::hex_to_byte(test_values[(int)i].second);
        if (value != test_values[(int)i].first) {
            std::cout << "Expected: " << unsigned(test_values[(int)i].first) << " Got: " << unsigned(value) << std::endl;
            return -1;
        }
        if (i == 0xff)
            break;
    }

    std::cout << "Done" << std::endl;
    
    return 0;
}