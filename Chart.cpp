/* 
 * File:   Chart.cpp
 * Author: isen
 * 
 * Created on 20 octobre 2015, 18:44
 */

#include "Chart.h"
#include <iostream>

using namespace std;

Chart::Chart() {
}

Chart::Chart(const Chart& orig) {
}

Chart::~Chart() {
    for(unsigned int i = 0; i < size(); ++i){
        delete getDataById(i);
    }
}

void Chart::add(Data1 * data) {
    tableau.push_back(data);
}

Data1* Chart::getDataById(int id) {
    return tableau[id];
}

int Chart::size()const {
    return tableau.size();
}
