#ifndef Ball_h
#define Ball_h

#include <raylib.h>

class Ball {
public:
  Ball(Vector2 speed, float radius, Color color, float x, float y);

  Ball(Ball &&) = default;
  Ball(const Ball &) = default;
  Ball &operator=(Ball &&) = default;
  Ball &operator=(const Ball &) = default;
  ~Ball() = default;

  void update(float deltaTime);
  void update(float deltaTime, Vector2 speed);

  Vector2 speed;
  float radius;
  Color color;
  float x, y;
  Vector2 position;
};

#endif // !Ball_h
