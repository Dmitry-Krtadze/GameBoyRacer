#include <Arduino.h>
#include <GameBoyFixVal.h>
GameBoy gb;

int dotX[50];                  
int dotY[50];                  
int dotCount = 1;              
int snakeX[10];       
int snakeY[10];       

int up = 0;  
int right = 1;  
int bottom = 2;  
int left = 3;    
int direction = right; 


int lenSnake = 5;

void setup() {  
  gb.begin(0);
  snakeX[0] = 4;
  snakeY[0] = 7;
  randomSeed(analogRead(0));   
  dotX[0] = random(0, 8);      
  dotY[0] = random(0, 16);     
}
int x = 1, y = 0;
int dirX = 3, dirY = 7; 

void makeMove(){
  if(gb.getKey() == 4 && direction != right){  direction = left;  }
  if(gb.getKey() == 5 && direction != left) {  direction = right;  } 
  if(gb.getKey() == 6 && direction != up)   {  direction = bottom;  }
  if(gb.getKey() == 3 && direction != bottom){  direction = up; }
}
void loss()
{
  delay(2000);
  gb.clearDisplay();
  for(int i = 0; i < lenSnake; i++)
  {
    snakeX[i] = 0;
    snakeY[i] = 0;
  }
  direction = right;
  dotX[0] = 3;
  dotY[0] = 3;
  lenSnake = 4;
  snakeX[0] = 4;
  snakeY[0] = 7;
}


void move(){

  for(int i = lenSnake - 1; i > 0; i--){
    if(snakeX[0]==snakeX[i] && snakeY[0] == snakeY[i]){
      loss();
    }
  }

  for (int i = lenSnake -1; i > 0; i--){
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }

  if (direction == up){
    if(snakeY[0] == 0){
      snakeY[0] = 15;
    }else{
      snakeY[0]--;
    }
  }
  
  if (direction == bottom){
    if(snakeY[0] == 15){
      snakeY[0] = 0;
    }else{
      snakeY[0]++;
    }
  }
  //--------------------------
  if (direction == left){
    if(snakeX[0] == 0){
      snakeX[0] = 7;
    }else{
      snakeX[0]--;
    }
  }
  //--------------------------
  if (direction == right){
    if(snakeX[0] == 7){
      snakeX[0] = 0;
    }else{
      snakeX[0]++;
    }
  }
  
}

void drawSnake(){
  for (int i =0; i < lenSnake; i++){
    gb.drawPoint(snakeX[i], snakeY[i]);
  }
}



void loop() { 
  makeMove();
  move();
  gb.clearDisplay();
  drawSnake();                             
  delay(250);                                                 
}
//   https://github.com/Dmitry-Krtadze/GameBoyRacer/