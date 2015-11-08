/* 
 * File:   Chart.h
 * Author: isen
 *
 * Created on 20 octobre 2015, 18:44
 */

#ifndef CHART_H
#define	CHART_H

#include <vector>
#include "Data1.h"

class Chart {
public:
    Chart();
    Chart(const Chart& orig);
    virtual ~Chart();
    void add(Data1 * data);
    Data1* getDataById(int id);
    int size()const;
protected:
    vector<Data1*>tableau;
};

#endif	/* CHART_H */

