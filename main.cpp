

#include "./source/methods/compileShader.h"
#include "source/methods/library/methods.h"

#include <iostream>
#include <GLFW/glfw3.h>


// Vertex Shader
// Fragment Shader
const char* fragmentShaderSource;


int main() {
    INIT_LIB();


    float one=1;
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glUniform2f(resolutionLoc, 800.0f, 600.0f);
        // glUniform1f(timeLoc, static_cast<float>(glfwGetTime()));
        glUniform1f(timeLoc, one+=0.1);
        // one= one>2?0:one;
        // vertices[0]=one;
        // vertices[3]=one-0.2;
        // vertices[6]=one+0.2;

        //
        glBufferData(GL_ARRAY_BUFFER, vertexCount*sizeof(GLfloat), vertices, GL_STATIC_DRAW);





        glBindVertexArray(VAO);
        std::cout << "running..."<<std::endl;
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
    }

END();
    return 0;
}
