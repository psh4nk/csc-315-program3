#ifndef MAIN
#define MAIN

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"
#include "constants.h"
#include <iostream>
//int drawaxis = 0;

void onAxis(int msg){
    switch(msg){
        case 1:
            drawaxis = 1;
            std::cout << "axis should be on: " << drawaxis << std::endl;
            break;
        case 2:
            drawaxis = 0;
            std::cout << "axis should be off: " << drawaxis << std::endl;
            break;
    }
    glutPostRedisplay();
}

void selfDestruct(int msg){}

int main(int argc, char** argv)
{
    int menu, axis, sphere;

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

    // And now create the menu 
    menu = glutCreateMenu(selfDestruct);
    glutAddSubMenu("Axes", axis);

    glutAttachMenu(GLUT_MIDDLE_BUTTON);



    glutMainLoop();
    return 0;
}

#endif
