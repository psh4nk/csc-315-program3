#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"

void init(void);
void setdrawaxis(int);
int getdrawaxis();
void drawAxes(int);
void keyboard(unsigned char, int , int);
void specialinput(int, int, int);
void defineBox( struct house* );
void drawBox( struct house* );
void display(void);
void reshape (int , int );

#endif

