/* 
 * File:   Arc.cpp
 * Author: isen
 * 
 * Created on 3 novembre 2015, 17:50
 */

#include "Arc.h"

Arc::Arc(float radius, float startAngle, float endAngle, Point3D center,float endRadius) {
    this->radius = radius;
    this->startAngle = startAngle;
    this->endAngle = endAngle;
    this->center  = center;
    this->endRadius = endRadius;
}

Arc::Arc(const Arc& orig) {
}

Arc::~Arc() {
}

float Arc::getArea(){
    return -1;
}


float Arc::getRadius()const {
    return this->radius;
}
Point3D Arc::getCenter()const {
    return this->center;
}

float Arc::getStartAngle()const {
    return this->startAngle;
}
float Arc::getEndAngle()const {
    return this->endAngle;
}

void Arc::draw(MyWindow* win) const {
    for(int r = getRadius(); r > endRadius; r--) {
        for(float theta = getStartAngle(); theta <= getEndAngle(); theta += 0.001) {
            win->putPixel(getCenter().getX()  + r*cos(theta), getCenter().getY() + r*(-sin(theta)), getColor().r, getColor().g, getColor().b);
            //setPixel(discContainer, (center.getX() + r*cos(theta)), (center.getY() + r*(-sin(theta))), color);
        }
    }
}

