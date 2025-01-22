#include "Pipe.h"
#include <random>
#include <math.h>

std::vector<Vector2> Pipe::GetPosition() const{
    return pipes;
}
float Pipe::Randomizer(float pipeMinY,float pipeMaxY){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution <float> distr(pipeMinY,pipeMaxY);
    position.y = roundf(position.y*100)/100;
    return position.y;
}


void Pipe::Initialize(){
    velocity = -4.0f;
    minYPosition = static_cast<float>(GetScreenHeight()) *0.5f;
    maxYPosition = static_cast<float>(GetScreenHeight()) *0.8f;
    position.x = static_cast<float>(GetScreenWidth())*1.1f;
    position.y = Pipe::Randomizer(minYPosition,maxYPosition);
    pipes.push_back(position);
}