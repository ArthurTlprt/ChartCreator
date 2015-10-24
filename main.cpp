/* 
 * File:   main.cpp
 * Author: Arthur Talpaert
 *  p60132
 *  arthur.talpaert@isen-lille.fr
 * Created on 10 octobre 2015, 15:23
 */

#include "MyWindow.h"
#include "Disc.h"
#include "Rectangle.h"
#include "BarGraph1.h"
#include "BarGraph2.h"
#include "BarGraph3.h"
#include "PieChart1.h"
#include "PieChart2.h"
#include "LineGraph.h"
#include "Data1.h"
#include <unistd.h>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
  
    MyWindow* win = MyWindow::createWindow(0, 0, 1400, 800);

    
    /*
     Graph2
     */
    
    bool type = false;
    
    BarGraph1 graph1(200, 900, Point3D(100, 100, 0), type);
    
    Data1* data0 = new Data1(0.75, Color(100, 100, 100));
    Data1* data1 = new Data1(0.15, Color(100, 0, 255));
    Data1* data2 = new Data1(1, Color(255, 100, 100));
    Data1* data3 = new Data1(0.2, Color(25, 150, 100));
    Data1* data4 = new Data1(0.57, Color(255, 150, 10));
    Data1* data5 = new Data1(0.8, Color(255, 255, 100));
    
    
    
    graph1.add(data0);
    graph1.add(data1);
    graph1.add(data2);
    graph1.add(data3);
    graph1.add(data4);
    graph1.add(data5);
    
    //graph1.draw(win);
    
    /*
     Fin BarGraph1
     */
    
    
    /*
     * Graph 2
     */
    
    data0->addPrct(0.3);
    data1->addPrct(0.8);
    data2->addPrct(0.12);
    data3->addPrct(0.7);
    data4->addPrct(0.23);
    data5->addPrct(0.6);
    
    data0->addPrct(0.3);
    data1->addPrct(0.8);
    data2->addPrct(0.12);
    data3->addPrct(0.7);
    data4->addPrct(0.23);
    data5->addPrct(0.6);
    
    data0->addPrct(0.3);
    data1->addPrct(0.8);
    data2->addPrct(0.12);
    data3->addPrct(0.7);
    data4->addPrct(0.23);
    data5->addPrct(0.6);
    
    data0->addPrct(0.3);
    data1->addPrct(0.8);
    data2->addPrct(0.12);
    data3->addPrct(0.7);
    data4->addPrct(0.23);
    data5->addPrct(0.6);
    
    data0->addPrct(0.3);
    data1->addPrct(0.8);
    data2->addPrct(0.12);
    data3->addPrct(0.7);
    data4->addPrct(0.23);
    data5->addPrct(0.6);
    
    data0->addPrct(0.3);
    data1->addPrct(0.8);
    data2->addPrct(0.12);
    data3->addPrct(0.7);
    data4->addPrct(0.23);
    data5->addPrct(0.6);
    
    graph1.draw(win);
  
    /*
     * Fin graph2
     */
    
    
    
    
    usleep(10000000);  
    
    MyWindow::destroyWindow();
    return 0;
    
}


