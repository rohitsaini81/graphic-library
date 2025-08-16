cmake_minimum_required(VERSION 3.31)
project(zing)

set(CMAKE_CXX_STANDARD 20)

# Find and include OpenGL
find_package(OpenGL REQUIRED)
include_directories(/usr/include)
include_directories(/usr/include)

# Add the executable first
add_executable(gp-lib main.cpp ./source/methods/compileShader.cpp)
# Link libraries
target_link_libraries(gp-lib
        OpenGL::GL
        glfw
        GLEW
)
