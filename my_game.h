#pragma once

#include "application.h"

class MyGame : public Application
{
    Sprite s;
    void init() override
    {
        s.load("../resource/textures/w7.png");
    }
    void update() override
    {
        if (Input::getKeyPress(GLFW_KEY_ESCAPE))
            run_app = false;
        camera.transform.rotate(glm::radians(1.0f));
    }
    void draw() override
    {
        Shader::default_shader.use();
        Shader::default_shader.setCamera(camera);
        Shader::default_shader.setMat3x2("m", glm::mat3x2(1, 0, 0, 1, 0, 0));
        Shader::default_shader.setScalar("tex", 0);
        s.draw();
    }
    void cleanup() override {}
};