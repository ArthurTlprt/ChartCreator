#include "MyWindow.h"
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <iostream>
#include <SDL/SDL_ttf.h>
using namespace std;

/*Suivant l'architecture de la machine, deux manières d'enregistrer des données en mémoire*/
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
#define MASQUE_ROUGE 0xff000000
#define MASQUE_VERT  0x00ff0000
#define MASQUE_BLEU  0x0000ff00
#define MASQUE_ALPHA 0x000000ff
#else
#define MASQUE_ROUGE 0x000000ff
#define MASQUE_VERT  0x0000ff00
#define MASQUE_BLEU  0x00ff0000
#define MASQUE_ALPHA 0xff000000
#endif

MyWindow::MyWindow(int x, int y, int width, int height) {
    //cout << "Constructor MyWindow" << endl;
    this->width = width;
    this->height = height;
    
    /*On initialise la SDL.*/
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Chart creator", "Chart creator");

    surface = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height, 32, MASQUE_ROUGE, MASQUE_VERT, MASQUE_BLEU, MASQUE_ALPHA);
    sdlWindow = SDL_SetVideoMode(width, height, 32, SDL_ANYFORMAT | SDL_HWSURFACE);
}

MyWindow::~MyWindow() {
    //Free the loaded image
    SDL_FreeSurface(sdlWindow);
    SDL_FreeSurface(surface);
    SDL_Quit();
    //cout << "Destructor MyWindow" << endl;
}

void MyWindow::draw(const MyDrawable& drawable) {
    /*Pour positionner les images*/
    SDL_Rect position;
    /*Position de l'image originale dans l'écran.*/
    position.x = 0;
    position.y = 0;

    SDL_LockSurface(surface); /*On bloque la surface*/
    drawable.draw(this);
    SDL_UnlockSurface(surface); /*On libère la surface, elle peut être utilisée pour une autre tâche*/
    //Apply image to screen
    SDL_BlitSurface(surface, NULL, sdlWindow, &position);
    SDL_Flip(sdlWindow);
}

void MyWindow::putPixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue) {
    Uint32 pixel = SDL_MapRGBA(surface->format, red, green, blue, 255);
    setPixel(surface, x, y, pixel);
}

// see http://fr.openclassrooms.com/informatique/cours/modifier-une-image-pixel-par-pixel/les-bases-techniques-pour-que-ca-fonctionne
/* ********************************************************************* */
/*setPixel : permet de modifier la couleur d'un pixel
Paramètres d'entrée/sortie :
SDL_Surface *surface : la surface sur laquelle on va modifier la couleur d'un pixel
int x : la coordonnée en x du pixel à modifier
int y : la coordonnée en y du pixel à modifier
Uint32 pixel : le pixel à insérer
 */
void MyWindow::setPixel(SDL_Surface *surface, int x, int y, Uint32 pixel) {
    /*nbOctetsParPixel représente le nombre d'octets utilisés pour stocker un pixel.
    En multipliant ce nombre d'octets par 8 (un octet = 8 bits), on obtient la profondeur de couleur
    de l'image : 8, 16, 24 ou 32 bits.*/
    int nbOctetsParPixel = surface->format->BytesPerPixel;
    /*Ici p est l'adresse du pixel que l'on veut modifier*/
    /*surface->pixels contient l'adresse du premier pixel de l'image*/
    Uint8 *p = (Uint8 *) surface->pixels + y * surface->pitch + x * nbOctetsParPixel;

    /*Gestion différente suivant le nombre d'octets par pixel de l'image*/
    switch (nbOctetsParPixel) {
        case 1:
            *p = pixel;
            break;

        case 2:
            *(Uint16 *) p = pixel;
            break;

        case 3:
            /*Suivant l'architecture de la machine*/
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                p[0] = (pixel >> 16) & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = pixel & 0xff;
            } else {
                p[0] = pixel & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = (pixel >> 16) & 0xff;
            }
            break;

        case 4:
            *(Uint32 *) p = pixel;
            break;
    }
}

void MyWindow::write(string text, string font, int x, int y,  unsigned char red, unsigned char green, unsigned char blue) {
    
    TTF_Init();
    SDL_Surface *texte = NULL;
    TTF_Font *police = NULL;
    police = TTF_OpenFont("Michroma-webfont.ttf", 22);
    if(police == NULL){
        cout << "police == NULL" << endl;
    }
    
    SDL_Rect position;
    
    /*position.x = x;
    position.y = y;*/
    
    position.x = 300;
    position.y = 300;
    
    //SDL_Color color = {red, green, blue};
    SDL_Color color = {0, 0, 0};
    //texte = TTF_RenderText_Blended(police, text.c_str(), color);
    texte = TTF_RenderText_Blended(police, "hello world", color);
    
    if(texte == NULL){
        cout <<"texte == NULL" << endl;
    }
    while(true){
        SDL_BlitSurface(texte, NULL, surface, &position);
        SDL_Flip(surface);
    }
    cout << "SDL_BlitSurface(texte, NULL, this->surface, &position)" << endl;
    cout << text.c_str() << endl;
    
    TTF_CloseFont(police);
    TTF_Quit();
}


void MyWindow::clearGraph() {
    /*Pour positionner les images*/
    SDL_Rect position;
    /*Position de l'image originale dans l'écran.*/
    position.x = 0;
    position.y = 0;

    SDL_LockSurface(surface); /*On bloque la surface*/

    for (int i = 0; i < getWidth(); i++) {
        for (int j = 0; j < getHeight(); j++) {
            putPixel(i, j, 255, 255, 255);
        }
    }

    SDL_UnlockSurface(surface); /*On libère la surface, elle peut être utilisée pour une autre tâche*/
    //Apply image to screen
    SDL_BlitSurface(surface, NULL, sdlWindow, &position);
    SDL_Flip(sdlWindow);
}

int MyWindow::getWidth() {
    return width;
}

int MyWindow::getHeight() {
    return height;
}

MyWindow* MyWindow::window = NULL;

void MyWindow::destroyWindow() {
    delete MyWindow::window;
}

MyWindow* MyWindow::createWindow(int x, int y, int width, int height) {
    if (MyWindow::window == NULL) {
        MyWindow::window = new MyWindow(x, y, width, height);
    }
    MyWindow::window->clearGraph();
    return MyWindow::window;
}
