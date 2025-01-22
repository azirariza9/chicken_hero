#ifndef BALL_H
#define BALL_H
#include "raylib.h"
#include "Pipe.h"

class Ball
{
public:
    Ball(const Pipe &pipe,float offsetX, float offsetY);
    void Initialize();
    void Update();
    void Draw();

private:
    const Pipe &associatedPipe;
    Vector2 relativeOffset;
    Vector2 position;

};




#endif //BALL_H