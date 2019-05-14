#include <PocketStar.h>

#define WIDTH 96
#define HEIGHT 64

#define i8  int8_t
#define i16 int16_t
#define u8  uint8_t
#define u16 uint16_t


typedef void (* Callback) ();

namespace buttons {
  enum buttons {
    up, down, right, left,
    a, b
  };
};

#define DEBOUNCE_UP    0.2
#define DEBOUNCE_DOWN  0.2
#define DEBOUNCE_RIGHT 0.2
#define DEBOUNCE_LEFT  0.2
#define DEBOUNCE_A     0.2
#define DEBOUNCE_B     0.2


namespace faces {
  enum faces {
    top, bottom, 
    right, left,
    front, back
  };
};

namespace directions {
  enum directions {
    clockWise, 
    counterClockWise
  };
};


u8 drawLocations[6][2] = {
  { 30, 5  },         // top
  { 30, 41 },         // bottom
  { 48, 23 },         // right
  { 12, 23 },         // left
  { 30, 23 },         // front
  { 66, 23 },         // back
};

u16 faceColors[6] = {
  WHITE_16b,          // top
  YELLOW_16b,         // bottom
  RED_16b,            // right
  ORANGE_16b,         // left
  GREEN_16b,          // front
  BLUE_16b,           // back
};
