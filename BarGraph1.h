/* 
 * File:   BarGraph1.h
 * Author: isen
 *
 * Created on 20 octobre 2015, 18:49
 */

#ifndef BARGRAPH1_H
#define	BARGRAPH1_H

#include "Point3D.h"
#include "Chart.h"
#include "MyWindow.h"
#include <vector>
//#include "Data1.h"

using namespace std;

class BarGraph1: public Chart {
public:
    BarGraph1(float width, float height, Point3D botLeftCorner, bool type);
    BarGraph1(const BarGraph1& orig);
    virtual ~BarGraph1();
    void SetHeight(float height);
    float GetHeight() const;
    void SetWidth(float width);
    float GetWidth() const;
    void SetBotLeftCorner(Point3D botLeftCorner);
    Point3D GetBotLeftCorner() const;
    void draw(MyWindow* win);
private:
    bool type; // true = vertical, false = horizontal
    Point3D botLeftCorner;
    float width;
    float height;
};

#endif	/* BARGRAPH1_H */

