#include "check_win.h"

SDL_Color textColor = { 0, 0, 0 };
bool win()
{
    int m[6][6];
    for(int i=1;i<6;i++)
    {
        for(int j=1;j<6;j++)
        {
            // lấy pixel
        SDL_Rect rect = {i*100+50, j*100+50, 1, 1};

            // Lưu trữ giá trị pixel của texture tại vị trí (x, y) vào biến pixel
        Uint32 pixel;
        SDL_RenderReadPixels(g_renderer, &rect, SDL_PIXELFORMAT_RGBA8888, &pixel, 1 * sizeof(Uint32));

           // Lấy giá trị r, g, b và a của pixel
        Uint8 r, g, b, a;
        SDL_GetRGBA(pixel, SDL_GetWindowSurface(g_window)->format, &r, &g, &b, &a);
       // std::cout<<(int)r<<' '<<(int)g<<' '<<(int)b<<' ';
        m[i][j]=(int)r*1000+(int)g;
       // std::cout<<m[i][j]<<std::endl;
        }
    }
    int count_win=1;
    for(int i=1;i<6;i++)
    {
        for(int j=1;j<6;j++)
        {
            if(m[j][i]-m[1][i]!=0)
            {
                count_win=0;
            }
        }
    }
    return count_win;
}


