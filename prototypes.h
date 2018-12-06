#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"

void init(void);
void setdrawaxis(int);
int getdrawaxis();
void drawAxes(int);
void mouse(int, int, int, int);
void keyboard(unsigned char, int , int);
float getzoom();
void setzoom(float);
void specialinput(int, int, int);
void setfill(int);
int getfill();
void spinDisplay();
void rotation(char, int);
void stoprotating();
void reset();
void defineHouse( struct house* );
void drawHouse( struct house* );
void setsignflag(int);
int getsignflag();
void drawSign();
void display(void);
void reshape (int , int );
void setviewtype(int);
int getviewtype();
void viewtype();

#endif

