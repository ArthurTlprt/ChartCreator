#include "MyDrawable.h"
#include "MyWindow.h"
#include<iostream>
using namespace std;


MyDrawable::MyDrawable():c(0,0,0) {
    //cout << "MyDrawable: default constructor " << this << endl;
}

MyDrawable::MyDrawable(const Color& c):c(c) {
    //cout << "MyDrawable: color constructor " << this << endl;
}

MyDrawable::MyDrawable(const MyDrawable& myd):c(myd.c){
    //cout << "MyDrawable: copy constructor " << this << endl;
}

MyDrawable::~MyDrawable() {
    //cout << "MyDrawable: Destructor " << this << endl;
}

void MyDrawable::setColor(const Color& c) {
    this->c.setColor(c);
}

const Color & MyDrawable::getColor() const {
    return c;
}

void MyDrawable::setColor(int r, int g, int b) {
    this->c.setColor(r,g,b);
}

