# Set the source files for the main application in the Sandbox directory
set(APP_SOURCES
    Application.cpp
)

# Build the main application in the Sandbox directory
add_executable(SandboxApp ${APP_SOURCES})

# Set any additional compile options or flags if needed
# target_compile_options(SandboxApp PRIVATE ...)

# Set any necessary include directories for the main application
target_include_directories(SandboxApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Axel)

# Set any linker flags or library dependencies required for the application
target_link_libraries(SandboxApp PRIVATE AxelLibrary)

# Install the application if desired
# install(TARGETS SandboxApp DESTINATION ...)
