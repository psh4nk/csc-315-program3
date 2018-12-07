#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"

// Some of this code is from Dr. Pounds

// init.cc
void init(void);

// drawAxes.cc
void setdrawaxis(int);
int getdrawaxis();
void drawAxes(int);

// mouse.cc
void mouse(int, int, int, int);

// keyboard.cc
void keyboard(unsigned char, int , int);

// specialinput.cc
float getzoom();
void setzoom(float);
void specialinput(int, int, int);

// drawHouse.cc
void setfill(int);
int getfill();
void spinDisplay();
void rotation(char, int);
void stoprotating();
void reset();
void drawHouse( struct house* );

// defineHouse.cc
void defineHouse( struct house* );

// drawSign.cc
void setsignflag(int);
int getsignflag();
void drawSign(char*);

// display.cc
void display(void);

// reshape.cc
void reshape (int , int );

// viewtype.cc
void setviewtype(int);
int getviewtype();
void viewtype();

#endif

