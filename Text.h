/* 
 * File:   Text.h
 * Author: isen
 *
 * Created on 14 novembre 2015, 12:09
 */

#ifndef TEXT_H
#define	TEXT_H
#include "MyDrawable.h"
#include "Point3D.h"
#include <iostream>
#include <string>

using namespace std;

class Text: public MyDrawable {
public:
    Text(string text, string font, Point3D topLeftCorner);
    Text(const Text& orig);
    virtual ~Text();

    void draw(MyWindow*) const;
    void setTopLeftCorner(Point3D topLeftCorner);
    Point3D getTopLeftCorner() const;
    void setFont(string font);
    string getFont() const;
    void setText(string text);
    string getText() const;
    void print();
private:
    string text;
    string font;
    Point3D topLeftCorner;
};

#endif	/* TEXT_H */

