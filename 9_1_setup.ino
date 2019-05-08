
void initialize() {
  pocketstar.setBitDepth(BitDepth16);
  pocketstar.setColorMode(ColorModeRGB);
  pocketstar.setMirror(false);
};


boolean pause() {
  return true;
}

void resume() {
  // clear the screen
  pocketstar.drawRect( 0, 0, WIDTH, HEIGHT, true, BLACK_16b );
}
