#include <GL/freeglut_std.h>

#include <math.h>
#include <stdio.h>

#include "drawshape.h"

/* Window details */
#define W_WIDTH 600
#define W_HEIGHT W_WIDTH
#define W_CENTER W_WIDTH/2, W_HEIGHT/2
#define W_NAME "Gravity"

#define DEF_SPEED 0.005

int frame;

struct Shape pent = {
    .x = W_WIDTH/2,
    .y = W_HEIGHT/2,
    .r = 100,
    .n = 6,
    .angle = 0.0,
    .speed = 4,
    .color = {1.0, 1.0, 1.0}
};

struct Shape pent2 = {
    .x = W_WIDTH/2,
    .y = W_HEIGHT/2,
    .r = 80,
    .n = 48,
    .angle = 0.0,
    .speed = -4,
    .color = {1.0, 1.0, 1.0}
};
struct Shape f = {
    .x = 400,
    .y = 400,
    .r = 30,
    .n = 6,
    .angle = 0,
    .speed = 0,
    .color = {1.0, 1.0, 1.0}
};

void display(void) {
    while(1) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawLinePoly(pent);
        drawLinePoly(pent2);
        drawFillPoly(f);
        pent2.x = 100 * sin((float) frame/50)+W_WIDTH/2;
        pent2.r = 20 * cos((float) frame/50)+50;
        glutSwapBuffers();
        frame++;
    }
}

int main(int argc, char *argv[]) {
    frame = 0;
    glutInit(&argc, argv);
    init(W_WIDTH, W_HEIGHT, W_NAME, BLACK);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
