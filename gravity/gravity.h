#ifndef GRAVITY_H_
#define GRAVITY_H_

#define G 6.67E-11

struct vector {
    float angle, size;
};

struct object {
    float x, y;
    float mass;
};

#endif
