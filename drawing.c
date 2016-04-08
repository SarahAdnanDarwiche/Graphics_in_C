// ourDrawing.c  proj2a, CS16, Fall 2012, UCSB
// I will be making a random design.
// Sarah Darwiche
// 11/10/2012
// Outline: P. Conrad and others--see bottom of file
#include "drawing.h"
#include "drawingFunctions.h"
#include "shapes.h"
#include <stdio.h>
#define FILENAME "ourDrawing.pbm"

void drawdesign(struct Drawing *d, struct Point center, float scale)
{
  
  struct Box     background_1;
  struct Circle  background_2;
  struct Polygon petal_1;
  struct Polygon petal_2;
  struct Polygon petal_3;
  struct Polygon petal_4;
  struct Polygon petal_5;
  struct Polygon petal_6;
  struct Polygon petal_7;
  struct Polygon petal_8;
  struct Polygon petal_9;
  struct Polygon petal_10;
  struct Polygon petal_11;
  struct Circle  center_1;
  
  //initBox(&background_1,((center.x-90),(center.y-54)),((center.x-80),(center.y-54)),(scale*160),(scale*110));
  //fillBox(d,background_1, COLOR_BLACK);
  
  initCircle(&background_2, makePoint(center.x ,center.y), (70.0*scale));
  fillCircle(d,background_2,COLOR_MAGENTA);
  
  initRegularPolygon(&petal_1, 8, makePoint(center.x ,center.y), (60.0*scale));
  fillPolygon(d,petal_1,COLOR_WHITE);
  initRegularPolygon(&petal_2, 10, makePoint(center.x ,center.y), (60.0*scale));
  fillPolygon(d,petal_2,COLOR_WHITE);
  
  initRegularPolygon(&petal_3, 10, makePoint(center.x ,center.y), (51.0*scale));
  fillPolygon(d,petal_3,COLOR_BLUE);
  initRegularPolygon(&petal_4, 12, makePoint(center.x ,center.y), (51.0*scale));
  fillPolygon(d,petal_4,COLOR_BLUE);
  
  initRegularPolygon(&petal_5, 6, makePoint(center.x ,center.y), (43.0*scale));
  fillPolygon(d,petal_5,COLOR_PURPLE);
  initRegularPolygon(&petal_6, 8, makePoint(center.x ,center.y), (43.0*scale));
  fillPolygon(d,petal_6,COLOR_PURPLE);
  
  initRegularPolygon(&petal_7, 8, makePoint(center.x ,center.y), (36.0*scale));
  fillPolygon(d,petal_7,COLOR_BLUE);
  initRegularPolygon(&petal_8, 6, makePoint(center.x ,center.y), (36.0*scale));
  fillPolygon(d,petal_8,COLOR_BLUE);
  
  initRegularPolygon(&petal_9, 3, makePoint(center.x ,center.y), (36.0*scale));
  fillPolygon(d,petal_9,COLOR_MAGENTA);
  
  initRegularPolygon(&petal_10, 8, makePoint(center.x ,center.y), (20.0*scale));
  fillPolygon(d,petal_10,COLOR_WHITE);
  initRegularPolygon(&petal_11, 6, makePoint(center.x ,center.y), (20.0*scale));
  fillPolygon(d,petal_11,COLOR_WHITE);
  
  initCircle(&center_1, makePoint(center.x ,center.y), (10.0*scale));
  fillCircle(d,center_1,COLOR_PURPLE);
  
  drawLineXY(d,center.x,(center.y+10), center.x, (center.y-10), COLOR_BLACK);
  drawLineXY(d,(center.x-10), center.y, (center.x+10), center.y, COLOR_BLACK);
  
}

int main()
{

  struct Drawing d;
  struct Box     background_1;
  struct Circle  background_2;
  struct Polygon petal_1;
  struct Polygon petal_2;
  struct Polygon petal_3;
  struct Polygon petal_4;
  struct Polygon petal_5;
  struct Polygon petal_6;
  struct Polygon petal_7;
  struct Polygon petal_8;
  struct Polygon petal_9;
  struct Polygon petal_10;
  struct Polygon petal_11;
  struct Circle  center_1;

initDrawing(&d, DRAWINGTYPE_COLOR, 512, 512, COLOR_WHITE);

drawdesign(&d, makePoint(100,80),1);
drawdesign(&d, makePoint(300,110),1.5);
drawdesign(&d, makePoint(200,350),2);

writeFile(&d, FILENAME);
return 0;
  
}