

void setSelection( u8 selection ){
  cube.lastSelection = cube.selection;
  cube.selection = selection;
};

float timer = 0.0;
void update( float timeDiff ) {
 
  input.update( timeDiff );

  timer += timeDiff;

  if( optionsMenu.visible ){

    optionsMenu.update();
        
    if( timer > 1/30 ) {
      timer = 0.0;
      optionsMenu.draw();
    }
 
   } else {
    
    if( input.get( buttons::a ) ) {
      cube.rotate( cube.selection, directions::clockWise );
    } else if( input.get( buttons::b ) ) {
      cube.rotate( cube.selection, directions::counterClockWise );
    }
  
  
    if( cube.selection == faces::left || cube.selection == faces::front || cube.selection == faces::right || cube.selection == faces::back ) {
      // selected face:   (-> ... means repeat sequence)
      // up/down      
      //   center -> top -> bottom -> ...
      if( input.get( buttons::up ) ) {
        setSelection( faces::top );
      } else if( input.get( buttons::down ) ) {
        setSelection( faces::bottom );
      }
  
      // right/left
      //   top -> ... (ignore)
      //   left -> front -> right -> back -> ...
      //   bottom -> ... (ignore)
      else if( cube.selection == faces::front ) {
        if( input.get( buttons::right ) ) {
          setSelection( faces::right );
        } else if( input.get( buttons::left ) ) {
          setSelection( faces::left );
        }
      }
      else if( cube.selection == faces::right ) {
        if( input.get( buttons::right ) ) {
          setSelection( faces::back );
        } else if( input.get( buttons::left ) ) {
          setSelection( faces::front );
        }
      }
      else if( cube.selection == faces::back ) {
        if( input.get( buttons::right ) ) {
          setSelection( faces::left );
        } else if( input.get( buttons::left ) ) {
          setSelection( faces::right );
        }
      }
      else if( cube.selection == faces::left ) {
        if( input.get( buttons::right ) ) {
          setSelection( faces::front );
        } else if( input.get( buttons::left ) ) {
          setSelection( faces::back );
        }
      }
    }
    else if( cube.selection == faces::top ) {
      if( input.get( buttons::up ) ) {
        setSelection( faces::bottom );
      } else if( input.get( buttons::down ) ) {
        setSelection( faces::front );
      }
      if( input.get( buttons::right ) ) {
        setSelection( faces::right );
      } else if( input.get( buttons::left ) ) {
        setSelection( faces::left );
      }
    }
    else if( cube.selection == faces::bottom ) {
      if( input.get( buttons::up ) ) {
        setSelection( faces::front );
      } else if( input.get( buttons::down ) ) {
        setSelection( faces::top );
      }
      if( input.get( buttons::right ) ) {
        setSelection( faces::right );
      } else if( input.get( buttons::left ) ) {
        setSelection( faces::left );
      }
    }
  
    if( timer > 1/30 ) {
      cube.draw();
    }
    
    if( optionsMenu.showBattery ){
      drawBatteryStatus();
    }
  }

};
