/* 
 * File:   Data1.h
 * Author: isen
 *
 * Created on 20 octobre 2015, 22:54
 */

#ifndef DATA1_H
#define	DATA1_H

#include "Color.h"
#include <vector>

class Data1 {
public:
    Data1(float prct, const Color& color);
    Data1(const Data1& orig);
    virtual ~Data1();
    void SetColor(const Color& color);
    Color GetColor() const;
    void addPrct(float prct);
    float getPrctById(int i) const;
    int getSize();
private:
    vector<float>tabPrct;
    //float prct;
    Color color;
};

#endif	/* DATA1_H */

