#include "bien_toan_cuc.h"
 int screen_width=900;
 int screen_height=700;
SDL_Window* g_window=NULL;
SDL_Renderer* g_renderer=NULL;
SDL_Surface* g_background=NULL;

bool Init()
    {

        if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
        {

            return false;
        }
        else
        {
            g_window=SDL_CreateWindow("hà trường giang",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screen_width,screen_height,SDL_WINDOW_SHOWN);

            if(g_window==NULL)
            {
                return false;
            }
             g_renderer=SDL_CreateRenderer(g_window,-1,SDL_WINDOW_SHOWN);

             if(g_renderer==NULL)
             {
                 return false;
             }
            return true;
        }

    }


SDL_Surface* LoadImage(std::string file_path)
{
//    SDL_Surface* load_image =NULL;
//    load_image = IMG_Load(file_path.c_str());
//    return load_image;
return IMG_Load(file_path.c_str());

}
void ApplySurface(SDL_Surface* image,int x,int y,int w,int h)
{
    const SDL_Rect offset={x,y,w,h};
    SDL_Texture* texture = SDL_CreateTextureFromSurface(g_renderer, image);
    SDL_RenderCopy(g_renderer, texture, NULL, &offset);
    SDL_RenderPresent(g_renderer);

    SDL_DestroyTexture(texture);

}
void CleanUp()
{
SDL_DestroyWindow(g_window);
SDL_DestroyRenderer(g_renderer);
SDL_FreeSurface(g_background);
//TTF_CloseFont(font);
}
