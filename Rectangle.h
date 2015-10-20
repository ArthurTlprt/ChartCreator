/* 
 * File:   Rectangle.h
 * Author: isen
 *
 * Created on 20 octobre 2015, 11:54
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

class Point3D;

#include "Point3D.h"
#include "Shape.h"
#include <cmath>

class Rectangle: public Shape {
public:
    Rectangle(float width = 0, float height = 0);

    void print();
    float getArea();
    void setHeight(float height);
    float getHeight() const;
    void setWidth(float width);
    float getWidth() const;
    void draw(MyWindow*) const;
    void setBotLeftCorner(Point3D botLeftCorner);
    Point3D getBotLeftCorner() const;
private:
    Point3D botLeftCorner;
    float width;
    float height;
};

#endif	/* RECTANGLE_H */

