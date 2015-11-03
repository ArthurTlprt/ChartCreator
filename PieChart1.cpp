/* 
 * File:   PieChart1.cpp
 * Author: isen
 * 
 * Created on 20 octobre 2015, 18:48
 */

#include "PieChart1.h"

PieChart1::PieChart1(float radius,const Point3D& center,string fileName): DataParser(fileName) {
    setRadius(radius);
    setCenter(center);
}

void PieChart1::draw(MyWindow* win) {
    
}

void PieChart1::setCenter(Point3D center) {
    this->center = center;
}

Point3D PieChart1::getCenter() {
    return center;
}

float PieChart1::getRadius() {
    return radius;
}

void PieChart1::setRadius(float radius) {
    this->radius = radius;
}

void PieChart1::draw(MyWindow* win)const{
    
    float sum, startAngle = 0, endAngle;

    int n = this->size();

    for(unsigned int i = 0; i < n; i++)
         sum += chartData.getDataById(i)->getPrctById(0);

     for(unsigned int i = 0; i < n; i++)
     {
         Color color = chartData.getDataById(i)->GetColor();
         //color = COLORS[(i%15)];
         endAngle = startAngle + ((chartData.getDataById(i)->getPrctById(0))*2*M_PI)/sum;
         for(int r = getRadius(); r <= getRadius(); r++) {
             for(float theta = startAngle; theta <= endAngle; theta += 0.001) {
                 win->putPixel(center.getX()  + r*cos(theta), center.getY() + r*(-sin(theta)), color.r, color.g, color.b);
                 //setPixel(discContainer, (center.getX() + r*cos(theta)), (center.getY() + r*(-sin(theta))), color);
             }
         }
         startAngle = endAngle;
     }
     
}

/*
PieChart1::PieChart1(const PieChart1& orig) {
}*/

PieChart1::~PieChart1() {
}

