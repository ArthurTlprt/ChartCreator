/* 
 * File:   BarGraph1.cpp
 * Author: isen
 * 
 * Created on 20 octobre 2015, 18:49
 */

#include "BarGraph1.h"
#include "Rectangle.h"

BarGraph1::BarGraph1(float width, float height, Point3D botLeftCorner, bool type, const Chart& chart): Chart(chart){
    this->type = type;
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
    
    int n = Chart::size();
    int len = tableau[0]->getSize();
    
     float width, height;
    // type : true = vertical, false = horizontal
    if(this->type == true){
        width = this->width/(n*len);
        
        for(int j = 0; j < len; j++){
            for(int i = 0; i < n; i++){

                Data1* data = tableau[i];
                Rectangle rect( width,  (this->height)*(data->getPrctById(j)) );
                rect.setColor( data->GetColor().r , data->GetColor().g, data->GetColor().b );
                if(i == 0 && j != 0){
                    rect.setBotLeftCorner(Point3D(this->GetBotLeftCorner().getX()+(width*(j*n+i+1)) , this->GetBotLeftCorner().getY(), 0));
                }else{
                    rect.setBotLeftCorner(Point3D(this->GetBotLeftCorner().getX()+(width*(j*n+i)) , this->GetBotLeftCorner().getY(), 0));
                }
                win->draw(rect);
            }
        }
        
    }else{
        height = this->height/(n*len);
        
        for(int j = 0; j < len; j++){
            float prevWidth = 0;
            for(int i = 0; i < n; i++){
                Data1* data = tableau[i];
                Rectangle rect( (this->width)*(data->getPrctById(j)) ,  height );
                prevWidth += (this->width)*(data->getPrctById(j));
                rect.setColor( data->GetColor().r , data->GetColor().g, data->GetColor().b );
                
                rect.setBotLeftCorner(Point3D( (this->GetBotLeftCorner().getX()) + prevWidth - (this->width)*(data->getPrctById(j)), this->GetBotLeftCorner().getY()+((height)*(2*(j+1))), 0));
                win->draw(rect);
            }
        }
        
    }
     
}

