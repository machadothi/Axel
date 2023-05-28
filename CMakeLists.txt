cmake_minimum_required(VERSION 3.0)
project(GameEngineProject)

set(CMAKE_CXX_STANDARD 14)

# Build the dynamic library in the Axel directory
add_subdirectory(Axel)

# Check if an alternative main application directory is provided as a CMake option
if(DEFINED ALTERNATE_MAIN_APP_DIR)
  if(${ALTERNATE_MAIN_APP_DIR} STREQUAL "MainSand")
    add_subdirectory(MainSand)
  elseif(${ALTERNATE_MAIN_APP_DIR} STREQUAL "AnotherDirectory")
    add_subdirectory(AnotherDirectory)
  else()
    message(FATAL_ERROR "Invalid ALTERNATE_MAIN_APP_DIR value: ${ALTERNATE_MAIN_APP_DIR}")
  endif()
else()
  # Build the main application in the Sandbox directory by default
  add_subdirectory(Sandbox)
endif()
