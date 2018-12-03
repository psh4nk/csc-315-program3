
#ifndef DRAW_AXES
#define DRAW_AXES

#include "opengl.h" 
#include <iostream>
void drawAxes(int length, int drawaxis)
{   

    /* This provides a coordinate axis about the origin. */
    std::cout << "drawaxis: " << drawaxis << std::endl;
    if(drawaxis != 0){
        glPointSize(1.0);
        glBegin(GL_LINES);
        glVertex3i(0,length,0);
        glVertex3i(0,-length,0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3i(length,0,0);
        glVertex3i(-length,0,0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3i(0,0,length);
        glVertex3i(0,0,-length);
        glEnd();
    }

}

#endif
