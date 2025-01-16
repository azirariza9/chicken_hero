#include "raylib.h"
#include <random>
#include <math.h>
#include <iostream>
#include <vector>


int main (void)
{
    const int screenWidth = 432;
    const int screenHeight = 768;
    const float chickenInitWidth = screenWidth*0.3f;
    const float chickenInitHeight = screenHeight/2;
    float chickenWidth = chickenInitWidth;
    float chickenHeight = chickenInitHeight;
    const float chickenColRadius = 21.0f;
    int chickenColWidth;
    int chickenColHeight; 
    const float gravityForce = 0.5f;
    const float flyPower = -10.0f;
    float chickenVelocity;

    

    
    // const int chickenWidth
    

    InitWindow(screenWidth, screenHeight, "example");

    SetTargetFPS(60);

    Texture2D backgroundDay = LoadTexture ("assets/sprites/background_day.png"); 
    Texture2D chickenHero = LoadTexture ("assets/sprites/bird_red_0.png");
    Texture2D groundSprite = LoadTexture ("assets/sprites/ground.png");
    Texture2D pipeSprite = LoadTexture ("assets/sprites/pipe_green_bottom.png");

    const float groundHeight = screenHeight-static_cast<float>(groundSprite.height)*1.5f;
    
    const float initPipeWidth = static_cast<float>(screenWidth)*1.1f;
    float pipeWidth = initPipeWidth;
    float pipeVelocity = -4.0f;
    const float pipeMinFloat = static_cast<float>(screenHeight) * 0.5f;
    const float pipeMaxFloat = static_cast<float>(screenHeight) * 0.8f;
    float pipeRandomFloatPrecise;

    std::vector<Vector2> pipesVector;
    bool newPipeTime = true;


    std::random_device rd;

    while (!WindowShouldClose())
    {
        if(newPipeTime == true) {
            std::mt19937 gen(rd());
            std::uniform_real_distribution <float> distr(pipeMinFloat,pipeMaxFloat);
            float pipeRandomFloat= distr(gen);
            pipeRandomFloatPrecise = roundf(pipeRandomFloat*100)/100;
            newPipeTime = false ;  
            pipesVector.push_back((Vector2){pipeWidth,pipeRandomFloatPrecise}); 
        }
        
        


        chickenColWidth = static_cast<int>(chickenWidth) + 25;
        chickenColHeight = static_cast<int> (chickenHeight) + 19;
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            DrawTextureEx(backgroundDay,(Vector2){0,0},0.0f,3.0f,WHITE);
            DrawCircle(chickenColWidth,chickenColHeight,chickenColRadius,BLUE);
            
            DrawTextureEx(chickenHero,(Vector2){chickenWidth,chickenHeight},0.0f,3.0f,WHITE);            
            DrawTextureEx(groundSprite,(Vector2){0,groundHeight},0.0f,2.0f,WHITE);
            DrawTextureEx(groundSprite,(Vector2){static_cast<float>(groundSprite.width),groundHeight},0.0f,2.0f,WHITE);
            for (const Vector2& pipeElement : pipesVector) {
                DrawCircleV((Vector2){pipeElement.x+static_cast<float>(pipeSprite.width),pipeElement.y-static_cast<float>(pipeSprite.width)*2.0f},chickenColRadius,BLACK);
                DrawTextureEx(pipeSprite,pipeElement,0.0f,2.0f,WHITE);
                DrawRectangleV(pipeElement,(Vector2){static_cast<float>(pipeSprite.width)*2.0f,static_cast<float>(pipeSprite.height)*2.0f},RED);}
            DrawRectangle(0,static_cast<int>(groundHeight),screenWidth,static_cast<int>(groundSprite.height*2),BLUE);
            

        EndDrawing();

        chickenVelocity += gravityForce;
        chickenHeight += chickenVelocity;
        for (Vector2& pipeElement : pipesVector) {
            pipeElement.x += pipeVelocity;    
        }

        if (pipesVector.back().x <= static_cast<float>(screenWidth)*0.4f)
            newPipeTime = true;
        
        if (pipesVector.front().x <= static_cast<float>(-screenWidth))
            pipesVector.erase(pipesVector.begin());

    

        if (IsKeyPressed(KEY_SPACE)) chickenVelocity = flyPower;
    }

    UnloadTexture(backgroundDay);
    UnloadTexture(chickenHero);
    UnloadTexture(groundSprite);
    UnloadTexture(pipeSprite);
    CloseWindow();
    return 0;
}