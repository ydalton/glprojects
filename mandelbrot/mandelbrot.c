#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "drawshape.h"

#define W_WIDTH 1000
#define W_HEIGHT W_WIDTH
#define W_CENTER W_WIDTH/2, W_HEIGHT/2
#define W_NAME "Mandelbrot"

#ifdef ZOOM
#define ZOOM_FACTOR 0.99
#endif

#define MAX_ITER 50

/* initial conditions */
double cre = -0.5;
double cim = 0;
double diam = 3;

double minr;
double mini;
double maxr;
double maxi;

double stepr;
double stepi;

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
#ifdef ZOOM
    while(1) {
#endif
        glClear(GL_COLOR_BUFFER_BIT);

        minr = cre - diam * 0.5;
        mini = cim - diam * 0.5;
        maxr = cre + diam * 0.5;
        maxi = cim + diam * 0.5;

        stepr = (maxr - minr) / W_WIDTH;
        stepi = (maxi - mini) / W_HEIGHT;

#ifndef DO_ITERATIONS
        iter = MAX_ITER;
#endif
#ifdef DO_ITERATIONS
        for(iter = 0; iter < MAX_ITER; iter++) {
#endif
            for(y = 0; y < W_HEIGHT; y++) {
                for(x = 0; x < W_WIDTH; x++) {
                    c = iterate(minr+x*stepr, mini+y*stepi, iter);
                    if (c == iter)
                        drawPixel(x, y, BLACK);
                    else
                        drawPixel(x, y, (255*c/iter), (255*c/iter), 255);
                }
            }
            glutSwapBuffers();
#ifdef DO_ITERATIONS
        }
#endif
#ifdef ZOOM
    diam *= ZOOM_FACTOR;
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
