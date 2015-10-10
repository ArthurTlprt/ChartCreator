#include "Shape.h"
#include "MyDrawable.h"
#include <iostream>
using namespace std;

int Shape::getId() {
    static int idmax = 0;
    return idmax++;
}

Shape::Shape(): MyDrawable(),id(getId()) {
    cout << "Default constructor Shape " << this << endl;
}

Shape::Shape(const Color& c): MyDrawable(c),id(getId()) {
    cout << "Default constructor Shape " << this << endl;
}

Shape::Shape(const Shape & s) : MyDrawable(s), id(s.id) {
    cout << "Copy constructor Shape " << this << endl;
}

void Shape::draw(MyWindow*) const{
    
}

float Shape::getArea() {
    return 0;
}

Shape::~Shape() {
    cout << "Destructor Shape" << this << endl;
}
