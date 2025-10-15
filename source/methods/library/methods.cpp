//
// Created by rohit on 10/15/25.
//

#include "methods.h"

#include <iostream>
#include <ostream>
// #include <GL/glew.h>

int INIT_LIB() {
    if (!glfwInit()) {
        std::cerr << "GLFW init failed!" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(800, 600, "zing graphic library", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow*, int width, int height) {
        glViewport(0, 0, width, height);
    });


    // if (glewInit() != GLEW_OK) {
    //     std::cerr << "GLEW init failed!" << std::endl;
    //     return -1;
    // }

    glViewport(0, 0, 800, 600);




}
