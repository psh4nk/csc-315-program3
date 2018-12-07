
#ifndef STRUCTS
#define STRUCTS

// Most of this code was written by Dr. Pounds

typedef struct vertex {
        float x;
        float y;
        float z;
        float w;
} vertex;

typedef struct colortype {
	float red;
	float green;
	float blue;
} colortype;

typedef struct box {
	vertex point[4];
	colortype color;	
} box;

typedef struct house {
	vertex point[5];
	colortype color;	
} house;

#endif
