#include "Point3D.h"
#include <cmath>
#include <iostream>
using namespace std;


int Point3D::count = 0;

Point3D::Point3D() : x(0), y(0), z(0) {
    Point3D::count++;
    //cout << "Default constructor Point3D " << this << endl;
};

Point3D::Point3D(float x, float y, float z) : x(0), y(0), z(0) {
    moveTo(x, y, z);
    Point3D::count++;
    //cout << "Constructor Point3D " << this << endl;
};

Point3D::Point3D(const Point3D & p) : x(0), y(0), z(0) {
    moveTo(p);
    Point3D::count++;
    //cout << "Copy Constructor Point3D " << this << endl;
};

void Point3D::reset() {
    x = 0;
    y = 0;
    z = 0;
}; //remet le point sur (0,0,0)

float Point3D::moveTo(const Point3D& p) {
    return moveTo(p.x, p.y, p.z);
}; //déplacement vers un point_retourne la distance parcourue

float Point3D::moveTo(float x, float y, float z) {
    float l = sqrt((this->x - x)*(this->x - x) + (this->y - y)*(this->y - y) + (this->z - z)*(this->z - z));
    this->x = x;
    this->y = y;
    this->z = z;
    return l;
}; //déplacement d'une distance_retourne la distance parcourue

void Point3D::decr() {
    x--;
    y--;
    z--;
}; //décrémente toutes les coordonnées à -1

void Point3D::incr() {
    x++;
    y++;
    z++;
}; //incrémente toutes les coordonnées à +1

void Point3D::print() const {
    cout << "(" << x << "," << y << "," << z << ")"<< endl;
}; //affiche un point sous la forme (x,y,z) - couleur

const float & Point3D::getX() const {
    return x;
};

const float & Point3D::getY() const {
    return y;
};

const float & Point3D::getZ() const {
    return z;
};

int Point3D::getCount() {
    return Point3D::count;
}

Point3D::~Point3D() {
    //cout << "Destructor Point3D " << this << endl;
}
