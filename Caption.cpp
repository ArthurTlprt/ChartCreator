/* 
 * File:   Caption.cpp
 * Author: isen
 * 
 * Created on 9 novembre 2015, 20:25
 */

#include "Caption.h"

Caption::Caption( Point3D botLeftCorner, float width, string fileName):DataParser(fileName) {
    setBotLeftCorner(botLeftCorner);
    setWidth(width);
}

/**
Caption::Caption(const Caption& orig) {
}*/

void Caption::draw(MyWindow* win) {
    
    TTF_Init();
    if(TTF_Init() == -1)
    {
        cout << "ttf error" << endl;
        exit(EXIT_FAILURE);
    }else{
        cout << "ttf works!!!!!!!!!" << endl;
    }
    TTF_Quit();
    
    int n = chartData.size();   // n = nb color
    cout << "il y a " << n << endl;
     
    for(int i=0; i<n; ++i){
        Rectangle square(getWidth(), getWidth());
        square.setBotLeftCorner(Point3D( getBotLeftCorner().getX(), getBotLeftCorner().getY() - getWidth() * 2 * i, 0));
        cout << "carré" << endl;
        square.getBotLeftCorner().print();
        Data1* data = chartData.getDataById(i);
        
        square.setColor(data->GetColor());
        win->draw(square);
    }
    
    //TTF_Quit();
}

Caption::~Caption() {
}

void Caption::setBotLeftCorner(Point3D botLeftCorner) {
    this->botLeftCorner = botLeftCorner;
}

Point3D Caption::getBotLeftCorner() const {
    return botLeftCorner;
}

void Caption::setWidth(float width) {
    this->width = width;
}

