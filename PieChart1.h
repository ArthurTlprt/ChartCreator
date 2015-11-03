/* 
 * File:   PieChart1.h
 * Author: isen
 *
 * Created on 20 octobre 2015, 18:48
 */

#ifndef PIECHART1_H
#define	PIECHART1_H

#include "Point3D.h"
#include "Chart.h"
#include "MyWindow.h"
#include "DataParser.h"
#include "Shape.h"
#include <vector>
#include <cmath>

using namespace std;

class PieChart1: public DataParser, public Shape {
public:
    PieChart1(float radius,const Point3D& center,string fileName);
    //PieChart1(const PieChart1& orig);
    virtual ~PieChart1();
    void setCenter(Point3D center);
    Point3D getCenter();
    void setRadius(float radius);
    float getRadius();
    void draw(MyWindow*) const;
private:
    Point3D center;
    float radius;
};

#endif	/* PIECHART1_H */

