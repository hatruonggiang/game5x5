#include "ham_random.h"

void random_()
{
            srand(time(NULL));
        int ran=25;
        while(ran)
        {   ran--;
            move_(0,rand()%5+1);
            move_(6,2*rand()%5+1);
            move_(3*rand()%5+1,0);
            move_(4*rand()%5+1,6);

        }
        fog_ball_hard=0;//điều kiện để hiển thị ảnh
}
