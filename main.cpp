#include <iostream>

#include "my_game.h"

int main()
{
    MyGame g;
    Application &app = g;
    return app.run();
}