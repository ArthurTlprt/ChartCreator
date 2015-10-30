/* 
 * File:   Andres.cpp
 * Author: isen
 * 
 * Created on 30 octobre 2015, 10:00
 */

#include "Andres.h"

Andres::Andres(Point3D center, int radius, Color color) {
    setCenter(center);
    setRadius(radius);
    this->color = color;
}
/*
Andres::Andres(const Andres& orig) {
}*/

Andres::~Andres() {
}

void Andres::setCenter(Point3D center) {
    this->center = center;
}

void Andres::setRadius(int radius) {
    this->radius = radius;
}


void Andres::draw(MyWindow* win){
    
    /*for(int r = this->radius; r >= 0; r--){
        
        int x = 0;
        int y = r;
        int d = r - 1;

        while(y >= x){
            win->putPixel(this->center.getX() + x, this->center.getY() + y, getColor().r, getColor().g, getColor().b);
            if(d >= 2*x){
                d = d-2*x-1;
                x = x+1;
            }else if(d < 2*(r-y)){
                d = d+2*y-1;
                y = y-1;
            }else{
                d = d+2*(y-x-1);
                y = y-1;
                x = x+1;
            }
         }
    }*/     
    int prec = 360;
    float theta = (2*M_PI)/prec;
    for(int i = 0; i < prec; ++i){
        Point3D pt(center.getX() + floor(radius*(cos(i*theta))), center.getY() + floor(radius*(sin(i*theta))), 0);
        pt.print();
        
        Line line(center, pt);
        line.setColor(color.r, color.g, color.b);
        cout << line.getColor().r << endl;
        cout << line.getColor().g << endl;
        cout << line.getColor().b << endl;
        //line.setColor(color.r, color.g, color.b);
        win->draw(line);
    }
}
