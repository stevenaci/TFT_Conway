#include <WiFi.h>
#include <ArduinoOTA.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <Bitmap.h>
#include <Conway.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

const int WIDTH = tft.height();
const int HEIGHT = tft.width();
const int SCALE = 3;
/* Conway's Game of Life Simulation */
Conway conway(WIDTH/ SCALE, HEIGHT/ SCALE);
/* A cool scalable bitmap */
Bitmap bitmap(WIDTH, HEIGHT, SCALE);

void setup(void) {
  tft.init();
  tft.setRotation(45);
}

void loop(void) {
  /* Update the game and bitmap*/
  conway.nextFrame();
  bitmap.updateBitmap(conway.cells);
  /* Draw */
  tft.fillScreen(TFT_VIOLET);
  tft.drawBitmap(0,0, &bitmap.bitmap[0], WIDTH, HEIGHT, TFT_GOLD);
}