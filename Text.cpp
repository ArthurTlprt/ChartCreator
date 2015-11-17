/* 
 * File:   Text.cpp
 * Author: isen
 * 
 * Created on 14 novembre 2015, 12:09
 */

#include "Text.h"

Text::Text(string text, string font, int fontSize, Point3D topLeftCorner) {
    setText(text.c_str());
    setFont(font.c_str());
    setTopLeftCorner(topLeftCorner);
    setFontSize(fontSize);
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

void Text::setFontSize(int fontSize) {
    this->fontSize = fontSize;
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
    win->write(getText(), getFont(), getFontSize(),  getTopLeftCorner().getX() +25, getTopLeftCorner().getY() - 22, getColor().r, getColor().g, getColor().b);
}

void Text::print() {
    cout << "Text::print()" << endl;
    cout << getText() << endl;
}


Text::~Text() {
}

