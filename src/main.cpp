#include <Arduino.h>
#include "GameBoyFixVal.h"
#include "blocks.h"
GameBoy gb;
void setup() {  gb.begin(0); }

void loop() {
  gb.clearDisplay();
  for (uint8_t y = 0; y < 8; y++) {
    for (uint8_t x = 0; x < 8; x++) {
      if (Z_Block_1[y][x]) {
        gb.drawPoint(x, y);
      }
    }
  }
  
  delay(500);
  gb.clearDisplay();
  for (uint8_t y = 0; y < 8; y++) {
    for (uint8_t x = 0; x < 8; x++) {
      if (Z_Block_1[y][x]) {
        gb.drawPoint(x, y);
      }
    }
  }
  delay(500);
}