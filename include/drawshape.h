#ifndef DRAWSHAPE_H_
#define DRAWSHAPE_H_

#include <stdint.h>

#include <GL/glut.h>

#define WHITE 1, 1, 1
#define BLACK 0, 0, 0

#define M_TAU (2*M_PI)

struct Shape {   
    uint16_t x,y,r,n;   /* x and y position, radius and number of sides. */
    float angle;        /* initial angle */
    int16_t speed;      /* speed of rotation */
    float color[3];     /* color */
};

void init(uint16_t width, uint16_t height, char *name,
		float red, float green, float blue);

void drawPixel(uint16_t x, uint16_t y, 
        uint16_t red, uint16_t green, uint16_t blue);
void drawLinePoly(struct Shape s);
void drawFillPoly(struct Shape s);

#endif
