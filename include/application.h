#pragma once

#include "window.h"
#include "mesh2D.h"
#include "shader.h"
#include "model.h"
#include "camera2D.h"
#include "input.h"
#include "gui.h"

class Application
{
public:
    int run();

    void init();
    void update();

    void cleanup();

private:
    Window main_window;
    Camera2D main_camera;

    Model m;

    bool run_app = true;
};