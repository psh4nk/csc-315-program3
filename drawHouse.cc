#ifndef DRAWHOUSE
#define DRAWHOUSE

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"
#include <string.h>
#include <iostream>

// code adapted from drawBox.cc from Dr. Pounds

static int fill = 0;
static float xrotate = 0, yrotate = 0, zrotate = 0, deltax = 0, deltay = 0, deltaz =0;

void setfill(int value){
    fill = value;
}

int getfill(){
    return fill;
}

void spinDisplay(){
    // update rotation values
    // and apply them
    xrotate = xrotate + deltax;
    yrotate = yrotate + deltay;
    zrotate = zrotate + deltaz;
    if(xrotate > 360) 
        xrotate = xrotate-360;
    if(yrotate > 360) 
        yrotate = yrotate-360;
    if(zrotate > 360) 
        zrotate = zrotate-360;
    glutPostRedisplay();
}

void reset(){
    // reset the rotation values
    xrotate = 0;
    yrotate = 0;
    zrotate = 0;
    deltax = 0;
    deltay = 0;
    deltaz = 0;
}
void stoprotating(){
    // only reset the delta rotation values,
    // which stops rotation
    deltax = 0;
    deltay = 0;
    deltaz = 0;
}

void rotation(char axis, int direction){
    // rotate based on input axis and direction
    
    // axis is either 'x', 'y', or 'z'
    // direction is either 0 : + or 1 : -
    if(axis == 'x')
        if(direction == 0)
            deltax += 1;
        else if(direction == 1)
            deltax -= 1;
    if(axis == 'y')
        if(direction == 0)
            deltay += 1;
        else if(direction == 1)
            deltay -= 1;
    if(axis == 'z')
        if(direction == 0)
            deltaz += 1;
        else if(direction == 1)
            deltaz -= 1;
}


void drawHouse( struct house *face ){
    // draws the house from defineHouse.cc,
    // draws the sign on the house,
    // and draws the viewport labels
    
    int i, j;
    char message[] = "HV GOOD BRK!";
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();
    glTranslatef(0.0, 2.0, 1.0);
    glRotatef(xrotate, 1.0, 0.0, 0.0);
    glRotatef(yrotate, 0.0, 1.0, 0.0);
    glRotatef(zrotate, 0.0, 0.0, 1.0);
    glTranslatef(-1.0,-1.0,-1.0);
    // draw the house/barn
    glPushMatrix();
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
    glTranslatef(0.0,0.0,0.0);

    glPopMatrix();

    // draw the sign
    glScalef(face[4].point[0].x/650, face[4].point[1].x/270, face[4].point[2].x/400);
    glRotatef(180.0,0.0,1.0,0.0);
    glTranslatef(-620.0,210.0,-500.0);
    glRotatef(240.0,1.0,0.0,0.0);
    drawSign(message);
    glPopMatrix();
    glPopMatrix();
    
    
    glPopMatrix();
    glPushMatrix();
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
        glRotatef(40,0,1,0);
        glRotatef(90,0,0,1);
        glTranslatef(400,4000,0);
        glColor3f(1.0,0.0,1.0);
        char orthographic[] = "ORTHOGRAPHIC";
        glRasterPos3f( 50.0f,50.0f, 0.0f );
        for(int i = 0; i < (int)strlen(orthographic); i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, orthographic[i]);
        glPopMatrix();
    }
    else if(getviewtype() == 2){
        // custom view selected
        glPushMatrix();
        glScalef(.003,.003,.003);
        glRotatef(40,0,1,0);
        glRotatef(90,0,0,1);
        glTranslatef(200,4300,0);
        glColor3f(1.0,0.0,1.0);
        char custom[] = "CUSTOM VIEW";
        glRasterPos3f( 450.0f,500.0f, 0.0f );
        for(int i = 0; i < (int)strlen(custom); i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, custom[i]);
        glPopMatrix();
    }
    glPopMatrix();

}

#endif
