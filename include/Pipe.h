#ifndef PIPE_H
#define PIPE_H
#include <vector>
#include "raylib.h"

class Pipe {
public:
    static void Initialize();
    static void Update();
    static void Draw();
    static void Cleanup();


    std::vector<Vector2> GetPosition() const;

private:
    static std::vector<Vector2> pipes;
    static Vector2 position;
    static float velocity;
    static float minYPosition;
    static float maxYPosition;
    static float Randomizer(float,float);
};
#endif 