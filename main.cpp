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
#include "PieChart1.h"
#include "PieChart2.h"
#include "LineGraph.h"
#include "Data1.h"
#include "DataParser.h"
#include <unistd.h>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
  
    MyWindow* win = MyWindow::createWindow(0, 0, 1400, 800);

    
    /*
     Graph1
     */
    {
        bool type = true;

        string fileName = "graph1.txt";

        BarGraph1 graph1(300, 400, Point3D(100, 650, 0), type, fileName);

        graph1.draw(win);
    }
    
    /**/
    
        /*
     Graph2
     */
    {
        bool type = false;

        string fileName = "graph1.txt";

        BarGraph1 graph1(100, 300, Point3D(100, 100, 0), type, fileName);

        graph1.draw(win);        
    }
    
    /**/
    
            /*
     Graph3
     */
    {
        bool type = true;

        string fileName = "graph0.txt";

        BarGraph1 graph1(300, 300, Point3D(500, 650, 0), type, fileName);

        graph1.draw(win);        
    }
    
    /**/
    
    
    usleep(30000000);  
    
    MyWindow::destroyWindow();
    return 0;
    
}


