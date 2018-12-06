#ifndef VIEWTYPE
#define VIEWTYPE

#include "opengl.h"
#include "structs.h"
#include <string.h>
#include <iostream>
#include <math.h>

static int view = 0;

void setviewtype(int value){
    view = value;
}

int getviewtype(){
    return view;
}

void viewtype(){
    float l,r,b,t,n,f,fovy,aspect,fw,fh;
    l = -1.0; r = 1.0;   // l=left, r=right
    b = -1.0; t = 1.0;   // b=bottom, t=top
    n =  1.0; f = 20.0;   // n=near, f=far  

    //convert glFrustum values to gluPerspective values
    fovy = 2*atan((t)/(fabs(n))) * 180/M_PI;
    aspect = ((r-l)/(t-b)); 
    
    if(view == 0){
        //perspective selected
        gluPerspective(fovy,aspect,n,f);
    }
    else if(view == 1){
        //ortho selected
        glOrtho   (-10.0, 10.0, -10.0, 10.0, 1.0, 20.0);  
    }
    else if(view == 2){
        // custom view selected
        std::cout << "fovy: ";
        std::cin >> fovy;
        std::cout << std::endl;
        std::cout << "aspect: ";
        std::cin >> aspect;
        std::cout << std::endl;
        std::cout << "zNear: ";
        std::cin >> n;
        std::cout << std::endl;
        std::cout << "zFar: ";
        std::cin >> f;
        std::cout << std::endl; 
        gluPerspective(fovy,aspect,n,f);
    }


}

#endif
