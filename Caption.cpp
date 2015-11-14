/* 
 * File:   Caption.cpp
 * Author: isen
 * 
 * Created on 9 novembre 2015, 20:25
 */

#include "Caption.h"

Caption::Caption( Point3D botLeftCorner, float width, string fileName, string font):DataParser(fileName) {
    setBotLeftCorner(botLeftCorner);
    setWidth(width);
    setFont(font);
}

/**
Caption::Caption(const Caption& orig) {
}*/

void Caption::draw(MyWindow* win) {
    
    
    
    int n = chartData.size();   // n = nb color
    //cout << "il y a " << n << endl;
     
    for(int i=0; i<n; ++i){
        
        Rectangle square(getWidth(), getWidth());
        Point3D pt( getBotLeftCorner().getX(), getBotLeftCorner().getY() - getWidth() * 2 * i, 0) ;
        square.setBotLeftCorner( pt );
        
        //cout << "carré" << endl;
        //square.getBotLeftCorner().print();
        Data1* data = chartData.getDataById(i);
        
        Text txt( data->GetName(), font, pt);
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



Point3D Caption::getBotLeftCorner() const {
    return botLeftCorner;
}

void Caption::setWidth(float width) {
    this->width = width;
}

