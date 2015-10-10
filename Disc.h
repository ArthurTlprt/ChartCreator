#ifndef DISC_H
#define	DISC_H

class Point3D;

#include "Point3D.h"
#include "Shape.h"

class Disc : public Shape{
private:
    Point3D center;
    float radius;

public:
    Disc();
    Disc(float,float,float);
    Disc(float radius,const Point3D& center,const Color & color);
    Disc(const Disc&);
    const float & getRadius();
    void setRadius(const float &);
    const Point3D & getCenter();
    void setCenter(const Point3D &);

    // shape part
    void draw(MyWindow*) const;
    float getArea();
    
    ~Disc();
};

#endif	/* DISC_H */

