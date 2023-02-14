#include <GL/glut.h>

#include <stdint.h>
#include <stdio.h>

#include "drawshape.h"

#define W_WIDTH 640
#define W_HEIGHT 480
#define W_NAME "Color Bars"

/* how many color bars are there? */
#define BAR_NUM 8               

const float colors[8][3] = {
    {1,1,1},    /* white */
    {1,1,0},    /* yellow */
    {0,1,1},    /* cyan */
    {0,1,0},    /* green */
    {1,0,1},    /* magenta */
    {1,0,0},    /* red */
    {0,0,1},    /* blue */
    {0,0,0}     /* black */
};

/* draw color bars */
void display() {
    uint8_t bar;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for(bar = 0; bar < BAR_NUM; bar++) {
        glColor3f(colors[bar][0], colors[bar][1], colors[bar][2]);
        glVertex2i(bar * (W_WIDTH/BAR_NUM), 0);
        glVertex2i((bar+1) * (W_WIDTH/BAR_NUM), 0);
        glVertex2i((bar+1) * (W_WIDTH/BAR_NUM), W_HEIGHT);
        glVertex2i(bar * (W_WIDTH/BAR_NUM), W_HEIGHT);
    }
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    init(W_WIDTH, W_HEIGHT, W_NAME, BLACK);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
