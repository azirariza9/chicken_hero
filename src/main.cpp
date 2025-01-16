#include "raylib.h"
int main ()
{
    GameInit();

    while (!WindowShouldClose())
    {
        GameUpdate();
        GameDraw();
    }
    GameCleanup();
    return 0;
}