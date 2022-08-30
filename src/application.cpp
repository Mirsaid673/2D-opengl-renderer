#include "application.h"

#include <iostream>

int Application::run()
{
    init();
    while (run_app && main_window.shouldClose() == 0)
        update();

    cleanup();

    return 0;
}

void Application::init()
{
    main_window.init(800, 800, "openGL");
    Input::init(main_window);
    Shader::initDefaultShader("../resource/shaders/default.vert", "../resource/shaders/default.frag");
    GUI::init(main_window);

    main_camera.scale = 2;
    main_camera.width = (float)main_window.getWidth() / (float)main_window.getHeight();
    main_camera.height = 1.0f;
    main_camera.update();

    m.load("../resource/textures/w7.png");
    m.transform.translate(glm::vec2(1.f, 0));
}

void Application::update()
{
    static int fps = 0;
    static double time = glfwGetTime();
    float clear_color[3]{0.3f, 0.5f, 0.75f};
    glViewport(0, 0, main_window.getWidth(), main_window.getHeight());
    glClearColor(clear_color[0], clear_color[1], clear_color[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    main_camera.transform.rotate(glm::radians(1.0f));

    // updating sizes

    main_camera.width = (float)main_window.getWidth() / (float)main_window.getHeight();
    main_camera.height = 1.0f;
    main_camera.update();

    //  drawing
    Shader::default_shader.use();
    Shader::default_shader.setCamera(main_camera);

    m.draw();

    GUI::newFrame();
    static bool show_demo = true;
    if (show_demo)
        ImGui::ShowDemoWindow(&show_demo);
    GUI::renderFrame();

    Input::update();
    main_window.swapBuffers();
    main_window.updateSize();

    if (Input::getKeyPress(GLFW_KEY_ESCAPE))
        run_app = false;
    fps++;
    double now = glfwGetTime();
    if (now - time >= 5.)
    {
        std::cout << (double)fps / (now - time) << "   " << now << '\n';
        time = now;
        fps = 0;
    }
}

void Application::cleanup()
{
    GUI::cleanup();
    main_window.cleanup();
}