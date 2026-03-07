#include <Arduino.h>
#include <GameBoyFixVal.h>
GameBoy gb;

#include "enemy.h"
#include "player.h"

int enemy_x = 2;
int car_speed = 100;
int mycar_x = 2;
int mycar_y = 12;

void setup() { 
  gb.begin(0);
  playerCar(mycar_x, mycar_y);
  randomSeed(analogRead(0));
}

void mainRaicing(){
  enemy_x = random(0,10);
  if (enemy_x > 5){
    enemy_x = 2;
  }else{
    enemy_x =  5;
  }
  for(int enemy_y = 0; enemy_y < 16; enemy_y++){
    enemyCar(enemy_x, enemy_y);
    if(gb.getKey() == 5){
      ClearPlayerCar(2,12);
      playerCar(5,12);
    }
    else if(gb.getKey() == 4){
      ClearPlayerCar(5,12);
      playerCar(2,12);
    }
    delay(car_speed);
    ClearEnemyCar(enemy_x, enemy_y);
  }
}

void loop() {   mainRaicing(); }
