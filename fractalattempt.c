// ourDrawing.c  proj2a, CS16, Fall 2012, UCSB
// I will be making a fractal.
// Sarah Darwiche
// 11/10/2012
// Outline: P. Conrad and others--see bottom of file

#include <math.h>
#include "drawing.h"
#include "shapes.h"
#include <stdio.h>
#define FILENAME "ourDrawing.pbm"

// @@@ RENAME THIS from drawShape1 to whatever you want to draw
// @@@ be that a skateboard, iPod, basketball court or whatever.


void fractal(struct Drawing *d, struct Point center, double height, double width)
{
  // @@@ Insert some code that determines the points, boxes,
  // @@@ circles, etc. you need
  // @@@ based on the values you passed in

  // @@@ Then call functions like initBox, initCircle, or whatever
  // @@@ to create the points, polygons, circles, boxes, etc

  // @@@ Then call functions like fillBox, fillCircle, or whatever
  // @@@ to make a drawing.  Pass d as your first parameter.
  
  char Direct;
  int iterate;
  double x1, y1, x2, y2;

	x1 = x2 = 320;
	y1 = y2 = 0;

	for(iterate = 0; iterate < 10000; iterate++)
	{
		Direct = rand();
		
		if(Direct == 0)
		{
			x1 = (x2 + 320) / 2;
			y1 = (y2 + 0) / 2;	
		}
		else if(Direct == 1)
		{
			x1 = (x2 + 0) / 2;
			y1 = (y2 + 480) / 2;
		}
		else if(Direct == 2)
		{
			x1 = (x2 + 640) / 2;	
			y1 = (y2 + 480) / 2;
		}
		putpixel(x1, y1, COLOR_BLUE);
		
        x2 = x1;
		y2 = y1;
	}


  
}


int main()
{
  struct Drawing d;
 
  // @@@ modify the values 400 and 150 to be the width/height
  // @@@ that you want

  initDrawing(&d, COLOR_BLUE, 400, 150, COLOR_WHITE);

  // @@@ call the drawing Routines.  The values 100,100, 50, 20
  // @@@ below are just example values

  // @@@ Draw each shape in at least two places in at least two
  // @@@ different sizes

  fractal(&d,makePoint(100,100),50,20);
  fractal(&d,makePoint(150,100),70,25);

  writeFile(&d, FILENAME);

  return 0;

}



// Netbpmtools project -- A project to create a set of tools in C
//  to explore graphics using the netpbm file format.
// Contributors to this project include:
//   Phill Conrad, Tobias Hollerer, Eric Goodman, Alex Wickes,
//   Mark Hamlin, Nick Vaughan











