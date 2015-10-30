/* 
 * File:   Andres.h
 * Author: isen
 *
 * Created on 30 octobre 2015, 10:00
 */

#ifndef ANDRES_H
#define	ANDRES_H

//#include "Shape.h"
#include "Point3D.h"
#include <cmath>
#include "Line.h"
#include "Color.h"

class Andres{
public:
    Andres(Point3D center, int radius, Color color);
    //Andres(const Andres& orig);
    virtual ~Andres();
    void draw(MyWindow* win);
    void setCenter(Point3D center);
    void setRadius(int radius);
    float getArea(){return 0;};
private:
    Color color;
    Point3D center;
    int radius;
};

#endif	/* ANDRES_H */

