//
// Created by ttran on 13.11.2018.
//
#include "game.h"
#include "glwrapper.h"

void on_surface_created() {
    glClearColor(0.0, 0.0, 0.3, 1.0); //dark blue
}

void on_surface_changed() {
}

char* on_draw_frame(unsigned int VBO, unsigned int vao, float * vertices_cpp_pointer) {
    unsigned int index[] = {
            0, 1, 2,
    };
    float vertices_cpp[9];
    for(int i=0;i<9;i++){
        vertices_cpp[i]=vertices_cpp_pointer[i];
    }
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_cpp), vertices_cpp, GL_STATIC_DRAW);
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    int success;
    char * infoLog = (char*)malloc(512);
    strcpy(infoLog, "OK");
    const char *vertexShaderSource ="#version 300 es\n"
                                    "layout (location = 0) in vec3 aPos;\n"
                                    "void main()\n"
                                    "{\n"
                                    "   gl_Position = vec4(aPos, 1.0);\n"
                                    "}\0";

    const char *fragmentShaderSource = "#version 300 es\n"
                                       "precision mediump float;\n"
                                       "out vec4 color;\n"
                                       "void main()\n"
                                       "{\n"
                                       "   color = vec4(1.0,1.0,0.0,1.0);\n"
                                       "}\n\0";
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success)
    {
        //glGetProgramInfoLog(shaderProgram, 512, NULL,infoLog);
        strcpy(infoLog, "ERRORRRRRR");
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);

    glEnableVertexAttribArray(0);
    glBindVertexArray(vao);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
    );
    glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,index);
    glDisableVertexAttribArray(0);

    //sleep(1);
    return infoLog;
}