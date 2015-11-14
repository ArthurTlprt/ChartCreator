/* 
 * File:   Text.cpp
 * Author: isen
 * 
 * Created on 14 novembre 2015, 12:09
 */

#include "Text.h"

Text::Text(string text, string font, Point3D topLeftCorner) {
    setText(text.c_str());
    setFont(font.c_str());
    setTopLeftCorner(topLeftCorner);
}

void Text::setTopLeftCorner(Point3D topLeftCorner) {
    this->topLeftCorner = topLeftCorner;
}

Point3D Text::getTopLeftCorner() const {
    return topLeftCorner;
}

void Text::setFont(string font) {
    this->font = font;
}

string Text::getFont() const {
    return font;
}

void Text::setText(string text) {
    this->text = text;
}

string Text::getText() const {
    return text;
}

Text::Text(const Text& orig) {
}

void Text::draw(MyWindow* win) const {
    win->write(getText(), getFont(), getTopLeftCorner().getX(), getTopLeftCorner().getY());
}

void Text::print() {
    cout << "Text::print()" << endl;
    cout << getText() << endl;
}


Text::~Text() {
}

