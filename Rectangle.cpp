/* 
 * File:   Rectangle.cpp
 * Author: isen
 * 
 * Created on 20 octobre 2015, 11:54
 */

#include "Rectangle.h"

Rectangle::Rectangle(float width, float height) {
    this->width = width;
    this->height = height;
    cout << "Constuction of a Rectangle (" << width << "," <<  height << ")" << endl;
}

float Rectangle::getArea() {
    return width * height;
}

void Rectangle::setHeight(float height) {
    this->height = height;
}

float Rectangle::getHeight() const {
    return height;
}

void Rectangle::setWidth(float width) {
    this->width = width;
}

float Rectangle::getWidth() const {
    return width;
}

void Rectangle::print() {
    Shape::print();
    cout << "WIDTH  : " << width << endl;
    cout << "HEIGHT : " << height << endl;
    cout << "AREA   : " << getArea() << endl;
}

void Rectangle::draw(MyWindow* win) const {
    for(int i = 0; i < this->height; i++){
        for(int j = 0; j < this->width; j++){
            win->putPixel(getBotLeftCorner().getX() + j, getBotLeftCorner().getY() - i, getColor().r, getColor().g, getColor().b);  
        }
    }
}

void Rectangle::setBotLeftCorner(Point3D botLeftCorner) {
    this->botLeftCorner = botLeftCorner;
}

Point3D Rectangle::getBotLeftCorner() const {
    return botLeftCorner;
}

