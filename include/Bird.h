#ifndef BIRD_H
#define BIRD_H

#include "raylib.h"

class Bird {
public:
    static void Initialize();
    static void Update();
    static void Draw ();
    static void Cleanup ();


private:
    static Vector2 position;
    static float velocity;
};


#endif