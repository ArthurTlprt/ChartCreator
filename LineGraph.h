/* 
 * File:   LineGraph.h
 * Author: isen
 *
 * Created on 20 octobre 2015, 18:50
 */

#ifndef LINEGRAPH_H
#define	LINEGRAPH_H

#include "Point3D.h"
#include "Chart.h"
#include "MyWindow.h"
#include "DataParser.h"
#include <vector>

using namespace std;

class LineGraph: public DataParser {
public:
    LineGraph(float width, float height, Point3D point, string fileName);
    virtual ~LineGraph();
    void draw(MyWindow* win);
    void setHeight(float height);
    float getHeight() const;
    void setWidth(float width);
    float getWidth() const;
    void setBotLeftCorner(Point3D botLeftCorner);
    Point3D getBotLeftCorner() const;
private:
    Point3D botLeftCorner;
    float width;
    float height;
};

#endif	/* LINEGRAPH_H */

