#include "Ball.h"
#include "Pong.h"
#include "constants.h"
#include <iostream>
#include <ostream>
#include <raylib.h>
#include <raymath.h>

void handleCollision(Ball &ball1, Ball &ball2);

Pong leftPong = Pong(false, {120, 425, 10, 50}, {{0, 0}, 5, BLACK, 125, 425},
                     {{0, 0}, 5, BLACK, 125, 475}, 0);
Pong rightPong = Pong(true, {1470, 425, 10, 50}, {{0, 0}, 5, BLACK, 1475, 425},
                      {{0, 0}, 5, BLACK, 1475, 475}, 0);
Ball ball = Ball({500, 250}, 15, BLACK, constants::screenWidth / 2,
                 constants::screenHeight / 2);

int main() {

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(constants::screenWidth, constants::screenHeight, constants::title);
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  SetTargetFPS(60);

  RenderTexture2D renderTexture =
      LoadRenderTexture(constants::screenWidth, constants::screenHeight);
  SetTextureFilter(renderTexture.texture, TEXTURE_FILTER_BILINEAR);
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();

    if (IsKeyPressed(KEY_F)) {
      ToggleBorderlessWindowed();
    }
    if (IsKeyDown(KEY_W)) {
      leftPong.speed = -800;
    } else if (IsKeyDown(KEY_S)) {
      leftPong.speed = 800;
    } else {
      leftPong.speed = 0;
    }

    if (IsKeyDown(KEY_UP)) {
      rightPong.speed = -800;
    } else if (IsKeyDown(KEY_DOWN)) {
      rightPong.speed = 800;
    } else {
      rightPong.speed = 0;
    }

    if ((CheckCollisionCircleRec({ball.x, ball.y}, ball.radius,
                                 leftPong.rectangle))) {
      ball.speed.x *= -1.0;
    } else if (CheckCollisionCircles({ball.x, ball.y}, ball.radius,
                                     {leftPong.topBall.x, leftPong.topBall.y},
                                     leftPong.topBall.radius)) {
      handleCollision(leftPong.topBall, ball);

    } else if (CheckCollisionCircles(
                   {ball.x, ball.y}, ball.radius,
                   {leftPong.bottomBall.x, leftPong.bottomBall.y},
                   leftPong.bottomBall.radius)) {
      handleCollision(leftPong.bottomBall, ball);
    }

    if ((CheckCollisionCircleRec({ball.x, ball.y}, ball.radius,
                                 rightPong.rectangle))) {
      ball.speed.x *= -1.0f;
    } else if (CheckCollisionCircles({ball.x, ball.y}, ball.radius,
                                     {rightPong.topBall.x, rightPong.topBall.y},
                                     rightPong.topBall.radius)) {
      handleCollision(rightPong.topBall, ball);

    } else if (CheckCollisionCircles(
                   {ball.x, ball.y}, ball.radius,
                   {rightPong.bottomBall.x, rightPong.bottomBall.y},
                   rightPong.bottomBall.radius)) {
      handleCollision(rightPong.bottomBall, ball);
    }
    BeginTextureMode(renderTexture);
    ClearBackground(RAYWHITE);
    DrawRectangleLinesEx(constants::mainBox, 10, BLACK);

    ball.update(dt);
    leftPong.update(dt);
    rightPong.update(dt);
    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexturePro(renderTexture.texture,
                   Rectangle{0, 0,
                             static_cast<float>(renderTexture.texture.width),
                             -static_cast<float>(renderTexture.texture.height)},
                   Rectangle{0, 0, static_cast<float>(GetScreenWidth()),
                             static_cast<float>(GetScreenHeight())},
                   Vector2{0, 0}, 0, WHITE);
    EndDrawing();
  }
  UnloadRenderTexture(renderTexture);
  CloseWindow();
  return 0;
}
// FIX THIS
void handleCollision(Ball &ball1, Ball &ball2) {
  std::cout << "called" << std::endl;
  float distance = Vector2Distance(ball1.position, ball2.position);
  Vector2 impactLine = Vector2Subtract(ball1.position, ball2.position);
  Vector2 speedDifference = Vector2Subtract(ball1.speed, ball2.speed);
  float numerator = Vector2DotProduct(impactLine, speedDifference);
  float denominator = distance * distance;
  Vector2 speedChange = Vector2Scale(impactLine, numerator / denominator);
  Vector2 newSpeed = Vector2Add(ball2.speed, speedChange);
  std::cout << ball2.speed.x << " " << ball2.speed.y << std::endl;
  ball2.speed = newSpeed;
  std::cout << ball2.speed.x << " " << ball2.speed.y << std::endl;
}
