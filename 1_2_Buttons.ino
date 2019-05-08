class Buttons {
  float debounceTimes[6];
  float time;
public:
  bool value[6];
  void update( float timeDiff );
  bool get( u8 button );
};

void Buttons::update( float timeDiff ){
  time += timeDiff;
  value[buttons::up]    = false;
  value[buttons::down]  = false;
  value[buttons::left]  = false;
  value[buttons::right] = false;
  value[buttons::a]     = false;
  value[buttons::b]     = false;

  u8 btns = pocketstar.getButtons();
  if( btns & ButtonUp && time > debounceTimes[buttons::up] ){
    debounceTimes[buttons::up] = time + DEBOUNCE_UP;
    value[buttons::up] = true;
  }
  if( btns & ButtonDown && time > debounceTimes[buttons::down] ){
    debounceTimes[buttons::down] = time + DEBOUNCE_DOWN;
    value[buttons::down] = true;
  }
  if( btns & ButtonLeft && time > debounceTimes[buttons::left] ){
    debounceTimes[buttons::left] = time + DEBOUNCE_LEFT;
    value[buttons::left] = true;
  }
  if( btns & ButtonRight && time > debounceTimes[buttons::right] ){
    debounceTimes[buttons::right] = time + DEBOUNCE_RIGHT;
    value[buttons::right] = true;
  }
  if( btns & ButtonA && time > debounceTimes[buttons::a] ){
    debounceTimes[buttons::a] = time + DEBOUNCE_A;
    value[buttons::a] = true;
  }
  if( btns & ButtonB && time > debounceTimes[buttons::b] ){
    debounceTimes[buttons::b] = time + DEBOUNCE_B;
    value[buttons::b] = true;
  }  
};

bool Buttons::get( u8 button ){
  switch( button ) {
    case buttons::up:    return value[buttons::up];
    case buttons::down:  return value[buttons::down];
    case buttons::left:  return value[buttons::left];
    case buttons::right: return value[buttons::right];
    case buttons::a:     return value[buttons::a];
    case buttons::b:     return value[buttons::b];
    default:             return false;
  }
};


Buttons input;
