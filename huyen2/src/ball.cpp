#include"bien_toan_cuc.h"
#include"ball.h"
#include<iostream>
#include<SDL.h>

SDL_Surface* g_ball[6][6];
int fog_ball_hard=2;
int x_mouse,y_mouse;

void get_link_ball()
{
    g_fog_ball=LoadImage("image/fog_ball.png");
    for(int j=1;j<6;j++)
    {
        for(int i=1;i<6;i++)
        {
               if(j==1)
            {
                g_ball[i][j]=LoadImage("image/black_gem.png");
            }
            else if(j==2)
            {
                g_ball[i][j]=LoadImage("image/gem_red.png");
            }
            else if(j==3)
            {
                g_ball[i][j]=LoadImage("image/green_gem.png");
            }
            else if(j==4)
            {
                g_ball[i][j]=LoadImage("image/blue_gem.png");
            }
            else if(j==5)
            {
                g_ball[i][j]=LoadImage("image/yellow_gem.png");
            }
        }
    }
}


void up_image_ball(int x,int y)
{
    for(int i=1;i<6;i++)
    {
        for(int j=1;j<6;j++)
        {
        x+=i*100;
        y+=(j)*100;
        //std::cout<<g_ball[i][j];
        ApplySurface(g_ball[i][j],x,y,50,50);
        x-=i*100;
        y-=(j)*100;
        }
    }
//int a=25+x*100,b=25+y*100;
//for( int i=1;i<6;i++)
//{
//
//
//}

}
void move_(int y,int x)
{
       if (x==3 and (y==7 or y==8)  )
        {
            fog_ball_hard=1;
        }
        else if (x==2 and (y==7 or y==8)  )
        {
            fog_ball_hard=0;
        }
    if(fog_ball_hard==1)
    {
        for(int i=1;i<6;i++)
        {
            for(int j=1;j<6;j++)
            {
                ApplySurface(g_fog_ball,25+100*j,25+100*i,50,50);
            }
        }
    }


    int x2=-1;
    int y2=-1;
    if(x==2 and y==7)
    {
        up_image_ball(25,25);
    }
    else if(y==0 and x!=6)
    {
        y2=x;
        SDL_Surface* temp=g_ball[5][y2];
        for(int x2=5;x2>0;--x2)
        {
          if(x2==1)
          {
              g_ball[x2][y2]=temp;
          } else
          {
              g_ball[x2][y2]=g_ball[x2-1][y2];
          }

        }
        if(fog_ball_hard==0)
        {
            for(int x3=1;x3<=5;x3++)
            {
                ApplySurface(g_ball[x3][y2],x3*100+25,y2*100+25,50,50);
            }
        }
    }
    else if(y==6 and x!=6)
    {
        y2=x;
        SDL_Surface* temp=g_ball[1][y2];
        for(int x2=1;x2<6;x2++)
        {
          if(x2==5)
          {
              g_ball[x2][y2]=temp;
          } else
          {
              g_ball[x2][y2]=g_ball[x2+1][y2];
          }
        }
        if(fog_ball_hard==0)
        {
            for(int x3=1;x3<=5;x3++)
            {
                ApplySurface(g_ball[x3][y2],x3*100+25,y2*100+25,50,50);
            }
        }
    }
    else if(x==0 and y!=6)
    {
        x2=y;
        SDL_Surface* temp=g_ball[x2][5];
        for(int y2=5;y2>0;--y2)
        {
          if(y2==1)
          {
              g_ball[x2][y2]=temp;
          } else
          {
              g_ball[x2][y2]=g_ball[x2][y2-1];
          }
        }
        if(fog_ball_hard==0)
        {
            for(int y3=1;y3<=5;y3++)
            {
                ApplySurface(g_ball[x2][y3],x2*100+25,y3*100+25,50,50);
            }
        }
    }
    else if(x==6 and y!=6)
    {
        x2=y;
        SDL_Surface* temp=g_ball[x2][1];
        for(int y2=1;y2<6;y2++)
        {
          if(y2==5)
          {
              g_ball[x2][y2]=temp;
          } else
          {
              g_ball[x2][y2]=g_ball[x2][y2+1];
          }
        }
        if(fog_ball_hard==0)
        {
            for(int y3=1;y3<=5;y3++)
            {
                ApplySurface(g_ball[x2][y3],x2*100+25,y3*100+25,50,50);
            }
        }
    }

}

