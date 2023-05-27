# Set the source files for the main application in the MainSand directory
set(APP_SOURCES
    MainSandSourceFile1.cpp
    MainSandSourceFile2.cpp
    ...
)

# Build the main application in the MainSand directory
add_executable(MainSandApp ${APP_SOURCES})

# Set any additional compile options or flags if needed
# target_compile_options(MainSandApp PRIVATE ...)

# Set any necessary include directories for the main application
# target_include_directories(MainSandApp PRIVATE ...)

# Set any linker flags or library dependencies required for the application
# target_link_libraries(MainSandApp PRIVATE AxelLibrary)

# Install the application if desired
# install(TARGETS MainSandApp DESTINATION ...)
