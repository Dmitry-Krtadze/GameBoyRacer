#include <Arduino.h>
#include <GameBoyFixVal.h>
GameBoy gb;

#include "enemy.h"
#include "player.h"
void setup() { gb.begin(0); }

void loop() {
  if(gb.getKey() == 4){
    ClearPlayerCar(5,12);
    playerCar(2,12);
  }else if (gb.getKey() == 5){
    ClearPlayerCar(2,12);
    playerCar(5,12);
  }
}
