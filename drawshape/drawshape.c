#include <GL/freeglut_std.h>

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include <drawshape.h>

void init(uint16_t width, uint16_t height, char *name, 
		float red, float green, float blue) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow(name);
    glClearColor(red, green, blue, 0);
    gluOrtho2D(0, width, height, 0);
}

void drawPixel(uint16_t x, uint16_t y, uint16_t red, uint16_t green, uint16_t blue) {
    glBegin(GL_POINTS);
    glPointSize(1);
    glColor3f((float)red/UINT8_MAX, 
              (float)green/UINT8_MAX, 
              (float)blue/UINT8_MAX);
    glVertex2i(x, y);
    glEnd();
}

void drawLinePoly(struct Shape s) {
    uint8_t n = (s.n >= UINT8_MAX) ? UINT8_MAX : s.n;

    /* set mode and color */
    glBegin(GL_LINES);
    glColor3f(s.color[0], s.color[1], s.color[2]);

    for (uint16_t i = 0; i < n; i++) {
        glVertex2i(s.x + s.r * cos((M_TAU*i / n)+s.angle), 
                   s.y + s.r * sin((M_TAU*i / n)+s.angle));
        glVertex2i(s.x + s.r * cos((M_TAU*(i+1) / n)+s.angle), 
                   s.y + s.r * sin((M_TAU*(i+1) / n)+s.angle));
    }
    glEnd();
}

void drawFillPoly(struct Shape s) {
    uint8_t n = (s.n >= UINT8_MAX) ? UINT8_MAX : s.n;
    float n_angle;

    /* set mode and color */
    glBegin(GL_QUADS);
    glColor3f(s.color[0], s.color[1], s.color[2]);
    for (uint16_t i = 0; i < n; i++) {
        n_angle = (M_TAU*i / n) + s.angle;
        glVertex2i(s.x + s.r * cos(n_angle), 
                   s.y + s.r * sin(n_angle));
    }
    glEnd();
}
