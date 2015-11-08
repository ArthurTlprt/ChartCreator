#include "Disc.h"
#include <iostream>
using namespace std;


Disc::Disc() : Shape(), radius(1) {
    cout << "Disc: Default constructor " << this << endl;
}

Disc::Disc(float x, float y, float z) : Shape(), radius(1), center(x, y, z) {
    
    cout << "Disc: constructor " << this << endl;
}

Disc::Disc(float radius, const Point3D & center, const Color & color) : Shape(color), radius(radius), center(center){
    cout << "Disc: constructor " << this << endl;

}
/*
Disc::Disc(const Disc& disc) : Shape(disc), radius(disc.radius), center(disc.center) {
    cout << "Disc: copy constructor " << this << endl;
}*/

const float & Disc::getRadius() {
    return radius;
}

void Disc::setRadius(const float & r) {
    radius = r;
}

const Point3D & Disc::getCenter() {
    return center;
};

void Disc::setCenter(const Point3D & c) {
    center.moveTo(c);
};

void Disc::draw(MyWindow* win) const {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {

            if ((i * i + j * j) <= (radius * radius) && !(i >0 && j > 0)) {
                //cout << "(" << i << ";" << j << ")" << endl;
                win->putPixel(center.getX() + i, center.getY() + j, getColor().r, getColor().g, getColor().b);
            }
        }
    }
}



float Disc::getArea() {
    return 3.14957 * radius * radius;
}

Disc::~Disc() {
    cout << "Disc: destructor " << this << endl;
}
