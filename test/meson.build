# List of tests
tests = [
    ['byte_to_hex',['byte_to_hex.cpp']],
    ['hex_to_byte',['hex_to_byte.cpp']],
    ['block_to_hex_string',['block_to_hex_string.cpp']],
    ['hex_string_to_block',['hex_string_to_block.cpp']],
    ['to_block',['to_block.cpp']],
    ['to_variable',['to_variable.cpp']]
]

# Compile all test
foreach test: tests
    exe = executable(test[0], test[1], link_with: libbyteconvert, include_directories: libbyteconvert_include)
    test(test[0],exe)
endforeach
