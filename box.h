#pragma once

#include "include/box2d/box2d.h"
#include <glm/glm.hpp>

class Box
{
private:
    b2Body *body;
    b2Fixture *fixture;

public:
    b2Body *getBody() const { return body; }
    b2Fixture *getFixture() const { return fixture; }

    void create(b2World *world, glm::vec2 pos, float angle, glm::vec2 size_half)
    {
        b2BodyDef bdef;
        bdef.type = b2_dynamicBody;
        bdef.position.Set(pos.x, pos.y);
        bdef.angle = angle;

        body = world->CreateBody(&bdef);

        b2PolygonShape shape;
        shape.SetAsBox(size_half.x, size_half.y);

        b2FixtureDef fdef;
        fdef.shape = &shape;
        fdef.density = 1.0f;
        fdef.friction = 0.3f;

        fixture = body->CreateFixture(&fdef);
    }
};