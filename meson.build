# Project info
project('byteconvert', 'cpp', version:'2.0.0', license: 'MIT', default_options : ['cpp_std=c++11'])

# Import modules
pkg = import('pkgconfig')

# Include directories
libbyteconvert_include = include_directories('.')

# Run subscripts
subdir('ByteConvert') # Run meson script in libbyteconvert dir
subdir('examples') # Run meson script in examples dir
subdir('test')

# Package info
pkg.generate(
    name : 'lib' + meson.project_name(),
    description : 'Library for converting variables to bytes.',
    version : meson.project_version(),
    filebase : meson.project_name(),
    url: 'https://github.com/SloCompTech/ByteConvert_cpp',
    libraries : libbyteconvert
)

# Declare as dependency so it can be used elsewhere
libbyteconvert_dep = declare_dependency(
    link_with: libbyteconvert,
    include_directories: libbyteconvert_include
)