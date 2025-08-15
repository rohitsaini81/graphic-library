cmake_minimum_required(VERSION 3.31)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

# Find and include OpenGL
find_package(OpenGL REQUIRED)
include_directories(/usr/include)

# Add the executable first
add_executable(untitled1 main.cpp)
# Link libraries
target_link_libraries(untitled1
        OpenGL::GL
        glfw
        GLEW
)
