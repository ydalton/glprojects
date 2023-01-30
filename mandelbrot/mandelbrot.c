#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "drawshape.h"

#define W_WIDTH 1000 
#define W_HEIGHT W_WIDTH
#define W_CENTER W_WIDTH/2, W_HEIGHT/2
#define W_NAME "Mandelbrot"

#define MAX_ITER 500

#define CENTER_REAL -1.4
#define CENTER_IMAGINARY 0.0
#define DIAMETER 0.05

const double minr = CENTER_REAL - DIAMETER * 0.5;
const double mini = CENTER_IMAGINARY - DIAMETER * 0.5;
const double maxr = CENTER_REAL + DIAMETER * 0.5;
const double maxi = CENTER_IMAGINARY + DIAMETER * 0.5;

static const double stepr = (maxr - minr) / W_WIDTH;
static const double stepi = (maxi - mini) / W_HEIGHT;

int iterate(double x, double y, uint16_t max_iter) {
    int iter;
    double r = x;
    double i = y;
    for (iter = 0; iter < max_iter; ++iter) {
        double r2 = r*r, i2 = i*i;
        if(r2+i2 >= 4.0) break;
        double ri = r*i;
        i = ri+ri + y;
        r = r2-i2 + x;
    }
    return iter;
}

void display(void) {
    uint16_t x, y, iter;
    int c;
    glClear(GL_COLOR_BUFFER_BIT);
#ifndef DO_ITERATIONS
    iter = MAX_ITER;
#endif
#ifdef DO_ITERATIONS
    for(iter = 0; iter < MAX_ITER; iter++) {
#endif
        for(y = 0; y < W_HEIGHT; y++) {
            for(x = 0; x < W_WIDTH; x++) {
                c = iterate(minr+x*stepr, mini+y*stepi, iter);
                //if (c == iter) c = MAX_ITER;
                drawPixel(x, y, 255-(255*c/iter), 255-(255*c/iter), 255-(255*c/iter));
            }
        }
        glutSwapBuffers();
#ifdef DO_ITERATIONS
    }
#endif
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    init(W_WIDTH, W_HEIGHT, W_NAME, BLACK);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
