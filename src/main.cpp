#include <Arduino.h>
#include <GameBoyFixVal.h>
GameBoy gb;

int dotX[50];                  //✅
int dotY[50];                  //✅
int dotCount = 1;              //✅
void setup() {  
  gb.begin(0);
  randomSeed(analogRead(0));   
  dotX[0] = random(0, 8);      //✅
  dotY[0] = random(0, 16);     //✅
}
int x = 1, y = 0;
int dirX = 3, dirY = 7; 
void makeMove(){
  if(gb.getKey() == 4){  x = -1;  y = 0;  }
  if(gb.getKey() == 5){  x = 1;   y = 0;  } 
  if(gb.getKey() == 6){  x = 0;   y = 1;  }
  if(gb.getKey() == 3){  x = 0;   y = -1; }
}
void loop() { 
  makeMove();
  dirX = dirX + x;
  dirY = dirY + y;
  if (dirX > 7) { dirX = 0; }
  if (dirX < 0) { dirX = 7; }
  if (dirY > 15) { dirY = 0; }
  if (dirY < 0) { dirY = 15; }

  for (int i = 0; i < dotCount; i = i + 1) {                  //✅
    if (dirX == dotX[i] && dirY == dotY[i]) {                 //✅
      dotX[i] = random(0, 8);                                 //✅
      dotY[i] = random(0, 16);                                //✅
      dotX[dotCount] = random(0, 8);                          //✅
      dotY[dotCount] = random(0, 16);                         //✅
    }                                                         //✅
  }                                                           //✅
  gb.clearDisplay();                                          //✅

  for (int i = 0; i < dotCount; i = i + 1) {                  //✅
    gb.drawPoint(dotX[i], dotY[i]);                           //✅
  }                                                           //✅
  gb.drawPoint(dirX, dirY);                                   //✅
  delay(300);                                                 //✅
}