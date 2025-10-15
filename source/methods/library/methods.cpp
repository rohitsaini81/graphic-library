//
// Created by rohit on 10/15/25.
//

#include <iostream>
#include <ostream>
#include "methods.h"

#include "../../methods/compileShader.h"
#include "../../methods/Loader.h"


GLuint VAO, VBO;
GLint resolutionLoc;
GLint timeLoc;
GLFWwindow* window;
GLuint shaderProgram=0;

// Vertex data for a simple triangle
GLfloat vertices[] = {
    0.0f,  0.5f, 0.0f,  // Top vertex
   -0.5f, -0.5f, 0.0f,  // Bottom-left
    0.5f, -0.5f, 0.0f   // Bottom-right
};
const unsigned int vertexCount = sizeof(vertices);  // Or number of floats
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


    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW init failed!" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    std::string vertexShaderSource = load_file("shaders/vertex.vs");
    std::string fragmentShaderSource = load_file("shaders/frag.fs");


    shaderProgram = createShaderProgram(fragmentShaderSource.c_str(),vertexShaderSource.c_str());

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)nullptr);
    glEnableVertexAttribArray(0);
    // glBindVertexArray(0);

    resolutionLoc = glGetUniformLocation(shaderProgram, "resolution");
    timeLoc = glGetUniformLocation(shaderProgram, "time");

return  0;
}


void END() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
}