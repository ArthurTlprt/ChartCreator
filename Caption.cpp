/* 
 * File:   Caption.cpp
 * Author: isen
 * 
 * Created on 9 novembre 2015, 20:25
 */

#include "Caption.h"

Caption::Caption( Point3D botLeftCorner, float width, string fileName, string font, int fontSize):DataParser(fileName) {
    setBotLeftCorner(botLeftCorner);
    setWidth(width);
    setFont(font);
    setFontSize(fontSize);
}

void Caption::draw(MyWindow* win) {
    
    
    
    int n = chartData.size();   // n = nb color
     
    for(int i=0; i<n; ++i){
        
        Rectangle square(getWidth(), getWidth());
        Point3D pt( getBotLeftCorner().getX(), getBotLeftCorner().getY() - getWidth() * 2 * i, 0) ;
        square.setBotLeftCorner( pt );

        Data1* data = chartData.getDataById(i);
        
        Text txt( data->GetName(), font, getFontSize(),  pt);
        win->draw(txt);
        square.setColor(data->GetColor());
        win->draw(square);
    }
}

Caption::~Caption() {
}

void Caption::setBotLeftCorner(Point3D botLeftCorner) {
    this->botLeftCorner = botLeftCorner;
}

void Caption::setFont(string font) {
    this->font = font;
}

string Caption::getFont() const {
    return this->font;
}

void Caption::setFontSize(int fontSize) {
    this->fontSize = fontSize;
}


Point3D Caption::getBotLeftCorner() const {
    return botLeftCorner;
}

void Caption::setWidth(float width) {
    this->width = width;
}

