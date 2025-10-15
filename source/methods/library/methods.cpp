//
// Created by rohit on 10/15/25.
//

#include "methods.h"

#include <iostream>
#include <ostream>

int INIT_LIB() {
    if (!glfwInit()) {
        std::cerr << "GLFW init failed!" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "zing graphic library", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }



}
