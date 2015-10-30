/* 
 * File:   LineGraph.cpp
 * Author: isen
 * 
 * Created on 20 octobre 2015, 18:50
 */

#include "LineGraph.h"

LineGraph::LineGraph(float width, float height, Point3D point, string fileName): DataParser(fileName) {
    setWidth(width);
    setHeight(height);
    setBotLeftCorner(point);
}

void LineGraph::setHeight(float height) {
    this->height = height;
}

float LineGraph::getHeight() const {
    return height;
}

void LineGraph::setWidth(float width) {
    this->width = width;
}

float LineGraph::getWidth() const {
    return width;
}

void LineGraph::setBotLeftCorner(Point3D botLeftCorner) {
    this->botLeftCorner = botLeftCorner;
}

Point3D LineGraph::getBotLeftCorner() const {
    return botLeftCorner;
}

/*
LineGraph::LineGraph(const LineGraph& orig) {
}*/


void LineGraph::draw(MyWindow* win) {
    
    cout << "largeur " << width + botLeftCorner.getX() << endl;
    cout << "hauteur " << height + botLeftCorner.getY() << endl;
    
    int n = chartData.size();   // n = nb color
    int len = chartData.getDataById(0)->getSize(); // len = nb point
    float width = this->width/n;
    
    cout << "n: " << n << endl;
    cout << "l : " << len << endl;
    
    for(int i=0; i < n; ++i){
        Data1* data = chartData.getDataById(i);
        for(int j=0; j <len-1; ++j){
            
            Point3D pt1( botLeftCorner.getX() + j*width, botLeftCorner.getY() - data->getPrctById(j)*(this->getHeight()), 0);
            
            Point3D pt2( botLeftCorner.getX() + (j+1)*width, botLeftCorner.getY() - data->getPrctById(j+1)*(this->getHeight()), 0);
            
            pt1.print();
            pt2.print();
            
            Line line(pt1, pt2);
            line.setColor(data->GetColor().r, data->GetColor().g, data->GetColor().b);
            win->draw(line);
            
            /*Line line1(Point3D(200, 200, 0), Point3D(500, 500+((j+1)*10*(i+1)), 0));
            line1.setColor(66, 9, 19);
            win->draw(line1);*/
        }
    }
}


LineGraph::~LineGraph() {
}

