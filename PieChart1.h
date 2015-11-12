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
#include "Arc.h"
#include "Disc.h"
#include <vector>
#include <cmath>

using namespace std;

class PieChart1: public DataParser{
public:
    PieChart1(float radius,const Point3D& center,float endRadius,string fileName);
    //PieChart1(const PieChart1& orig);
    virtual ~PieChart1();
    void setCenter(Point3D center);
    Point3D getCenter();
    void setRadius(float radius);
    float getRadius();
    float getEndRadius();
    void draw(MyWindow* win);
private:
    Point3D center;
    float radius;
    float endRadius;
};

#endif	/* PIECHART1_H */

