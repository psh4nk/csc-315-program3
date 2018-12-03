#include "opengl.h"
#include <iostream>

void specialinput(int key, int x, int y){
    switch(key){
        case GLUT_KEY_PAGE_UP:
            //move camera closer
            break;
        case GLUT_KEY_PAGE_DOWN:
            //move camera farther away
            break;
    }
}
