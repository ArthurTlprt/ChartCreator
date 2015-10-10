#ifndef MYDRAWABLE_H
#define	MYDRAWABLE_H
class MyWindow;
#include "MyWindow.h"
class Color;
#include "Color.h"

class MyDrawable {
public:
    MyDrawable();
    MyDrawable(const Color&);
    MyDrawable(const MyDrawable&);
    virtual ~MyDrawable();
    void setColor(int r, int g, int b);
    void setColor(const Color&);
    const Color & getColor() const;
    virtual void draw(MyWindow*) const = 0;
    
private:
    Color c;
};


#endif	/* MYDRAWABLE_H */

