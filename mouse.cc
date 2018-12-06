#ifndef MOUSE
#define MOUSE

#include "opengl.h"
#include "prototypes.h"
#include "globals.h"

void mouse(int button, int state, int x, int y) { 
    // Controls mouse input
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN && y > x && y > -x + WINDOW_HEIGHT){
                rotation('z', 0);
            }
            else{
                if(state == GLUT_DOWN && x > WINDOW_WIDTH / 2){
                    rotation('x', 0);
                }
                if(state == GLUT_DOWN && x < WINDOW_WIDTH / 2){
                    rotation('y', 0);
                }
            }
            glutIdleFunc(spinDisplay);
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN && y > x && y > -x + WINDOW_HEIGHT)
                rotation('z', 1);
            else{
                if(state == GLUT_DOWN && x > WINDOW_WIDTH / 2)
                rotation('x', 1);
                if(state == GLUT_DOWN && x < WINDOW_WIDTH / 2)
                rotation('y', 1);
            }
            glutIdleFunc(spinDisplay);
            break;

        default:
            break;
    }
}
#endif
