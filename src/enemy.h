void enemyCar(int x, int y){
    gb.drawPoint(x,y);
    gb.drawPoint(x,y - 1);
    gb.drawPoint(x - 1,y - 1);
    gb.drawPoint(x + 1,y - 1);
    gb.drawPoint(x,y - 2);
    gb.drawPoint(x - 1, y - 3);
    gb.drawPoint(x + 1, y - 3);
}
void ClearEnemyCar(int x, int y){
    gb.wipePoint(x,y);
    gb.wipePoint(x,y - 1);
    gb.wipePoint(x - 1,y - 1);
    gb.wipePoint(x + 1,y - 1);
    gb.wipePoint(x,y - 2);
    gb.wipePoint(x - 1, y - 3);
    gb.wipePoint(x + 1, y - 3);
}