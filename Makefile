# Structured makefile for camera placement
#
#

CC = g++
LDLIBS =  -lglut -lGL -lGLU -lm
HEADERS = opengl.h structs.h globals.h constants.h prototypes.h
OBJS = init.o defineHouse.o drawHouse.o drawAxes.o drawSign.o reshape.o display.o keyboard.o specialinput.o viewtype.o  

debug ?= n
ifeq ($(debug), y)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2 
endif


all: main tags  

main :	main.o $(OBJS) 
	$(CC) $(CFLAGS) main.o $(OBJS) -o main $(LDLIBS)

main.o : main.cc $(HEADERS)
	$(CC) $(CFLAGS) main.cc -c

init.o : init.cc $(HEADERS)
	$(CC) $(CFLAGS) init.cc -c

defineBox.o : defineHouse.cc $(HEADERS)
	$(CC) $(CFLAGS) defineHouse.cc -c

drawBox.o : drawHouse.cc $(HEADERS)
	$(CC) $(CFLAGS) drawHouse.cc -c

drawAxes.o : drawAxes.cc $(HEADERS)
	$(CC) $(CFLAGS) drawAxes.cc -c

drawSign.o : drawSign.cc $(HEADERS)
	$(CC) $(CFLAGS) drawSign.cc -c

reshape.o : reshape.cc $(HEADERS)
	$(CC) $(CFLAGS) reshape.cc -c

display.o : display.cc $(HEADERS)
	$(CC) $(CFLAGS) display.cc -c

keyboard.o : keyboard.cc $(HEADERS)
	$(CC) $(CFLAGS) keyboard.cc -c

specialinput.o : specialinput.cc $(HEADERS)
	$(CC) $(CFLAGS) specialinput.cc -c

viewtype.o : viewtype.cc $(HEADERS)
	$(CC) $(CFLAGS) viewtype.cc -c


clean:
	rm *.o

pristine:
	rm *.o
	touch *

tags:
	ctags *.h *.cc
