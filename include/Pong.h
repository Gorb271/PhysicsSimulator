#ifndef Pong_h
#define Pong_h

#include "Ball.h"
#include <raylib.h>

class Pong {
public:
  Pong(bool isRight, Rectangle rectangle, Ball topBall, Ball bottomBall,
       float speed);

  Pong(Pong &&) = default;
  Pong(const Pong &) = default;
  Pong &operator=(Pong &&) = delete;
  Pong &operator=(const Pong &) = delete;
  ~Pong() = default;

  void update(float deltaTime);

  bool isRight{};
  Rectangle rectangle;
  Ball topBall;
  Ball bottomBall;
  float x, y;
  float speed;
};

#endif // !Pong_h
