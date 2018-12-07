#ifndef DRAWSIGN
#define DRAWSIGN

#include "opengl.h"
#include "structs.h"
#include <string.h>

static int signflag = 0;

void setsignflag(int value){
    signflag = value;
}

int getsignflag(){
    return signflag;
}

void drawSign(char input[]){
    // specifu what text the sign should draw
    // doesn't actaully draw the house, 
    // drawHouse does that
    if(signflag == 1 || signflag == 2){
        glColor3f(1.0,1.0,1.0);
        char message[] = "HELLO WORLD!";
        if(signflag == 1){
            void *font = GLUT_STROKE_MONO_ROMAN;
            for(int i = 0; i < (int)strlen(message); i++)
                glutStrokeCharacter(font, message[i]);
        }
        if(signflag == 2){
            void *font = GLUT_STROKE_MONO_ROMAN;
            for(int i = 0; i < (int)strlen(input); i++)
                glutStrokeCharacter(font, input[i]);
        }
    }
}

#endif
