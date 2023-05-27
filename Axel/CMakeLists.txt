# Set the source files for the dynamic library in the Axel directory
set(LIBRARY_SOURCES
    Test.cpp
)

# Create the dynamic library in the Axel directory
add_library(AxelLibrary SHARED ${LIBRARY_SOURCES})

# Set any additional compile options or flags if needed
# target_compile_options(AxelLibrary PRIVATE ...)

# Set any necessary include directories for the library
# target_include_directories(AxelLibrary PRIVATE ...)

# Set any linker flags or library dependencies required for the library
# target_link_libraries(AxelLibrary PRIVATE ...)

# Install the library if desired
# install(TARGETS AxelLibrary DESTINATION ...)
