#pragma once

#include <glm.hpp>

// hold information about camera
// currently with default information
class Camera{
public:
    glm::vec3 camerapos;
    glm::vec3 camerafront;
    glm::vec3 cameraup;
    float yaw;
    float pitch;
    float fov;

    Camera(
        glm::vec3 cameraposition = glm::vec3(-50.0f, 180.0f, -50.0f),
        glm::vec3 camerafront = glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3 cameraup = glm::vec3(0.0f, 1.0f, 0.0f),
        float yaw = -90.0f,
        float pitch = 0.0f,
        float fov = 45.0f
    );
};
