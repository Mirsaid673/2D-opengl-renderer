#pragma once

#include "window.h"
#include "mesh2D.h"
#include "shader.h"
#include "sprite.h"
#include "camera2D.h"
#include "input.h"
#include "gui.h"

class Application
{
public:
    int run();

    void app_init();
    void app_update();

    virtual void init() {};
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void cleanup(){};

    void app_cleanup();

protected:
    Window main_window;
    Camera2D camera;

    bool run_app = true;
};