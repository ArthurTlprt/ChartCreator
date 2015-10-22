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
    //Data1* data0 = new Data1(75, Color(100, 100, 100));
    //tableau.push_back(data0);
}

Chart::Chart(const Chart& orig) {
}

Chart::~Chart() {
}

void Chart::add(Data1 * data) {
    tableau.push_back(data);
    cout << "push_back some data" << endl;
}
int Chart::size() {
    return tableau.size();
}
