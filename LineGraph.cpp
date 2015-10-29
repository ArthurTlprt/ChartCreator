/* 
 * File:   LineGraph.cpp
 * Author: isen
 * 
 * Created on 20 octobre 2015, 18:50
 */

#include "LineGraph.h"

LineGraph::LineGraph(float width, float height, Point3D point, string fileName): DataParser(fileName) {
    
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

}


LineGraph::~LineGraph() {
}

