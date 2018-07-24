#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <sstream>
#include <memory>

#include <ByteConvert/ByteConvert.hpp>

int main()
{
    std::cout << "Testing hex_string_to_block function" << std::endl;

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

    // Test odd length hex strings
    std::cout << "Testing" << std::endl;

    size_t block_size = 0;
    std::string inval("");
    for (uint8_t i = 0; i < 0xff;i++) {
        inval = test_values[(int)i].second + test_values[((int)i)+1].second;
        std::unique_ptr<uint8_t[]> block(ByteConvert::hex_string_to_block(inval,&block_size));
        if (block_size != 2 || block[0] != test_values[(int)i].first || block[1] != test_values[((int)i)+1].first) {
            uint8_t bl1[2] = {test_values[(int)i].first, test_values[((int)i)+1].first};
            uint8_t bl2[2] = {block[0], block[1]};
            std::cout << "Expected: " << ByteConvert::block_to_hex_string(bl1,2) << " Got: " << ByteConvert::block_to_hex_string(bl2,2) << std::endl;
            return -1;
        }
        if (i == 0xff)
            break;
    }

    // Test even length hex strings
    for (uint8_t i = 0; i < 0xff;i++) {
        inval = test_values[(int)i].second[1] + test_values[((int)i)+1].second;
        std::unique_ptr<uint8_t[]> block(ByteConvert::hex_string_to_block(inval,&block_size));
        if (block_size != 2 || block[0] != static_cast<uint8_t>(test_values[(int)i].first & 0x0f) || block[1] != test_values[((int)i)+1].first) {
            uint8_t bl1[2] = {static_cast<uint8_t>(test_values[(int)i].first & 0x0f), test_values[((int)i)+1].first};
            uint8_t bl2[2] = {block[0], block[1]};
            std::cout << "Expected: " << ByteConvert::block_to_hex_string(bl1,2) << " Got: " << ByteConvert::block_to_hex_string(bl2,2) << std::endl;
            return -1;
        }
        if (i == 0xff)
            break;
    }

    std::cout << "Done" << std::endl;
    
    return 0;
}