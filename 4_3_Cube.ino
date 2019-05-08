class Cube {
  bool changed = true;
  Face sides[6] = { Face(0), Face(1), Face(2), Face(3), Face(4), Face(5) };
public:
  Cube();
  u8 selection = faces::front;
  u8 lastSelection  = faces::front;
  bool draw();
  void rotate( u8 face, u8 direction );
};

Cube::Cube(){};
bool Cube::draw() {
  if( lastSelection  != selection || changed ) {
    pocketstar.drawRect( 0, 0, WIDTH, HEIGHT, true, BLACK_16b );
    pocketstar.drawRect(
      drawLocations[ selection ][0] - 1,
      drawLocations[ selection ][1] - 1,
      19, 19, true, GRAY_16b );

    for( u8 i = 0; i < 6; i++ ){
      sides[ i ].draw( drawLocations[i][0], drawLocations[i][1] );
    }
    changed = false;
    lastSelection = selection;
  }
};

void Cube::rotate( u8 face, u8 direction ){
  changed = true;
  Row temp;
  switch( face ) {
    case faces::top:
      temp = sides[ faces::front ].getRow( 0 );
      if( direction == directions::clockWise ) {
        sides[ faces::front ].setRow( 0, sides[ faces::right ].getRow( 0 ).get() );
        sides[ faces::right ].setRow( 0, sides[ faces::back  ].getRow( 0 ).get() );
        sides[ faces::back  ].setRow( 0, sides[ faces::left  ].getRow( 0 ).get() );
        sides[ faces::left  ].setRow( 0, temp.get() );
      } else {
        sides[ faces::front ].setRow( 0, sides[ faces::left  ].getRow( 0 ).get() );
        sides[ faces::left  ].setRow( 0, sides[ faces::back  ].getRow( 0 ).get() );
        sides[ faces::back  ].setRow( 0, sides[ faces::right ].getRow( 0 ).get() );
        sides[ faces::right ].setRow( 0, temp.get() );
      }
      sides[ faces::top ].rotate( direction );
      break;
      
    case faces::bottom:
      temp = sides[ faces::front ].getRow( 2 );
      if( direction == directions::clockWise ) {
        sides[ faces::front ].setRow( 2, sides[ faces::left  ].getRow( 2 ).get() );
        sides[ faces::left  ].setRow( 2, sides[ faces::back  ].getRow( 2 ).get() );
        sides[ faces::back  ].setRow( 2, sides[ faces::right ].getRow( 2 ).get() );
        sides[ faces::right ].setRow( 2, temp.get() );
      } else {
        sides[ faces::front ].setRow( 2, sides[ faces::right ].getRow( 2 ).get() );
        sides[ faces::right ].setRow( 2, sides[ faces::back  ].getRow( 2 ).get() );
        sides[ faces::back  ].setRow( 2, sides[ faces::left  ].getRow( 2 ).get() );
        sides[ faces::left  ].setRow( 2, temp.get() );
      }
      sides[ faces::bottom ].rotate( direction );
      break;
      
    case faces::left:
      temp = sides[ faces::top ].getCol( 0 );
      if( direction == directions::clockWise ) {
        sides[ faces::top    ].setCol( 0, sides[ faces::back   ].getCol( 2 ).getReverse() );
        sides[ faces::back   ].setCol( 2, sides[ faces::bottom ].getCol( 0 ).getReverse() );
        sides[ faces::bottom ].setCol( 0, sides[ faces::front  ].getCol( 0 ).get() );
        sides[ faces::front  ].setCol( 0, temp.get() );
      } else {
        sides[ faces::top    ].setCol( 0, sides[ faces::front  ].getCol( 0 ).get() );
        sides[ faces::front  ].setCol( 0, sides[ faces::bottom ].getCol( 0 ).get() );
        sides[ faces::bottom ].setCol( 0, sides[ faces::back   ].getCol( 2 ).getReverse() );
        sides[ faces::back   ].setCol( 2, temp.getReverse() );
      }
      sides[ faces::left ].rotate( direction );
      break;
      
    case faces::right:
      temp = sides[ faces::top ].getCol( 2 );
      if( direction == directions::clockWise ) {
        sides[ faces::top    ].setCol( 2, sides[ faces::front  ].getCol( 2 ).get() );
        sides[ faces::front  ].setCol( 2, sides[ faces::bottom ].getCol( 2 ).get() );
        sides[ faces::bottom ].setCol( 2, sides[ faces::back   ].getCol( 0 ).getReverse() );
        sides[ faces::back   ].setCol( 0, temp.getReverse() );
      } else {
        sides[ faces::top    ].setCol( 2, sides[ faces::back   ].getCol( 0 ).getReverse() );
        sides[ faces::back   ].setCol( 0, sides[ faces::bottom ].getCol( 2 ).getReverse() );
        sides[ faces::bottom ].setCol( 2, sides[ faces::front  ].getCol( 2 ).get() );
        sides[ faces::front  ].setCol( 2, temp.get() );
      }
      sides[ faces::right ].rotate( direction );
      break;

    case faces::front:
      temp = sides[ faces::top ].getRow( 2 );
      if( direction == directions::clockWise ) {
        sides[ faces::top    ].setRow( 2, sides[ faces::left   ].getCol( 2 ).getReverse() );
        sides[ faces::left   ].setCol( 2, sides[ faces::bottom ].getRow( 0 ).get() );
        sides[ faces::bottom ].setRow( 0, sides[ faces::right  ].getCol( 0 ).getReverse() );
        sides[ faces::right  ].setCol( 0, temp.get() );
      } else {
        sides[ faces::top    ].setRow( 2, sides[ faces::right  ].getCol( 0 ).get() );
        sides[ faces::right  ].setCol( 0, sides[ faces::bottom ].getRow( 0 ).getReverse() );
        sides[ faces::bottom ].setRow( 0, sides[ faces::left   ].getCol( 2 ).get() );
        sides[ faces::left   ].setCol( 2, temp.getReverse() );
      }
      sides[ faces::front ].rotate( direction );
      break;
      
    case faces::back:
      temp = sides[ faces::top ].getRow( 0 );
      if( direction == directions::clockWise ) {
        sides[ faces::top    ].setRow( 0, sides[ faces::right  ].getCol( 2 ).get() );
        sides[ faces::right  ].setCol( 2, sides[ faces::bottom ].getRow( 2 ).getReverse() );
        sides[ faces::bottom ].setRow( 2, sides[ faces::left   ].getCol( 0 ).get() );
        sides[ faces::left   ].setCol( 0, temp.getReverse() );
      } else {
        sides[ faces::top    ].setRow( 0, sides[ faces::left   ].getCol( 0 ).getReverse() );
        sides[ faces::left   ].setCol( 0, sides[ faces::bottom ].getRow( 2 ).get() );
        sides[ faces::bottom ].setRow( 2, sides[ faces::right  ].getCol( 2 ).getReverse() );
        sides[ faces::right  ].setCol( 2, temp.get() );
      }
      sides[ faces::back ].rotate( direction );
      break;
  }
};

Cube cube;
