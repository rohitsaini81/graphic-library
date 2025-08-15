#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Vertex data for a simple triangle
GLfloat vertices[] = {
    0.0f,  0.5f, 0.0f,  // Top vertex
   -0.5f, -0.5f, 0.0f,  // Bottom-left
    0.5f, -0.5f, 0.0f   // Bottom-right
};

// Vertex Shader
const char* vertexShaderSource = R"(
    #version 330 core
    layout(location = 0) in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos, 1.0);
    }
)";

// Fragment Shader
const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;
    uniform vec2 resolution;
    uniform float time;
    float random(vec2 p) {
    return fract(sin(time * 2.0) * 0.5 + 0.5);


    }

    void main() {
        vec2 uv = gl_FragCoord.xy / resolution.xy;

    // Random values for each color channel
    float r = sin(time * 2.0) * 0.5 + 0.5; // Range 0..1
    float g = sin(time * 0.7 + 2.0) * 0.5 + 0.5;
    float b = sin(time * 1.3 + 4.0) * 0.5 + 0.5;

    FragColor = vec4(r, g, b, 1.0);
    // FragColor = vec4(randValue, randValue, 0.3, 1.0);
    }
)";

// Compile shader
GLuint compileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader compilation failed:\n" << infoLog << std::endl;
    }
    return shader;
}

// Create shader program
GLuint createShaderProgram() {
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cerr << "Shader linking failed:\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return program;
}

int main() {
    if (!glfwInit()) {
        std::cerr << "GLFW init failed!" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Random Triangle", nullptr, nullptr);
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

    GLuint shaderProgram = createShaderProgram();

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    GLint resolutionLoc = glGetUniformLocation(shaderProgram, "resolution");
    GLint timeLoc = glGetUniformLocation(shaderProgram, "time");
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glUniform2f(resolutionLoc, 800.0f, 600.0f);
        glUniform1f(timeLoc, static_cast<float>(glfwGetTime()));


        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}
