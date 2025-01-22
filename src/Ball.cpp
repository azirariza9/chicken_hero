#include "Ball.h"

Ball::Ball(const Pipe &pipe, float offsetX, float offsetY)
    : associatedPipe(pipe),relativeOffset({offsetX,offsetY}){

    }

