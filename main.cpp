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
#include "Caption.h"
#include "Data1.h"
#include "DataParser.h"
#include "Line.h"
#include <unistd.h>
#include <iostream>
#include <SDL/SDL_ttf.h>


using namespace std;


int main(int argc, char** argv) {
  
    MyWindow* win = MyWindow::createWindow(0, 0, 1400, 800);

    
    /*
     Graph1
     */
    {
        bool type = true;

        string fileName = "graph0.txt";

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

        string fileName = "graph1.txt";

        BarGraph1 graph1(300, 300, Point3D(500, 650, 0), type, fileName);

        graph1.draw(win);        
    }
    
    /**/
    
                /*
     Graph4
     */
    {
        string fileName = "graph2.txt";

        LineGraph graph4(300, 300, Point3D(600, 350, 0), fileName);

        graph4.draw(win);        
    }
    /**/
    
                    /*
     Graph5
     */
    
    {
        string fileName = "graph0.txt";

        PieChart1 graph5(100, Point3D(1000, 150, 0) ,0 , fileName);

        graph5.draw(win);        
        
    }
    
    /**/
    
                    /*
     Graph6
     */
    
    {
        string fileName = "graph0.txt";
        Point3D center(1250, 150, 0);
        
        PieChart1 graph6(100, center, 50, fileName);

        graph6.draw(win);        
    }
    
    /**/
    
     /*
                     Caption
     */
    
    {
        string fileName = "graph0.txt";
        
        Caption caption(Point3D(1000, 600, 0),20, fileName);
        
        caption.draw(win);
    }
    
    /**/
    //usr/include/SDL/SDL_ttf.h
    
    
    usleep(30000000);  
    
    MyWindow::destroyWindow();
    return 0;
    
}


