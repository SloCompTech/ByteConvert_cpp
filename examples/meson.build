# List of examples
examples = [
    ['bytes_to_int',['bytes_to_int.cpp']],
    ['bytes_to_string',['bytes_to_string.cpp']],
    ['int_to_bytes',['int_to_bytes.cpp']],
    ['string_to_bytes',['string_to_bytes.cpp']]
]

# Compile all test
foreach example: examples
    exe = executable(example[0], example[1], link_with: libbyteconvert, include_directories: libbyteconvert_include)
    test('example_' + example[0],exe)
endforeach
