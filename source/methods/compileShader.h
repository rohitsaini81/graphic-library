//
// Created by rohit on 8/16/25.
//

#ifndef COMPILESHADER_H
#define COMPILESHADER_H
#include <GL/glew.h>

extern  int version;
extern  void init_shaders();
extern GLuint compileShader(GLenum type, const char* source);
extern GLuint createShaderProgram(const char* fragmentShaderSource, const char* vertexShaderSource);



#endif //COMPILESHADER_H
