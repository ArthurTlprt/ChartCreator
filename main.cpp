/* 
 * File:   main.cpp
 * Author: Arthur Talpaert
 *  p60132
 *  arthur.talpaert@isen-lille.fr
 * Created on 10 octobre 2015, 15:23
 */

#include "MyWindow.h"
#include "Disc.h"
#include <unistd.h>


int main(int argc, char** argv) {
  
    MyWindow* win = MyWindow::createWindow(0, 0, 1400, 800);

    Disc disc0;
    disc0.setRadius(200);
    
    //usleep(1000000);   // 1 seconds = 1000000 microseconds
    

      disc0.setColor(200, 100, 0);
      disc0.setCenter(Point3D(400, 300, 0));
      win->draw(disc0);
      usleep(50000);  
    
    usleep(100000000);  
    
    MyWindow::destroyWindow();
    return 0;
    
}


