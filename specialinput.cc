#ifndef SPECIALINPUT
#define SPECIALINPUT

#include "opengl.h"
#include <iostream>
static float zoom = 0.0;

void setzoom(float value){
    zoom = value;
}

float getzoom(){
    return zoom;
}

void specialinput(int key, int x, int y){
    switch(key){
        case GLUT_KEY_PAGE_UP:
            // move camera closer
            // when page up pressed
            zoom-=.1;
            break;
        case GLUT_KEY_PAGE_DOWN:
            // move camera farther away
            // when page down pressed
            zoom+=.1;
            break;
    }
}
#endif
