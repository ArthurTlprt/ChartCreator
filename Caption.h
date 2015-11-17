/* 
 * File:   Caption.h
 * Author: isen
 *
 * Created on 9 novembre 2015, 20:25
 */

#ifndef CAPTION_H
#define	CAPTION_H

#include "Point3D.h"
#include "MyWindow.h"
#include "DataParser.h"
#include "Rectangle.h"
#include "Text.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

using namespace std;

class Caption: public DataParser {
public:
    Caption(Point3D botLeftCorner, float width, string fileName, string font, int fontSize);
    virtual ~Caption();
    void setBotLeftCorner(Point3D botLeftCorner);
    Point3D getBotLeftCorner()const;
    void setWidth(float width);
    void setFont(string font);
    string getFont()const;
    void setFontSize(int fontSize);
    int getFontSize()const{return fontSize;};
    float getWidth(){return width;};
    void draw(MyWindow* win);
private:
    string font;
    Point3D botLeftCorner;
    float width;
    int fontSize;
};

#endif	/* CAPTION_H */

