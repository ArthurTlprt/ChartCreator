#ifndef SHAPE_H
#define	SHAPE_H
class MyWindow;
#include "MyWindow.h"

class Shape : public MyDrawable {
private:
    int id;
protected:
    int getId();

public:
    Shape();
    Shape(const Color&);
    Shape(const Shape &);

    virtual void print();
    virtual float getArea() = 0;
    virtual void draw(MyWindow*) const = 0;

    ~Shape();
};

#endif	/* SHAPE_H */