cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Build the dynamic library in the Axel directory
add_subdirectory(Axel)

# Check if an alternative main application directory is provided as a CMake option
if(DEFINED ALTERNATE_MAIN_APP_DIR)
  add_subdirectory(${ALTERNATE_MAIN_APP_DIR})
else()
  # Build the main application in the Sandbox directory by default
  add_subdirectory(Sandbox)
endif()
