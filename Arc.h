/* 
 * File:   Arc.h
 * Author: isen
 *
 * Created on 3 novembre 2015, 17:50
 */

#ifndef ARC_H
#define	ARC_H

#include "Point3D.h"
#include "Shape.h"
#include <cmath>
#include "Line.h"

class Arc : public Shape{
public:
    Arc(float radius, float startAngle, float endAngle, Point3D center,float endRadius);
    Arc(const Arc& orig);
    virtual ~Arc();
    void draw(MyWindow*) const;
    float getArea();
    float getRadius()const;
    float getStartAngle()const;
    float getEndAngle()const;
    Point3D getCenter()const;
private:
    float radius;
    float startAngle;
    float endAngle;
    Point3D center;
    float endRadius;
};

#endif	/* ARC_H */

