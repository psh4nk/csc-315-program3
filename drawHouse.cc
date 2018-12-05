#ifndef DRAWHOUSE
#define DRAWHOUSE

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"

static int fill = 0;

void setfill(int value){
    fill = value;
}

int getfill(){
    return fill;
}


void drawHouse( struct house *face )
{
    int i, j;

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();

    // draw the house/barn
    for(j=0;j<7;j++){ // one more side than the boxes had to account for front and back

        glColor3f(face[j].color.red, face[j].color.green, face[j].color.blue);

        if(fill == 1) 
            glBegin(GL_POLYGON); // draw it filled
        else {
            glColor3f(0, .6, .9); // draw the wireframe a nice shade of blue
            glBegin(GL_LINE_LOOP);  // draw the wireframe without filling
        }
        for (i=0;i<5;i++){
            glVertex3f(face[j].point[i].x, face[j].point[i].y, face[j].point[i].z);
        }
        glEnd();
    }

    glPopMatrix();
    
    // set the sign position and then draw it
    glPushMatrix();
	glScalef(face[4].point[0].x/550, face[4].point[1].x/270, face[4].point[2].x/400);
	glRotatef(180.0,0.0,2.0,0.0);
	glTranslatef(-200.0,0.0,-500.0);
	glRotatef(240.0,1.0,0.0,0.0);
	drawSign();
}

#endif
