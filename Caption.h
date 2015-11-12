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
#include <SDL/SDL_ttf.h>

using namespace std;

class Caption: public DataParser {
public:
    Caption(Point3D botLeftCorner, float width, string fileName);
    //Caption(const Caption& orig);
    virtual ~Caption();
    void setBotLeftCorner(Point3D botLeftCorner);
    Point3D getBotLeftCorner()const;
    void setWidth(float width);
    float getWidth(){return width;};
    void draw(MyWindow* win);
private:
    Point3D botLeftCorner;
    float width;
};

#endif	/* CAPTION_H */

