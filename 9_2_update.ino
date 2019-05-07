
void update( float timeDiff ) {
 
  input.update( timeDiff );

  if( input.get( buttons::a ) ) {
    cube.rotate( cube.selection, directions::clockWise );
  } else if( input.get( buttons::b ) ) {
    cube.rotate( cube.selection, directions::counterClockWise );
  }

  // selected face:   (-> ... means repeat sequence)
  // up/down      
  //   center -> top -> bottom -> ...

  if( cube.selection == faces::left || cube.selection == faces::front || cube.selection == faces::right || cube.selection == faces::back ) {
    if( input.get( buttons::up ) ) {
      cube.lastSelection = cube.selection;
      cube.selection = faces::top;
    } else if( input.get( buttons::down ) ) {
      cube.lastSelection = cube.selection;
      cube.selection = faces::bottom;
    }
    
  // right/left
  //   top -> ... (ignore)
  //   left -> front -> right -> back -> ...
  //   bottom -> ... (ignore)

    else if( cube.selection == faces::front ) {
      if( input.get( buttons::right ) ) {
        cube.lastSelection = cube.selection;
        cube.selection = faces::right;
      } else if( input.get( buttons::left ) ) {
        cube.lastSelection = cube.selection;
        cube.selection = faces::left;
      }
    }
    else if( cube.selection == faces::right ) {
      if( input.get( buttons::right ) ) {
        cube.lastSelection = cube.selection;
        cube.selection = faces::back;
      } else if( input.get( buttons::left ) ) {
        cube.lastSelection = cube.selection;
        cube.selection = faces::front;
      }
    }
    else if( cube.selection == faces::back ) {
      if( input.get( buttons::right ) ) {
        cube.lastSelection = cube.selection;
        cube.selection = faces::left;
      } else if( input.get( buttons::left ) ) {
        cube.lastSelection = cube.selection;
        cube.selection = faces::right;
      }
    }
    else if( cube.selection == faces::left ) {
      if( input.get( buttons::right ) ) {
        cube.lastSelection = cube.selection;
        cube.selection = faces::front;
      } else if( input.get( buttons::left ) ) {
        cube.lastSelection = cube.selection;
        cube.selection = faces::back;
      }
    }
  }
  else if( cube.selection == faces::top ) {
    if( input.get( buttons::up ) ) {
      cube.lastSelection = cube.selection;
      cube.selection = faces::bottom;
    } else if( input.get( buttons::down ) ) {
      cube.lastSelection = cube.selection;
      cube.selection = faces::front;
    }
  }
  else if( cube.selection == faces::bottom ) {
    if( input.get( buttons::up ) ) {
      cube.lastSelection = cube.selection;
      cube.selection = faces::front;
    } else if( input.get( buttons::down ) ) {
      cube.lastSelection = cube.selection;
      cube.selection = faces::top;
    }
  }

  drawBatteryStatus();
//  drawFramerate( timeDiff );
  cube.draw();


};
