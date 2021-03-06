# Makefile for CS16 
# Author: Harry Presman
# With additional modifications by P. Conrad and B. Mazloom
# Modified Date: 07/20/2011

# Globals
CC = gcc
CFLAGS = -Wall -g 


# Convenient Macros
PICS = house.gif filledHouse.gif snowman.gif manySnowmen.gif \
	flags.gif ourDrawing.gif 
OBJS = drawingFunctions.o shapeFunctions.o
HEAD = shapes.h drawing.h shapeFunctions.h drawingFunctions.h
BINARIES = drawHouse drawFilledColorHouse drawSnowman \
	drawManySnowmen drawFlags ourDrawing
WEBSUBDIR = cs16/project2a
WEBDIR = $(HOME)/public_html/$(WEBSUBDIR)
WEBPAGE = http://www.cs.ucsb.edu/~$(USER)/$(WEBSUBDIR)
CP = /bin/cp
CONVERT = /opt/local/bin/convert 
MKDIR = /bin/mkdir

# Project files

all : $(BINARIES) $(PICS) web

drawHouse : $(OBJS) drawHouse.o
	$(CC) -lm $(OBJS) drawHouse.o -o $@

drawFilledColorHouse : $(OBJS) drawFilledColorHouse.o
	$(CC) -lm $(OBJS) drawFilledColorHouse.o -o $@

drawSnowman : $(OBJS) drawSnowman.o
	$(CC) -lm $(OBJS) drawSnowman.o -o $@

drawManySnowmen : $(OBJS) drawManySnowmen.o
	$(CC) -lm $(OBJS) drawManySnowmen.o -o $@

drawFlags : $(OBJS) drawFlags.o
	$(CC) -lm $(OBJS) drawFlags.o -o $@

ourDrawing : $(OBJS) ourDrawing.o
	$(CC) -lm $(OBJS) ourDrawing.o -o $@

# Since there aren't many files, if any header changes, we'll
# recompile all .c files into .o files.  Otherwise, if any one .c file
# changes, we'll just recompile that one file into a .o file.

%.o : %.c $(HEAD)
	$(CC) -c $<

# We could also be explicit, but I don't think it's worth it:
#drawHouse.o : drawing.h shapes.h drawHouse.c
#drawFilledColorHouse.o : drawing.h shapes.h drawFilledColorHouse.c
#shapeFunctions.o : shapes.h shapeFunctions.h shapeFunctions.c
#drawingFunctions.o : drawing.h shapes.h shapeFunctions.h drawingFunctions.h drawingFunctions.c


# To make a gif file from a pbm, run the convert program

%.gif : %.pbm
	$(CONVERT) $< $@

house.pbm: drawHouse
	./drawHouse $@

filledHouse.pbm: drawFilledColorHouse
	./drawFilledColorHouse $@

snowman.pbm: drawSnowman
	./drawSnowman

manySnowmen.pbm: drawManySnowmen
	./drawManySnowmen

flags.pbm: drawFlags
	./drawFlags

ourDrawing.pbm: ourDrawing
	./ourDrawing

web: $(PICS) 
	$(MKDIR) -p $(WEBDIR)
	$(CP) $(PICS) $(WEBDIR)
	echo "Visit $(WEBPAGE) to see your pics"

clean :
	rm -f *.o core core.* *.pbm *.gif ${BINARIES}

