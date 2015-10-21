/* 
 * File:   Chart.cpp
 * Author: isen
 * 
 * Created on 20 octobre 2015, 18:44
 */

#include "Chart.h"

Chart::Chart() {
}

Chart::Chart(const Chart& orig) {
}

Chart::~Chart() {
}

void Chart::add(Data1* data) {
    tableau.push_back(data);
}
int Chart::size() {
    return tableau.size();
}
