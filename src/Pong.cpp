#include "Pong.h"
#include "Ball.h"
#include "constants.h"
#include <iostream>
#include <raylib.h>

Pong::Pong(bool isRight, Rectangle rect, Ball topBall, Ball bottomBall,
           float speed)
    : isRight(isRight), rectangle{rect}, topBall{topBall},
      bottomBall{bottomBall}, x(rectangle.x), y(rectangle.y), speed(speed) {}

void Pong::update(float deltaTime) {
  if (topBall.y - topBall.radius <= constants::mainBox.y) {
    std::cout << this->topBall.y - this->topBall.radius << std::endl;
    this->y = constants::mainBox.y + (2 * topBall.radius) + 20;
  }
  if (bottomBall.y + bottomBall.radius >=
      constants::mainBox.y + constants::mainBox.height) {
    this->y = constants::mainBox.y + constants::mainBox.height -
              (4 * this->bottomBall.radius) - this->rectangle.height;
  }
  this->y += this->speed * deltaTime;

  rectangle.y = this->y;
  topBall.y = rectangle.y;
  bottomBall.y = rectangle.y + rectangle.height;
  topBall.update(deltaTime, {0, 0});
  bottomBall.update(deltaTime, {0, 0});

  DrawRectangleRec(rectangle, BLACK);
}
