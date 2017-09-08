project('libbyteconvert','cpp',
        version:'0.1.4',
        default_options : [
            'c_std=c11', 
            'cpp_std=c++11'])
pkg = import('pkgconfig')

subdir('libbyteconvert')

pkg.generate(libraries : mylib,
             version : meson.project_version(),
             name : 'libbyteconvert',
             filebase : 'byteconvert',
             description : 'A conversion library.',
             url: 'https://github.com/SloCompTech/ByteConvert_cpp')
