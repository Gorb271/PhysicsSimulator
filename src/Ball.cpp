#include "Ball.h"
#include "constants.h"
#include <raylib.h>

Ball::Ball(Vector2 speed, float radius, Color color, float x, float y)
    : speed(speed), radius(radius), color(color), x(x), y(y), position({x, y}) {
}

void Ball::update(float deltaTime) {
  if (this->x >=
          constants::mainBox.x + constants::mainBox.width - this->radius - 10 ||
      this->x <= constants::mainBox.x + this->radius + 10) {
    this->x = constants::screenWidth / 2;
    this->y = constants::screenHeight / 2;
    this->speed = {-700, 500};
  }
  if (this->y >= constants::mainBox.y + constants::mainBox.height -
                     this->radius - 10 ||
      this->y <= constants::mainBox.y + this->radius + 10) {
    this->speed.y *= -1.0f;
  }
  this->x += this->speed.x * deltaTime;
  this->y += this->speed.y * deltaTime;
  DrawCircle(this->x, this->y, this->radius, this->color);
}
void Ball::update(float deltaTime, Vector2 speed) {
  this->speed = speed;
  update(deltaTime);
}
