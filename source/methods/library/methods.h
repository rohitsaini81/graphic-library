//
// Created by rohit on 10/15/25.
//

#ifndef ZING_METHODS_H
#define ZING_METHODS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
extern GLFWwindow* window;
extern GLint resolutionLoc;
extern GLint timeLoc;
extern GLuint VAO, VBO;
extern GLfloat vertices[];
extern GLuint shaderProgram;
extern const unsigned int vertexCount;
int INIT_LIB();

class methods {
    public:
    methods();
    ~methods();
};

void END();
#endif //ZING_METHODS_H