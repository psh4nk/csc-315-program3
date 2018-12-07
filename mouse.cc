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
                // add to z rotation if the mouse is 
                // in the bottom center of screen
                rotation('z', 0);
            }
            else{
                if(state == GLUT_DOWN && x > WINDOW_WIDTH / 2){
                    // add to x rotation if the mouse is 
                    // in the right portion of screen
                    rotation('x', 0);
                }
                if(state == GLUT_DOWN && x < WINDOW_WIDTH / 2){
                    // add to y position if the mouse is
                    // in the left portion of the screen
                    rotation('y', 0);
                }
            }
            glutIdleFunc(spinDisplay);
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN && y > x && y > -x + WINDOW_HEIGHT)
                // subtract from z rotation if the mouse is 
                // in the bottom center of screen
                rotation('z', 1);
            else{
                if(state == GLUT_DOWN && x > WINDOW_WIDTH / 2){
                    // subtract from x rotation if the mouse is 
                    // in the bottom center of screen
                    rotation('x', 1);
                }
                if(state == GLUT_DOWN && x < WINDOW_WIDTH / 2){
                    // subtract from y rotation if the mouse is 
                    // in the bottom center of screen
                    rotation('y', 1);
                }
            }
            glutIdleFunc(spinDisplay);
            break;

        default:
            break;
    }
}
#endif
