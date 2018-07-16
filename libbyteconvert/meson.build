# Install headers
install_headers('ByteConvert.hpp', subdir : 'ByteConvert')

# List sources
src = ['ByteConvert.cpp']

# Link & build libraries
libbyteconvert = library(
    meson.project_name(), 
    src, 
    version : meson.project_version(),
    install: true
)