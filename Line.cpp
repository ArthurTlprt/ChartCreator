/* 
 * File:   Line.cpp
 * Author: isen
 * 
 * Created on 29 octobre 2015, 17:43
 */

#include "Line.h"


Line::Line(Point3D pt1, Point3D pt2) {
    this->pt1 = pt1;
    this->pt2 = pt2;
}

float Line::getArea() {
    return 0.0;
}

void Line::draw(MyWindow* win) const {
    float x1 = pt1.getX();
    float y1 = pt1.getY();
    float x2 = pt2.getX();
    float y2 = pt2.getY();
    
    
    int delta_x(x2 - x1);
    signed char const ix((delta_x > 0) - (delta_x < 0));
    delta_x = std::abs(delta_x) << 1;
 
    int delta_y(y2 - y1);
    signed char const iy((delta_y > 0) - (delta_y < 0));
    delta_y = std::abs(delta_y) << 1;
 
    win->putPixel(x1, y1, getColor().r, getColor().g, getColor().b);
 
    if (delta_x >= delta_y)
    {
        int error(delta_y - (delta_x >> 1));
 
        while (x1 != x2)
        {
            if ((error >= 0) && (error || (ix > 0)))
            {
                error -= delta_x;
                y1 += iy;
            }
 
            error += delta_y;
            x1 += ix;
 
            win->putPixel(x1, y1, getColor().r, getColor().g, getColor().b);
        }
    }
    else
    {
        int error(delta_x - (delta_y >> 1));
 
        while (y1 != y2)
        {
            if ((error >= 0) && (error || (iy > 0)))
            {
                error -= delta_y;
                x1 += ix;
            }
            error += delta_x;
            y1 += iy;
 
            win->putPixel(x1, y1, getColor().r, getColor().g, getColor().b);
        }
    }
    
}

Line::~Line() {
}

