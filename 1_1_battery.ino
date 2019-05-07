
// TODO make a class for this so it can be drawn and have state

u8 batteryPrintCounter = 0;
void drawBatteryStatus(){
  batteryPrintCounter++;

  if( batteryPrintCounter > 100 ){ 
    batteryPrintCounter = 0;
  
    u8 percentage = (u8)(pocketstar.batteryLevel() * 100);
  
    pocketstar.setFont( pocketStar5pt );
    pocketstar.setFontColor( WHITE_16b, BLACK_16b );
    pocketstar.setCursor( 72, 0 );
    pocketstar.print( "   " );

    if( percentage == 100 ) {
      pocketstar.setCursor( 72, 0 );
    } else if( percentage >= 10 ) {
      pocketstar.setCursor( 76, 0 );
    } else {
      pocketstar.setCursor( 80, 0 );
    }
    pocketstar.print( percentage );
  
    pocketstar.setCursor( 84, 0 );
    pocketstar.print( "%" );
    
    pocketstar.setFont( pocketStarSymbols );
    pocketstar.setCursor( 90, 0 );
    if( pocketstar.isCharging() ) {
      pocketstar.print( "C" );
    } else {
      pocketstar.print( "D" );
    }
  }
};
