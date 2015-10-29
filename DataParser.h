/* 
 * File:   DataParser.h
 * Author: isen
 *
 * Created on 26 octobre 2015, 16:31
 */

#ifndef DATAPARSER_H
#define	DATAPARSER_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "Data1.h"
#include <sstream>

#include "Chart.h"

using namespace std;

class DataParser {
public:
    DataParser(string fileName);
    //DataParser(const DataParser& orig);
    virtual ~DataParser();
private:
    bool stringToFloat(string str, float &f);
    bool stringToInt(string str, int &x);
    Chart chartData;
};

#endif	/* DATAPARSER_H */

