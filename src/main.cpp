#include <iostream>

#include "window.h"
#include "mesh2D.h"
#include "shader.h"
#include "model.h"
#include "camera2D.h"
#include "input.h"

Window wnd;
Camera2D camera;

int main()
{
    wnd.init(800, 800, "openGL");
    Input::init(wnd);
    Shader shader("../resource/shaders/default.vert", "../resource/shaders/default.frag");
    
    const float camera_scale = 4;
    float aspect = camera_scale * (float)wnd.getWidth() / ((float)wnd.getHeight());
    camera.othographic(-aspect, aspect, -camera_scale, camera_scale, 0, 10);

    float clear_color[3]{0.3f, 0.5f, 0.75f};
    while (Input::getKeyUp(GLFW_KEY_ESCAPE) && wnd.shouldClose() == 0)
    {
        glViewport(0, 0, wnd.getWidth(), wnd.getHeight());
        glClearColor(clear_color[0], clear_color[1], clear_color[2], 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //========frame start========
        
        //========frame end========
        Input::update();
        wnd.swapBuffers();
        wnd.updateSize();
        float aspect = camera_scale * (float)wnd.getWidth() / ((float)wnd.getHeight());
        camera.othographic(-aspect, aspect, -camera_scale, camera_scale, 0, 10);
    }

    shader.destroy();
    wnd.cleanup();

    return 0;
}