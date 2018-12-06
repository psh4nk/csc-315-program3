#ifndef MAIN
#define MAIN

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"
#include "constants.h"
#include <iostream>

void onAxis(int msg){
    switch(msg){
        case 1:
            setdrawaxis(1);
            break;
        case 2:
            setdrawaxis(0);
            break;
    }
    glutPostRedisplay();
}

void dofill(int msg){
    switch(msg){
        case 1:
            setfill(1);
            break;  
        case 2:
            setfill(0);
            break;
    }
    glutPostRedisplay();
}

void putSign(int msg){
    switch(msg){
        case 1:
            setsignflag(1);
            break;
        case 2:
            setsignflag(0);
            break;
    }
    glutPostRedisplay();
}   

void useView(int msg){
    switch(msg){
        case 1:
            setviewtype(0);
            break;
        case 2: 
            setviewtype(1);
            break;
        case 3:
            setviewtype(2);
            break;
    }
    reshape(WINDOW_HEIGHT, WINDOW_WIDTH);
    glutPostRedisplay();

}

void selfDestruct(int msg){}

int main(int argc, char** argv)
{
    int menu, axis, fill, sign, view;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (WINDOW_HEIGHT, WINDOW_WIDTH); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialinput);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape);

    axis = glutCreateMenu(onAxis);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);
    fill = glutCreateMenu(dofill);
    glutAddMenuEntry("Fill", 1);
    glutAddMenuEntry("Wireframe", 2);
    sign = glutCreateMenu(putSign);
    glutAddMenuEntry("Place the sign", 1);
    glutAddMenuEntry("Remove the sign", 2);
    view = glutCreateMenu(useView);
    glutAddMenuEntry("Perspective", 1);
    glutAddMenuEntry("Orthographic", 2);
    glutAddMenuEntry("Custom view (pls enter in console", 3);

    // And now create the menu 
    menu = glutCreateMenu(selfDestruct);
    glutAddSubMenu("Axes", axis);
    glutAddSubMenu("Fill", fill);
    glutAddSubMenu("Sign", sign);
    glutAddSubMenu("View", view);

    glutAttachMenu(GLUT_MIDDLE_BUTTON);



    glutMainLoop();
    return 0;
}

#endif
