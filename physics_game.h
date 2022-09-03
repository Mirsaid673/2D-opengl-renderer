#pragma once

#include "application.h"
#include "box.h"

#include <memory>
#include <array>

struct Obj
{
    Model m;
    Box b;

    void updateTransform()
    {
        b2Vec2 p = b.getBody()->GetPosition();
        float a = b.getBody()->GetAngle();
        m.transform.position = glm::vec2(p.x, p.y);
        m.transform.setRotation(a);
    }

    void updateBoxTransform()
    {
        b.getBody()->SetTransform(b2Vec2(m.transform.position.x, m.transform.position.y), b.getBody()->GetAngle());
    }
};

class MyGame : public Application
{
    std::unique_ptr<b2World> world;
    Obj *current;

    Model Ground;
    std::array<Obj, 20> objects;

    void init() override
    {
        camera.scale = (float)main_window.getWidth() / 50.f;

        b2Vec2 gravity(0, -9.81f);
        world = std::make_unique<b2World>(gravity);

        b2BodyDef groundbd;
        groundbd.position.Set(0, -4);
        b2Body *ground = world->CreateBody(&groundbd);

        glm::vec2 ground_size(8, 0.5);
        b2PolygonShape g_box;
        g_box.SetAsBox(ground_size.x, ground_size.y);
        ground->CreateFixture(&g_box, 0.0f);

        Sprite::LoadConfguration lc;
        lc.left_top = glm::vec2(-ground_size.x, ground_size.y);
        lc.right_bottom = glm::vec2(ground_size.x, -ground_size.y);
        lc.filter = GL_NEAREST;

        Ground.sprite.load("../resource/textures/desk.jpg", lc);
        Ground.transform.position = glm::vec2(ground->GetPosition().x, ground->GetPosition().y);

        glm::vec2 body_size(0.5, 0.5);
        lc.left_top = glm::vec2(-body_size.x, body_size.y);
        lc.right_bottom = glm::vec2(body_size.x, -body_size.y);

        glm::vec2 position(0);
        float ang = glm::radians(15.f);

        Texture t("../resource/textures/w7.png");

        for (int i = 1; i < objects.size(); i++)
        {
            objects[i].b.create(world.get(), position, ang, body_size);
            objects[i].m.sprite.load(lc, t);
            objects[i].updateTransform();
        }
        objects[0].b.create(world.get(), position, 0, body_size);
        objects[0].m.sprite.load(lc, t);
        objects[0].updateTransform();

        current = &objects[0];
        current->b.getBody()->SetFixedRotation(true);
    }
    void update() override
    {
        if (Input::getKeyPress(GLFW_KEY_ESCAPE))
            run_app = false;

        float speed = 0.1f;
        glm::vec2 vel(0, 0);
        if (Input::getKeyDown(GLFW_KEY_A))
            vel += (glm::vec2(-speed, 0));
        if (Input::getKeyDown(GLFW_KEY_D))
            vel += (glm::vec2(speed, 0));

        if (Input::getKeyPress(GLFW_KEY_SPACE))
            current->b.getBody()->ApplyForceToCenter(b2Vec2(0, 500), true);

        current->m.transform.position += vel;
        current->updateBoxTransform();
        current->b.getBody()->SetAwake(true);

        world->Step(1.0f / 60.0f, 10, 20);
        for (auto &o : objects)
        {
            o.updateTransform();
        }
    }
    void draw() override
    {
        Shader &shader = Shader::default_shader;
        shader.use();
        shader.setCamera(camera);
        Ground.draw();
        for (auto &o : objects)
        {
            o.m.draw();
        }
    }
    void cleanup() override {}
};