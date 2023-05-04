#include "hinh_nen.h"

 void up_hinh_nen(int x,int y,int w,int h)
{
    g_background=LoadImage("image/7x7_2.png");
    ApplySurface(g_background,0,0,900,700);
    for(int j=1;j<6;j++){//i=0
            g_huong[0][j]=LoadImage("image/down.png");
            x+=j*100;
            y+=0*100;
            ApplySurface(g_huong[0][j],x,y,w,h);
            x-=j*100;
            y-=0*100;
    }
    for(int j=1;j<6;j++){//i=6
            g_huong[6][j]=LoadImage("image/up.png");
            x+=j*100;
            y+=6*100;
            ApplySurface(g_huong[6][j],x,y,w,h);
            x-=j*100;
            y-=6*100;
    }
    for(int i=1;i<6;i++){//j=0
            g_huong[i][0]=LoadImage("image/right.png");
            x+=0*100;
            y+=i*100;
            ApplySurface(g_huong[i][0],x,y,w,h);
            x-=0*100;
            y-=i*100;
    }
    for(int i=1;i<6;i++){
            g_huong[i][6]=LoadImage("image/left.png");
            x+=6*100;
            y+=i*100;
            ApplySurface(g_huong[i][6],x,y,w,h);
            x-=6*100;
            y-=i*100;
    }
}


