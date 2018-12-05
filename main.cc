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

void selfDestruct(int msg){}

int main(int argc, char** argv)
{
    int menu, axis, fill;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (WINDOW_HEIGHT, WINDOW_WIDTH); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialinput);
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape);

    axis = glutCreateMenu(onAxis);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);
    fill = glutCreateMenu(dofill);
    glutAddMenuEntry("Fill it", 1);
    glutAddMenuEntry("Wireframe it", 2);

    // And now create the menu 
    menu = glutCreateMenu(selfDestruct);
    glutAddSubMenu("Axes", axis);
    glutAddSubMenu("Fill", fill);

    glutAttachMenu(GLUT_MIDDLE_BUTTON);



    glutMainLoop();
    return 0;
}

#endif
