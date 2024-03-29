#pragma once

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

// Needed for cout in windowinit.cpp
#include <iostream>

// initialize glfw
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
GLFWwindow& WindowInit();
