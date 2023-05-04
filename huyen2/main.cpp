#include"bien_toan_cuc.h"
#include"ball.h"
#include"hinh_nen.h"
#include"check_win.h"
#include"ham_random.h"
#include"music.h"


std::stringstream timeText;
std::stringstream so_luot_da_di_text;
int time_1;
int time_2=0;
//int diem_cao;
int so_luot_da_di=0;
int x=1;int y=1;

int main(int arc,char*argv[])
{
     TTF_Init();
     if(Init())
     {
         TTF_Font* font = TTF_OpenFont("image/font_3.ttf", 50);
         if (font == NULL)// Xử lý lỗi khi không tải được font
            {
                return 1;
            }

        // Hiện luật chơi
        int quit_=false;
        while(!quit_)
        {
            SDL_Surface* luat_choi_=LoadImage("image/luat_choi.png");
            ApplySurface(luat_choi_,0,0,900,600);

           while(SDL_PollEvent(&g_event))
           {
               if(g_event.type==SDL_MOUSEBUTTONDOWN)
               {
                   quit_=true;
               }
           }
        }
        up_hinh_nen(25,25,50,50);// tải hình nền game : khung ,các nút điều khiển

        get_link_ball();// lấy link ảnh ball vào các ô trong mảng

        random_();//xáo trộn các ball

        up_image_ball(25,25);//tải ảnh  ball
        Load_Sound();



        // vòng xử lý chính và hàm in thời gian
        bool check=true;
        SDL_Surface* _800x0_ = LoadImage("image/800x0.png");
        SDL_Surface* image_move=LoadImage("image/move.png");
         while(check)//giữ màn hình SDL
         {

            while(SDL_PollEvent(&g_event))//kiểm tra các sự kiện
            {




                if(g_event.type== SDL_MOUSEBUTTONDOWN)//các sự kiện chuột
                {
                    x_mouse=-1;y_mouse=-1;
                   SDL_GetMouseState(&x_mouse, &y_mouse);
                  // std::cout<<x_mouse<<' '<<y_mouse;
                   move_(x_mouse/100,y_mouse/100);
                   // hiện số lượt đã đi
                    if(x_mouse<700)
                    {
                       so_luot_da_di+=1;
                       so_luot_da_di_text.str("");
                       so_luot_da_di_text<<so_luot_da_di;
                       SDL_Surface* so_luot_da_di_textSurface  =TTF_RenderText_Solid(font,so_luot_da_di_text.str().c_str(),textColor);
                       ApplySurface(_800x0_,705,405,190,90);
                       ApplySurface(so_luot_da_di_textSurface,830,410,30,30);
                    }
                    Up_Sound(x_mouse,y_mouse);
                    Check_1_arr();
                }
            }



             // hàm in thời gian
             timeText.str( "" );
             time_1=(SDL_GetTicks() - 0)/1000;
             timeText << time_1;
             SDL_Surface* timetextSurface = TTF_RenderText_Solid(font, timeText.str().c_str(), textColor);
             ApplySurface(timetextSurface,800,20,25,25);
              if(time_1-time_2>=1)//cái này để nó đỡ nhấp nháy khi có sự kiện chuột. thật ra là có lệnh này nó vẫn nhấp nháy. nhưng mình đã lợi dụng nhấp nháy trùng với time luôn
            {
                SDL_Surface* _800_0_time=LoadImage("image/_800_0_time.png");
            ApplySurface(_800_0_time,710,10,180,80);
            time_2=time_1;
            }




            // check win
            if( x_mouse>700 and x_mouse<900 and y_mouse>100 and y_mouse<200)
            {
                if(win())
                {
                    count_sound_background=0;
                SDL_Surface* win_=LoadImage("image/win.png");
                ApplySurface(win_,0,0,900,700);
                SDL_Surface* timetextSurface = TTF_RenderText_Solid(font, timeText.str().c_str(), textColor);
                ApplySurface(timetextSurface,470,147,30,30);
                ApplySurface(timetextSurface,510,305,30,30);
                SDL_Delay(5000);
                check=false;
                }
            }



            // check exit
            if( x_mouse>700 and x_mouse<900 and y_mouse>600 and y_mouse<700)
            {
                check=false;
            }
         }
     CleanUp();
     TTF_Quit();
     SDL_Quit();
     }
}
/////*This source code copyrighted by Lazy Foo' Productions (2004-2022)
////and may not be redistributed without written permission.*/
////
//////Using SDL, SDL_image, SDL_ttf, SDL_mixer, standard IO, math, and strings
////#include <SDL.h>
////#include <SDL_image.h>
////#include <SDL_mixer.h>
////#include <stdio.h>
////#include <string>
////#include"music.h"
////
//////Screen dimension constants
////const int SCREEN_WIDTH = 640;
////const int SCREEN_HEIGHT = 480;
////
//////Texture wrapper class
////class LTexture
////{
////	public:
////		//Initializes variables
////		LTexture();
////
////		//Deallocates memory
////		~LTexture();
////
////		//Loads image at specified path
////		bool loadFromFile( std::string path );
////
////		#if defined(SDL_TTF_MAJOR_VERSION)
////		//Creates image from font string
////		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
////		#endif
////
////		//Deallocates texture
////		void free();
////
////		//Set color modulation
////		void setColor( Uint8 red, Uint8 green, Uint8 blue );
////
////		//Set blending
////		void setBlendMode( SDL_BlendMode blending );
////
////		//Set alpha modulation
////		void setAlpha( Uint8 alpha );
////
////		//Renders texture at given point
////		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
////
////		//Gets image dimensions
////		int getWidth();
////		int getHeight();
////
////	private:
////		//The actual hardware texture
////		SDL_Texture* mTexture;
////
////		//Image dimensions
////		int mWidth;
////		int mHeight;
////};
////
//////Starts up SDL and creates window
////bool init();
////
//////Loads media
////bool loadMedia();
////
//////Frees media and shuts down SDL
////void close();
////
//////The window we'll be rendering to
////SDL_Window* gWindow = NULL;
////
//////The window renderer
////SDL_Renderer* gRenderer = NULL;
////
//////Scene texture
////LTexture gPromptTexture;
////
////
////
////
////LTexture::LTexture()
////{
////	//Initialize
////	mTexture = NULL;
////	mWidth = 0;
////	mHeight = 0;
////}
////
////LTexture::~LTexture()
////{
////	//Deallocate
////	free();
////}
////
////bool LTexture::loadFromFile( std::string path )
////{
////	//Get rid of preexisting texture
////	free();
////
////	//The final texture
////	SDL_Texture* newTexture = NULL;
////
////	//Load image at specified path
////	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
////	if( loadedSurface == NULL )
////	{
////		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
////	}
////	else
////	{
////		//Color key image
////		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
////
////		//Create texture from surface pixels
////        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
////		if( newTexture == NULL )
////		{
////			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
////		}
////		else
////		{
////			//Get image dimensions
////			mWidth = loadedSurface->w;
////			mHeight = loadedSurface->h;
////		}
////
////		//Get rid of old loaded surface
////		SDL_FreeSurface( loadedSurface );
////	}
////
////	//Return success
////	mTexture = newTexture;
////	return mTexture != NULL;
////}
////
////
////void LTexture::free()
////{
////	//Free texture if it exists
////	if( mTexture != NULL )
////	{
////		SDL_DestroyTexture( mTexture );
////		mTexture = NULL;
////		mWidth = 0;
////		mHeight = 0;
////	}
////}
////
////void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
////{
////	//Modulate texture rgb
////	SDL_SetTextureColorMod( mTexture, red, green, blue );
////}
////
////void LTexture::setBlendMode( SDL_BlendMode blending )
////{
////	//Set blending function
////	SDL_SetTextureBlendMode( mTexture, blending );
////}
////
////void LTexture::setAlpha( Uint8 alpha )
////{
////	//Modulate texture alpha
////	SDL_SetTextureAlphaMod( mTexture, alpha );
////}
////
////void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
////{
////	//Set rendering space and render to screen
////	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
////
////	//Set clip rendering dimensions
////	if( clip != NULL )
////	{
////		renderQuad.w = clip->w;
////		renderQuad.h = clip->h;
////	}
////
////	//Render to screen
////	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
////}
////
////int LTexture::getWidth()
////{
////	return mWidth;
////}
////
////int LTexture::getHeight()
////{
////	return mHeight;
////}
////
////bool init()
////{
////	//Initialization flag
////	bool success = true;
////
////	//Initialize SDL
////	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
////	{
////		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
////		success = false;
////	}
////	else
////	{
////		//Set texture filtering to linear
////		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
////		{
////			printf( "Warning: Linear texture filtering not enabled!" );
////		}
////
////		//Create window
////		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
////		if( gWindow == NULL )
////		{
////			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
////			success = false;
////		}
////		else
////		{
////			//Create vsynced renderer for window
////			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
////			if( gRenderer == NULL )
////			{
////				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
////				success = false;
////			}
////			else
////			{
////				//Initialize renderer color
////				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
////
////				//Initialize PNG loading
////				int imgFlags = IMG_INIT_PNG;
////				if( !( IMG_Init( imgFlags ) & imgFlags ) )
////				{
////					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
////					success = false;
////				}
////
////				 //Initialize SDL_mixer
////				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
////				{
////					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
////					success = false;
////				}
////			}
////		}
////	}
////
////	return success;
////}
////
////bool loadMedia()
////{
////	//Loading success flag
////	bool success = true;
////
//////	//Load prompt texture
//////	if( !gPromptTexture.loadFromFile( "image/prompt.png" ) )
//////	{
//////		printf( "Failed to load prompt texture!\n" );
//////		success = false;
//////	}
//////
//////	//Load music
//////	gMusic = Mix_LoadMUS( "image/beat.wav" );
//////	if( gMusic == NULL )
//////	{
//////		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
//////		success = false;
//////	}
//////
//////	//Load sound effects
//////	gScratch = Mix_LoadWAV( "image/scratch.wav" );
//////	if( gScratch == NULL )
//////	{
//////		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
//////		success = false;
//////	}
//////
//////	gHigh = Mix_LoadWAV( "image/high.wav" );
//////	if( gHigh == NULL )
//////	{
//////		printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
//////		success = false;
//////	}
//////
//////	gMedium = Mix_LoadWAV( "image/medium.wav" );
//////	if( gMedium == NULL )
//////	{
//////		printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
//////		success = false;
//////	}
//////
//////	gLow = Mix_LoadWAV( "image/low.wav" );
//////	if( gLow == NULL )
//////	{
//////		printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
//////		success = false;
//////	}
////Load_Sound();
////	return success;
////}
////
////void close()
////{
////	//Free loaded images
////	gPromptTexture.free();
////
////	//Free the sound effects
////	Mix_FreeChunk( gScratch );
////	Mix_FreeChunk( gHigh );
////	Mix_FreeChunk( gMedium );
////	Mix_FreeChunk( gLow );
////	gScratch = NULL;
////	gHigh = NULL;
////	gMedium = NULL;
////	gLow = NULL;
////
////	//Free the music
////	Mix_FreeMusic( gMusic );
////	gMusic = NULL;
////
////	//Destroy window
////	SDL_DestroyRenderer( gRenderer );
////	SDL_DestroyWindow( gWindow );
////	gWindow = NULL;
////	gRenderer = NULL;
////
////	//Quit SDL subsystems
////	Mix_Quit();
////	IMG_Quit();
////	SDL_Quit();
////}
////
////int main( int argc, char* args[] )
////{
////	//Start up SDL and create window
////	if( !init() )
////	{
////		printf( "Failed to initialize!\n" );
////	}
////	else
////	{
////		//Load media
////		if( !loadMedia() )
////		{
////			printf( "Failed to load media!\n" );
////		}
////		else
////		{
////			//Main loop flag
////			bool quit = false;
////
////			//Event handler
////			SDL_Event e;
////
////			//While application is running
////			while( !quit )
////			{
////				//Handle events on queue
////				while( SDL_PollEvent( &e ) != 0 )
////				{
////					//User requests quit
////					if( e.type == SDL_QUIT )
////					{
////						quit = true;
////					}
////					//Handle key press
////					else if( e.type == SDL_KEYDOWN )
////					{
////						switch( e.key.keysym.sym )
////						{
////							//Play high sound effect
////							case SDLK_1:
////							Mix_PlayChannel( -1, gHigh, 0 );
////							break;
////
////							//Play medium sound effect
////							case SDLK_2:
////							Mix_PlayChannel( -1, gMedium, 0 );
////							break;
////
////							//Play low sound effect
////							case SDLK_3:
////							Mix_PlayChannel( -1, gLow, 0 );
////							break;
////
////							//Play scratch sound effect
////							case SDLK_4:
////							Mix_PlayChannel( -1, gScratch, 0 );
////							break;
////
////							case SDLK_9:
////							//If there is no music playing
////							if( Mix_PlayingMusic() == 0 )
////							{
////								//Play the music
////								Mix_PlayMusic( gMusic, -1 );
////							}
////							//If music is being played
////							else
////							{
////								//If the music is paused
////								if( Mix_PausedMusic() == 1 )
////								{
////									//Resume the music
////									Mix_ResumeMusic();
////								}
////								//If the music is playing
////								else
////								{
////									//Pause the music
////									Mix_PauseMusic();
////								}
////							}
////							break;
////
////							case SDLK_0:
////							//Stop the music
////							Mix_HaltMusic();
////							break;
////						}
////					}
////				}
////
////				//Clear screen
////				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
////				SDL_RenderClear( gRenderer );
////
////				//Render prompt
////				gPromptTexture.render( 0, 0 );
////
////				//Update screen
////				SDL_RenderPresent( gRenderer );
////			}
////		}
////	}
////
////	//Free resources and close SDL
////	close();
////
////	return 0;
////}
