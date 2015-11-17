#include "SDL/SDL.h"

#ifndef MYWINDOW_H
#define	MYWINDOW_H

class MyDrawable;
#include "MyDrawable.h"
#include <string>

using namespace std;


class MyWindow {
private:
    /*Taille de l'image*/
    int x;
    int y;
    int width;
    int height;
    
    /*SDL*/
    SDL_Surface * surface;
    SDL_Surface* sdlWindow;
    
    MyWindow(int x, int y, int width, int height);
    ~MyWindow();
    Uint32 getPixel(SDL_Surface *surface, int x, int y);
    void setPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
    
    static MyWindow* window;

public:
    void draw(const MyDrawable&);
    /* dessine un pixel a l'ecran */
    void putPixel(int, int, unsigned char, unsigned char, unsigned char);
    /* ecrit du texte */
    void write(string text, string font,int fontSize, int x, int y,  unsigned char, unsigned char, unsigned char);
    /* Efface la fenetre courante */
    void clearGraph();
    /* Ferme la fenetre graphique */
    static void destroyWindow();
    /*getters*/
    int getWidth();
    int getHeight();
    /* Ouvre une fenetre graphique, en (x,y) de largeur width et de hauteur height */
    static MyWindow* createWindow(int x, int y, int width, int height);
};

#endif	/* MYDRAWABLE_H */
