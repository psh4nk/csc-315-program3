#ifndef KEYBOARD
#define KEYBOARD

#include "opengl.h"
#include "prototypes.h"
void keyboard( unsigned char key, int x, int y){
    switch(key){
        case 's':
            // stop the house from rotating
            stoprotating();
            break;
        case 'r':
            // reset the house to original position and size
            reset();
            break;
        case 'R':
            //return house to original position and size and reset the 
            //camera to original position and perspective
            reset();
            setzoom(0);
            setviewtype(0);
            glMatrixMode (GL_PROJECTION);
            glLoadIdentity ();
            viewtype();

            glMatrixMode (GL_MODELVIEW); 
            glutPostRedisplay();
            break;
        case 'q':
            exit(0);
        case 'Q':
            exit(0);
    }
}
#endif 
