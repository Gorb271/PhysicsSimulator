#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <raylib.h>

namespace constants {

const int screenWidth = 1600;
const int screenHeight = 900;
const char *const title = "Pong";
const Rectangle mainBox{static_cast<float>(screenWidth) / 16,
                        static_cast<float>(screenHeight) / 16,
                        14 * static_cast<float>(screenWidth) / 16,
                        14 * static_cast<float>(screenHeight) / 16};
} // namespace constants

#endif // !CONSTANTS_H
