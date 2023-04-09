#ifndef BIEN_TOAN_CUC_H
#define BIEN_TOAN_CUC_H
#include <string>
#include<SDL.h>
#include <SDL_image.h>
#include<iostream>
#include<algorithm>
#include <SDL_ttf.h>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include <fstream>
#include <string.h>


    // các biến toàn cục
    extern int screen_width;
    extern int screen_height;
    //extern int screen_bpp=32;
    extern SDL_Window* g_window;
    extern SDL_Renderer* g_renderer;
    extern SDL_Surface* g_background;
    extern SDL_Surface* g_ball[6][6];
    static SDL_Surface* g_fog_ball;
    static SDL_Surface* g_huong[7][7];
    static SDL_Event g_event;
    extern int x_mouse,y_mouse;

    extern TTF_Font* font;
    extern int ran;


    // các hàm toàn cục
    bool Init();
    SDL_Surface* LoadImage(std::string file_path);
    void ApplySurface(SDL_Surface* image,int x,int y,int w,int h);
    void CleanUp();




#endif // BIEN_TOAN_CUC_H
