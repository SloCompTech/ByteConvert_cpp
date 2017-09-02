pkg = import('pkgconfig')
mylib = shared_library('byteconvert', 'ByteConvert.cpp', version : '0.1.2', soversion : '0',install: true)
install_headers('ByteConvert.hpp', subdir : 'ByteConvert')
pkg.generate(libraries : mylib,
             version : '0.1.2',
             name : 'libbyteconvert',
             filebase : 'libbyteconvert',
             description : 'A conversion library.',
             variables : 'URL=https://github.com/SloCompTech/ByteConvert_cpp')
