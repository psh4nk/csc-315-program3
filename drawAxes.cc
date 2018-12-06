
#ifndef DRAW_AXES
#define DRAW_AXES

#include "opengl.h" 
#include <string.h>

static int drawaxis;

void setdrawaxis(int value){
    drawaxis = value;
}

int getdrawaxis(){
    return drawaxis;
}

void drawAxes(int length)
{   

    /* This provides a coordinate axis about the origin. */
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

        //Label the axes
        char x[] = "X", y[] = "Y", z[] = "Z";
        
        // label x axis
        glPushMatrix();
        glScalef(.005, .005, .005);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        glRotatef(90.0, 0.0, 0.0, 1.0);
        glTranslatef(900.0, 0.0, .5);
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, x[0]);
        glPopMatrix();

        // label y axis
        glPushMatrix();
        glScalef(.005, .005, .005);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        glRotatef(95.0, 0.0, 0.0, 1.0);
        glTranslatef(0.0, 50.0, 1000.0);
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, y[0]);
        glPopMatrix();

        // label z axis
        glPushMatrix();
        glScalef(.005, .005, .005);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        glRotatef(90.0, 0.0, 0.0, 1.0);
        glTranslatef(0.0, 900.0, .5);
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, z[0]);
        glPopMatrix(); 

    }

}

#endif
