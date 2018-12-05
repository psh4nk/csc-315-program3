#ifndef DRAWBOX
#define DRAWBOX

#include "opengl.h"
#include "structs.h"

int fill = 0;

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

    for(j=0;j<7;j++){ // one more side than the boxes had to account for front and back

        glColor3f(face[j].color.red, face[j].color.green, face[j].color.blue);

        if(fill == 1) 
            glBegin(GL_POLYGON); // draw it filled. Will add flag here later
        else 
            glBegin(GL_LINE_LOOP);
        for (i=0;i<5;i++){
            glVertex3f(face[j].point[i].x, face[j].point[i].y, face[j].point[i].z);
        }
        glEnd();
    }

    glPopMatrix();

}

#endif
