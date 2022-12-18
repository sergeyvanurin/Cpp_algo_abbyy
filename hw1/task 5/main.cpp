#include <stdio.h>

class Prism {
    const double height;
public:
    Prism(const double height): height(height) {};
    virtual double Square() const = 0;
    double Volume() const { return height * Square(); }
};

class Box: public Prism {
    double length;
public:
    Box(double height, double length): Prism(height), length(length) {};
    virtual double Square() const { return length * length; }
};

class Cube: public Box {
    double length;
public:
    Cube(double length): Box(length, length) {};
};

int main() {
    const Prism *p, *q, *r;
    Box a(0.5, 2), b(5, 0.2);
    Cube c(0.5);
    p = &a; q = &b; r = &c;
    printf("Squares: %3.3lf %3.3lf %3.3lf\n", p->Square(), q->Square(), r->Square());
    printf("Volumes: %3.3lf %3.3lf %3.3lf\n", p->Volume(), q->Volume(), r->Volume());
    return 0;
}

