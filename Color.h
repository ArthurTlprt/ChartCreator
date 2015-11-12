#ifndef COLOR_H
#define	COLOR_H

#include <iostream>
using namespace std;

class Color {
public:
    int r;
    int g;
    int b;

    Color() : r(0), g(0), b(0) {
        //cout << "Default Constructor Color " << this << endl;
    };

    Color(int r, int g, int b) : r(r), g(g), b(b) {
        //cout << "Constructor Color " << this << endl;
    };

    Color(const Color & c) : r(c.r), g(c.g), b(c.b) {
        //cout << "Copy constructor Color " << this << endl;
    };

    void setColor(int r, int g, int b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    void setColor(const Color & c) {
        r = c.r;
        g = c.g;
        b = c.b;
    }

    void print() {
        cout << "Color: (" << r << ";" << g << ";" << b << ")" << endl;
    }

    ~Color() {
        //cout << "Destructor Color " << this << endl;
    };
};

#endif	/* COLOR_H */


