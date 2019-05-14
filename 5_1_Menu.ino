namespace menu {
  enum menu {
    resumeGame,
    newGame,
    showBatteryOption
  };
};

class Menu {
public:
  u8 selection = 1;
  u8 lastSelection = 1;
  bool changed = true;
  bool visible = true;
  bool exitOption = false;
  bool showBattery = false;
  void update();
  void draw();
  void setSelection( u8 sel );
};

void Menu::setSelection( u8 sel ){
  lastSelection = selection;
  selection = sel;
  changed = true;
};
void Menu::draw(){
  char* headerText = "Rubiks Cube";
  char* resumeGameText = "Resume game";
  char* newGameText = "New game";
  char* showBatteryText = "Show battery";
  char* hideBatteryText = "Hide battery";

  pocketstar.setFontColor( WHITE_16b, BLACK_16b );
  pocketstar.setFont( pocketStar7pt );
  pocketstar.setCursor( (WIDTH - pocketstar.getPrintWidth( headerText )) / 2, 4 );
  pocketstar.print( headerText );
    
  pocketstar.setCursor( (WIDTH - pocketstar.getPrintWidth( resumeGameText )) / 2, 22 );
  pocketstar.print( resumeGameText );

  pocketstar.setCursor( (WIDTH - pocketstar.getPrintWidth( newGameText )) / 2, 34 );
  pocketstar.print( newGameText );

  if( showBattery ) {
    pocketstar.setCursor( (WIDTH - pocketstar.getPrintWidth( hideBatteryText )) / 2, 46 );
    pocketstar.print( hideBatteryText );
  } else {
    pocketstar.setCursor( (WIDTH - pocketstar.getPrintWidth( showBatteryText )) / 2, 46 );
    pocketstar.print( showBatteryText );
  }
  

  u8 x;
  u8 w;
    
  if( changed ) {
    changed = false;
    switch( lastSelection ) {
      case menu::resumeGame:
        w = pocketstar.getPrintWidth( resumeGameText );
        x = (WIDTH - w) / 2;
        pocketstar.drawRect( x - 1, 21, w + 3, 12, false, BLACK_16b );
        break;
      case menu::newGame:
        w = pocketstar.getPrintWidth( newGameText );
        x = (WIDTH - w) / 2;
        pocketstar.drawRect( x - 1, 33, w + 3, 12, false, BLACK_16b );
        break;
      case menu::showBatteryOption:
        w = pocketstar.getPrintWidth( showBatteryText );
        x = (WIDTH - w) / 2;
        pocketstar.drawRect( x - 1, 45, w + 3, 12, false, BLACK_16b );
        break;
    };
  }
    
  switch( selection ) {
    case menu::resumeGame:
      w = pocketstar.getPrintWidth( resumeGameText );
      x = (WIDTH - w) / 2;
      pocketstar.drawRect( x - 1, 21, w + 3, 12, false, YELLOW_16b );
      break;
    case menu::newGame:
      w = pocketstar.getPrintWidth( newGameText );
      x = (WIDTH - w) / 2;
      pocketstar.drawRect( x - 1, 33, w + 3, 12, false, YELLOW_16b );
      break;
    case menu::showBatteryOption:
      w = pocketstar.getPrintWidth( showBatteryText );
      x = (WIDTH - w) / 2;
      pocketstar.drawRect( x - 1, 45, w + 3, 12, false, YELLOW_16b );
      break;
  };
};


void Menu::update(){
  if( input.get(buttons::up) ){
    if( selection == menu::newGame ) {
      setSelection( menu::resumeGame );
    } else if( selection == menu::showBatteryOption ) {
      setSelection( menu::newGame );
    } else {
      setSelection( menu::showBatteryOption );
    }
  }
  else if( input.get(buttons::down) ){
    if( selection == menu::resumeGame ) {
      setSelection( menu::newGame );
    } else if( selection == menu::newGame ) {
      setSelection( menu::showBatteryOption );
    } else {
      setSelection( menu::resumeGame );
    }
  }

  if( input.get(buttons::b) ){
    visible = true;
  }
  
  if( input.get(buttons::a) && !exitOption ){
    if( selection == menu::resumeGame) {
      visible = false;
      cube.changed = true;
    } else if( selection == menu::newGame) {
      cube = Cube();
      visible = false;
    } else if( selection == menu::showBatteryOption) {
      showBattery = !showBattery;
    }
  }
};


Menu optionsMenu;
