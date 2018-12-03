#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"

void init(void);
void drawAxes(int , int);
void keyboard(unsigned char, int , int);
void specialinput(int, int, int);
void defineBox( struct house* );
void drawBox( struct house* );
void display(void);
void reshape (int , int );
static int drawaxis = 1;
/*
void init(void) 
void drawAxes(int length)
void defineBox( box *face )
void drawBox( struct box *face )
void display(void)
void reshape (int w, int h)
*/
#endif

