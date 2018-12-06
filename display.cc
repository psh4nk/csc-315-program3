#ifndef DISPLAY
#define DISPLAY

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"

static int drawaxis = 0;

void display(void)
{

    struct house faces[7]; 
    float *M;
    int i, j;


    defineHouse(&faces[0]);

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);

    /* ONLY MODIFY CODE BELOW */

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();             /* clear the matrix */

    // Let's manually move the camera back

    //glTranslatef(0.0, 0.0, -10.0);

    // Now explicitly place the camera

    gluLookAt (6.1+getzoom(), 5.1+getzoom(), 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

    /* DO NOT MODIFY ANYTHING ELSE */


    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Draw a coordinate axis */
    drawAxes(5);

    /* Draw house + sign */
    drawHouse(&faces[0]); 
	glPopMatrix();
    glFlush();

}

#endif
