#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "glm.hpp"

class Input {
public:
    float mouseoutside;
    float mouselastx;
    float mouselasty;

    Input();
};
