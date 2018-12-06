#ifndef DRAWHOUSE
#define DRAWHOUSE

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"
#include <string.h>

static int fill = 0;

void setfill(int value){
    fill = value;
}

int getfill(){
    return fill;
}


void drawHouse( struct house *face ){
    int i, j;

    glPushMatrix();
    glScalef(face[4].point[0].x/550, face[4].point[1].x/270, face[4].point[2].x/400);
    glRotatef(180.0,0.0,2.0,0.0);
    glTranslatef(-200.0,0.0,-500.0);
    glRotatef(240.0,1.0,0.0,0.0);
    drawSign();
    glPopMatrix();

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();

    // draw the house/barn
    for(j=0;j<7;j++){ // one more side than the boxes had to account for front and back


        if(fill == 1){
            glColor3f(face[j].color.red, face[j].color.green, face[j].color.blue); // use the fill colors
            glBegin(GL_POLYGON); // draw it filled
        }
        else {
            glColor3f(0, .6, .9); // draw the wireframe a nice shade of blue
            glBegin(GL_LINE_LOOP);  // draw the wireframe without filling
        }
        for (i=0;i<5;i++){
            glVertex3f(face[j].point[i].x, face[j].point[i].y, face[j].point[i].z);
        }
        glEnd();
    }
    glTranslatef(0,0,0);

    glPopMatrix();

    // draw what view type is selected in the top right corner
    if(getviewtype() == 0){
        // perspective selected
        glPushMatrix();
        glScalef(.003,.003,.003);
        glRotatef(40,0,1,0);
        glRotatef(90,0,0,1);
        glTranslatef(200,4300,0);
        glColor3f(1.0,0.0,1.0);
        char perspective[] = "PERSPECTIVE";
        glRasterPos3f( 500.0f , 500.0f ,0.0f );
        for(int i = 0; i < (int)strlen(perspective); i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, perspective[i]);
        glPopMatrix();
    }
    else if(getviewtype() == 1){
        //ortho selected
        glPushMatrix();
        glScalef(.003,.003,.003);
        /*glRotatef(35,0,1,0);
        glRotatef(91,0,0,1);
        glTranslatef(150,4300,0);*/
        glColor3f(1.0,0.0,1.0);
        char orthographic[] = "ORTHOGRAPHIC";
        glRasterPos3f( 500.0f , 500.0f ,0.0f );
        for(int i = 0; i < (int)strlen(orthographic); i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, orthographic[i]);
        glPopMatrix();
    }
    else if(getviewtype() == 2){
        glPushMatrix();
        glScalef(.003,.003,.003);
        glRotatef(40,0,1,0);
        glRotatef(90,0,0,1);
        glTranslatef(200,4300,0);
        glColor3f(1.0,0.0,1.0);
        char custom[] = "CUSTOM VIEW";
        for(int i = 0; i < (int)strlen(custom); i++)
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, custom[i]);
        glPopMatrix();
    }

}

#endif
