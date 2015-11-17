/* 
 * File:   Line.h
 * Author: isen
 *
 * Created on 29 octobre 2015, 17:43
 */

#ifndef LINE_H
#define	LINE_H

#include "Point3D.h"
#include "Shape.h"
#include <math.h>
#include <cstdlib>



class Line: public Shape {
public:
    Line(Point3D pt1, Point3D pt2);
    void draw(MyWindow*) const;
    float getArea();

    virtual ~Line();
private:
    Point3D pt1;
    Point3D pt2;
};

#endif	/* LINE_H */

