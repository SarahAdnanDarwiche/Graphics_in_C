// ourDrawing.c  proj2a, CS16, Fall 2012, UCSB
// I will be making a snowflake-like structure.
// Sarah Darwiche
// 11/10/2012
// Outline: P. Conrad and others--see bottom of file
#include "drawing.h"
#include "drawingFunctions.h"
#include "shapes.h"
#include <stdio.h>
#define FILENAME "ourDrawing.pbm"

int main ()
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
  struct Circle  center;
  
  initDrawing(&d, DRAWINGTYPE_COLOR, 200, 150, COLOR_WHITE);

  //void fillBox(struct Drawing *d, struct Box b, int color);
  initBox(&background_1,(10,20),(20,20),160,110);
  fillBox(&d, background_1, COLOR_BLACK);
  
  initCircle(&background_2, makePoint(100.0,74.0), 70.0);
  fillCircle(&d,background_2,COLOR_MAGENTA);
  
  initRegularPolygon(&petal_1, 8, makePoint(100.0,74.0), 60.0);
  fillPolygon(&d,petal_1,COLOR_WHITE);
  initRegularPolygon(&petal_2, 10, makePoint(100.0,74.0), 60.0);
  fillPolygon(&d,petal_2,COLOR_WHITE);
  
  initRegularPolygon(&petal_3, 10, makePoint(100.0,74.0), 51.0);
  fillPolygon(&d,petal_3,COLOR_BLUE);
  initRegularPolygon(&petal_4, 12, makePoint(100.0,74.0), 51.0);
  fillPolygon(&d,petal_4,COLOR_BLUE);
  
  initRegularPolygon(&petal_5, 6, makePoint(100.0,74.0), 43.0);
  fillPolygon(&d,petal_5,COLOR_PURPLE);
  initRegularPolygon(&petal_6, 8, makePoint(100.0,74.0), 43.0);
  fillPolygon(&d,petal_6,COLOR_PURPLE);
  
  initRegularPolygon(&petal_7, 8, makePoint(100.0,74.0), 36.0);
  fillPolygon(&d,petal_7,COLOR_BLUE);
  initRegularPolygon(&petal_8, 6, makePoint(100.0,74.0), 36.0);
  fillPolygon(&d,petal_8,COLOR_BLUE);
  
  initRegularPolygon(&petal_9, 3, makePoint(100.0,74.0), 36.0);
  fillPolygon(&d,petal_9,COLOR_MAGENTA);
  
  initRegularPolygon(&petal_10, 8, makePoint(100.0,74.0), 20.0);
  fillPolygon(&d,petal_10,COLOR_WHITE);
  initRegularPolygon(&petal_11, 6, makePoint(100.0,74.0), 20.0);
  fillPolygon(&d,petal_11,COLOR_WHITE);
  
  initCircle(&center, makePoint(100.0,74.0), 10.0);
  fillCircle(&d,center,COLOR_PURPLE);
  
  drawLineXY(&d, 100, 84, 100, 64, COLOR_BLACK);
  drawLineXY(&d, 90, 74, 110, 74, COLOR_BLACK);
  drawLineXY(&d, 106.64, 81.47, 92.7, 67.1, COLOR_BLACK);
  drawLineXY(&d, 107.2, 67, 93, 81.3, COLOR_BLACK);
  
  writeFile(&d, FILENAME);
  return 0;
}











