#include "GameInit.h"
#include "Bird.h"
#include "Pipe.h"
#include "Ball.h"

void GameInit(){
    InitWindow(432,768,"example");
    Bird::Initialize();
    Pipe::Initialize();
    Ball::Initialize();
}