# Project info
project('byteconvert', 'cpp', version:'1.0.0', license: 'MIT', default_options : ['cpp_std=c++11'])

# Import modules
pkg = import('pkgconfig')

subdir('libbyteconvert') # Run meson script in libbyteconvert dir
subdir('examples') # Run meson script in examples dir

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
libbyteconvert_inc = include_directories('libbyteconvert')
libbyteconvert_dep = declare_dependency(
    link_with: libbyteconvert,
    include_directories: libbyteconvert_inc
)