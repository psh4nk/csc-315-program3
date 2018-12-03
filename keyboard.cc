#include "opengl.h"

void keyboard( unsigned char key, int x, int y){
    switch(key){
        case 's':
            //stop house rotation
            break;
        case 'r':
            // reset the house to original position and size
            break;
        case 'R':
            //return house to original position and size and reset the 
            //camera to original position and perspective
            break;
        case 'q':
            exit(0);
        case 'Q':
            exit(0);
    }

    
}
