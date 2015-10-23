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
#include "Data1.h"
#include <unistd.h>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
  
    MyWindow* win = MyWindow::createWindow(0, 0, 1400, 800);
/*
    Disc disc0;
    disc0.setRadius(200);
   
    
    disc0.setColor(255, 0, 0);
    disc0.setCenter(Point3D(400, 300, 0));
    win->draw(disc0);
   */
    
    
    BarGraph1 graph0(400, 600, Point3D(600, 600, 0));
    
    Data1* data0 = new Data1(0.75, Color(100, 100, 100));
    Data1* data1 = new Data1(0.15, Color(100, 0, 255));
    Data1* data2 = new Data1(1, Color(255, 100, 100));
    Data1* data3 = new Data1(0.2, Color(25, 150, 100));
    Data1* data4 = new Data1(0.57, Color(255, 150, 10));
    Data1* data5 = new Data1(0.8, Color(255, 255, 100));
    
    graph0.add(data0);
    graph0.add(data1);
    graph0.add(data2);
    graph0.add(data3);
    graph0.add(data4);
    graph0.add(data5);
    
    graph0.draw(win);
 
    usleep(10000000);  
    
    MyWindow::destroyWindow();
    return 0;
    
}


