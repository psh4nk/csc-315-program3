#ifndef RESHAPE
#define RESHAPE

#include "opengl.h"
#include "prototypes.h"

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   viewtype();
   //glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);
   //glOrtho   (-10.0, 10.0, -10.0, 10.0, 1.0, 20.0);
   //gluPerspective(67.38,1,1.5,20.0); 

   glMatrixMode (GL_MODELVIEW);
}

#endif
