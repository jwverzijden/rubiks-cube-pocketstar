class Face {
  u8 face;
  u8 slots[3][3];
public:
  Face( u8 _face );
  void setCol( u8 col, u8* newItems );
  void setRow( u8 row, u8* newItems );
  void draw( u8 x, u8 y );
  Row getCol( u8 col );
  Row getRow( u8 row );
  void rotate( u8 direction );
};
Face::Face( u8 _face ){
  face = _face;
  for( u8 y = 0; y < 3; y++ ){
    for( u8 x = 0; x < 3; x++ ){
      slots[y][x] = face;
    }
  }
};
void Face::draw( u8 _x, u8 _y ){
  // for slots draw slot in its color
  for( u8 y = 0; y < 3; y++ ) {
    for( u8 x = 0; x < 3; x++ ) {
      pocketstar.drawRect( _x + (x*6), _y + (y*6), 5, 5, true, faceColors[ slots[ y ][ x ] ] );
    }
  }
};
void Face::setCol( u8 col, u8* newItems ){
  for( u8 i = 0; i < 3; i++ ) {
    slots[i][col] = newItems[i];
  }
};
void Face::setRow( u8 row, u8* newItems ){
  for( u8 i = 0; i < 3; i++ ) {
    slots[row][i] = newItems[i];
  }
};
Row Face::getCol( u8 col ){
  u8 c[3] = { slots[0][col], slots[1][col], slots[2][col] };
  Row _col ( c );
  return _col;
};
Row Face::getRow( u8 row ){
  u8 r[3] = { slots[row][0], slots[row][1], slots[row][2] };
  Row _row ( r );
  return _row;
};
void Face::rotate( u8 direction ){
  if( direction == directions::clockWise ) {
    Row temp0 ( getRow( 0 ) );
    Row temp1 ( getRow( 1 ) );
    Row temp2 ( getRow( 2 ) );
    setCol( 2, temp0.get() );
    setCol( 1, temp1.get() );
    setCol( 0, temp2.get() );
  } else {
    Row temp0 ( getRow( 0 ) );
    Row temp1 ( getRow( 1 ) );
    Row temp2 ( getRow( 2 ) );
    setCol( 0, temp0.getReverse() );
    setCol( 1, temp1.getReverse() );
    setCol( 2, temp2.getReverse() );
  }
};
