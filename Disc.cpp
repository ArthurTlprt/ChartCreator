#include "Disc.h"
#include <iostream>
using namespace std;

Disc::Disc() : Shape(), radius(1) {
    cout << "Disc: Default constructor " << this << endl;
}

Disc::Disc(float x, float y, float z) : Shape(), radius(1), center(x, y, z) {
    cout << "Disc: constructor " << this << endl;
}

Disc::Disc(float radius, const Point3D & center, const Color & color) : Shape(color), radius(radius), center(center) {
    cout << "Disc: constructor " << this << endl;

}

Disc::Disc(const Disc& disc) : Shape(disc), radius(disc.radius), center(disc.center) {
    cout << "Disc: copy constructor " << this << endl;
}

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
            if((i * i + j * j) <= (radius * radius)){
                /*if( i >0  && j < 0){
                    win->putPixel(center.getX() + i, center.getY() + j,0 ,100 , 200);
                }*/
                Point3D A(center.getX(), center.getY(), 0);
                Point3D B(radius, 0, 0); 
                Point3D C(radius*cos(M_PI/4), radius* sin(M_PI/4), 0);
                for(int k = 0; k <= sin(M_PI/4); k++){
                    if(i == radius*cos(M_PI/4) && j == radius*sin(M_PI/4) - k){
                        win->putPixel(center.getX() + i, center.getY() + j,255 ,255 , 255);
                    }
                }
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
