/* 
 * File:   Data1.cpp
 * Author: isen
 * 
 * Created on 20 octobre 2015, 22:54
 */

#include "Data1.h"

Data1::Data1() {
}

Data1::Data1(const Data1& orig) {
}

Data1::~Data1() {
}

void Data1::SetColor(Color color) {
    this->color = color;
}

Color Data1::GetColor() const {
    return color;
}

void Data1::SetPrct(float prct) {
    this->prct = prct;
}

float Data1::GetPrct() const {
    return prct;
}

