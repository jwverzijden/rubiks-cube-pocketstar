
void initialize() {
  pocketstar.setBitDepth(BitDepth16);
  pocketstar.setColorMode(ColorModeRGB);
  pocketstar.setMirror(false);
};


boolean pause() {
  if( optionsMenu.visible ) {
    return true;
  }
  pocketstar.drawRect( 0, 0, WIDTH, HEIGHT, true, BLACK_16b );
  optionsMenu.setSelection( menu::resumeGame );
  optionsMenu.visible = true;
  return false;
}

void resume() {
  // clear the screen
  pocketstar.drawRect( 0, 0, WIDTH, HEIGHT, true, BLACK_16b );
}
