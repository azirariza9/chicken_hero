#include "Bird.h"

void Bird::Initialize(){
    position = {static_cast<float>(GetScreenWidth())*0.3f,
                static_cast<float>(GetScreenHeight())*0.5f};
    velocity = 0;
}