#ifndef SHADERS_H
#define SHADERS_H

#include <glad/gl.h>
#include <string>
#include <iostream>
#include <vector>

//advanced calculation stuff
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class Shader {
public:
    unsigned int shaderID;
    Shader(int shaderType, const char * shaderpath);
};

class ShaderProgram {
public:
    unsigned int programID;
    ShaderProgram(std::vector<Shader> shaders);
    
    void use();
    // utility uniform functions
    void setInt(const std::string &name, int value);   
    void setBool(const std::string &name, bool value); 
    void setFloat(const std::string &name, float value);

    void setVec3(const std::string& name, float x, float y, float z);
    void setVec4(const std::string& name, float x, float y, float z, float w);
    void setMatrix4fv(const std::string& name, glm::mat4 trans);
};

#endif