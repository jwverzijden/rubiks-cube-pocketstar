void drawFramerate( float diff ){
  float framerate = 1 / diff;
  pocketstar.setFont( pocketStar5pt );
  pocketstar.setFontColor( WHITE_16b, BLACK_16b );
  pocketstar.setCursor( 72, 7 );
  pocketstar.print( framerate );
  pocketstar.print( "   " );
};
