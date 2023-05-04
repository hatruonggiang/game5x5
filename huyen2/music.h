#include"bien_toan_cuc.h"
#include"ball.h"
#include"hinh_nen.h"
#include <SDL_mixer.h>


extern Mix_Music *gMusic ;
extern Mix_Chunk *Completed_Sound_ ;
extern Mix_Chunk *gHigh;
extern Mix_Chunk *gMedium ;
extern Mix_Chunk *Sound_Move ;
extern int count_1_arr;
extern int count_sound_background;

void Load_Sound();
void Up_Sound(int x,int y);
void Check_1_arr();
