#include"bien_toan_cuc.h"
#include"ball.h"
#include"hinh_nen.h"
#include<SDL_mixer.h>
#include"music.h"

  bool success;
  Mix_Music *Sound_Background =NULL ;
  Mix_Chunk *Completed_Sound_  =NULL;
  Mix_Chunk *Sound_1_arr =NULL;
  Mix_Chunk *Sound_Move_ =NULL;
  int count_sound_background=0;
  SDL_Surface* Sound_=LoadImage("image/Sound.png");
  SDL_Surface* No_Sound_=LoadImage("image/NO_Sound.png");

  void Load_Sound()
  {

	//Load music
	Sound_Background = Mix_LoadMUS( "image/relax.mp3" );
	if( Sound_Background == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
      //Load sound effects
	Completed_Sound_ = Mix_LoadWAV( "image/scratch.wav" );
	if( Completed_Sound_ == NULL )
	{
		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	Sound_1_arr = Mix_LoadWAV( "image/1_arr.mp3" );
	if( Sound_1_arr == NULL )
	{
		printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	Sound_Move_ = Mix_LoadWAV( "image/Sound_Move_.wav" );
	if( Sound_Move_ == NULL )
	{
		printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		std::cout<<"dmm";
		success = false;
	}

  }


  int count_1_arr=-1;
  void Check_1_arr()
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
    int count_1_arr_1=-1;
    for(int i=1;i<6;i++)
    {
        int count_1_arr_x=0;
        for(int j=1;j<6;j++)
        {
            if(m[j][i]-m[1][i]==0)
            {
                count_1_arr_x+=1;
            }
        }
        if(count_1_arr_x==5)
        {
         count_1_arr_1+=1;
        }
        if(count_1_arr_1>count_1_arr and fog_ball_hard==0)
        {
            count_1_arr+=1;
            Mix_PlayChannel( -1, Sound_1_arr, count_1_arr );
        }
        count_1_arr_x=0;
    }
}
  void Up_Sound(int x,int y){
      std::cout<<fog_ball_hard<<std::endl;
      if(( x/100==0 and y!=0) or( x!=0 and y/100==0 ) or(x!=0 and y/100==6) or(x/100==6 and y!=0))
      {
         Mix_PlayChannel( -1, Sound_Move_, 0 );
      }
      if(x/100>6 and y/100==1)
      {
          Mix_PlayChannel( -1,Completed_Sound_ , 1 );
      }
      if(x/100>6 and y/100>=5 and y/100<=6)
      {
          count_sound_background+=1;
      // âm thanh nền
      if(count_sound_background%2==0)
      {
        //Play the music
        Mix_PlayMusic( Sound_Background, -1 );
        ApplySurface(Sound_,710,510,180,80);
      }
      else if(count_sound_background%2==1)
       {
           Mix_HaltMusic();
           ApplySurface(No_Sound_,710,510,180,80);
       }
      }
  }
