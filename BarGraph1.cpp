/* 
 * File:   BarGraph1.cpp
 * Author: isen
 * 
 * Created on 20 octobre 2015, 18:49
 */

#include "BarGraph1.h"
#include "Rectangle.h"

BarGraph1::BarGraph1(float width, float height, Point3D botLeftCorner) {
    this->width = width;
    this->height = height;
    this->botLeftCorner = botLeftCorner;
}

BarGraph1::BarGraph1(const BarGraph1& orig) {
}

BarGraph1::~BarGraph1() {
}

void BarGraph1::SetHeight(float height) {
    this->height = height;
}

float BarGraph1::GetHeight() const {
    return height;
}

void BarGraph1::SetWidth(float width) {
    this->width = width;
}

float BarGraph1::GetWidth() const {
    return width;
}

void BarGraph1::SetBotLeftCorner(Point3D botLeftCorner) {
    this->botLeftCorner = botLeftCorner;
}

Point3D BarGraph1::GetBotLeftCorner() const {
    return botLeftCorner;
}
void BarGraph1::draw(MyWindow* win) {
    int n = 5; // number of rectangle
    float tab[5] = {70, 45, 80, 12, 66};
    float width = this->width/n;
    for(int i = 0; i < n; i++){
        Rectangle rect(width, this->height*(tab[i]/100));
        rect.setBotLeftCorner(Point3D(this->GetBotLeftCorner().getX()+(width*i) , this->GetBotLeftCorner().getX(), 0));
        rect.setColor(i*21,255-(i*21), i*21);
        win->draw(rect);
    }
}

