#ifndef RESHAPE
#define RESHAPE

#include "opengl.h"
#include "prototypes.h"

// Some portions of this code 
// were written by Dr. Pounds

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   viewtype();
   glMatrixMode (GL_MODELVIEW);
}

#endif
