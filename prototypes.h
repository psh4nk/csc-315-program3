#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"

void init(void);
void setdrawaxis(int);
int getdrawaxis();
void drawAxes(int);
void keyboard(unsigned char, int , int);
void specialinput(int, int, int);
void setfill(int);
int getfill();
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

