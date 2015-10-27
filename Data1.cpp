/* 
 * File:   Data1.cpp
 * Author: isen
 * 
 * Created on 20 octobre 2015, 22:54
 */

#include "Data1.h"

Data1::Data1(){
    
}

Data1::Data1(float prct, const Color& color) {
    this->tabPrct.push_back(prct);
    this->color.setColor(color);
}

Data1::Data1(const Data1& orig) {
}

Data1::~Data1() {
}

void Data1::SetColor(const Color& color) {
    this->color.setColor(color);
}

Color Data1::GetColor() const {
    return color;
}

void Data1::addPrct(float prct) {
    this->tabPrct.push_back(prct);
}

float Data1::getPrctById(int i) const {
    return this->tabPrct[i];
}

int Data1::getSize() {
    return this->tabPrct.size();
}

void Data1::SetName(string name) {
    this->name = name;
}

string Data1::GetName() const {
    return name;
}


