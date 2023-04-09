#include"bien_toan_cuc.h"
#include"ball.h"
#include"hinh_nen.h"
SDL_Color textColor = { 0, 0, 0 };
Uint32 startTime = 0;
std::stringstream timeText;
int time_1;
//int diem_cao;
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
        std::cout<<(int)r<<' '<<(int)g<<' '<<(int)b<<' ';
        m[i][j]=(int)r*1000+(int)g;
        std::cout<<m[i][j]<<std::endl;
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



int main(int arc,char*argv[])
{
     TTF_Init();
     if(Init())
     {
       TTF_Font* font = TTF_OpenFont("image/font.ttf", 28);
         if (font == NULL)// Xử lý lỗi khi không tải được font
            {

                return 1;
                std::cout<<"0";
            }


        up_hinh_nen(25,25,50,50);//trong file hinh_nen
        get_link_ball();//trong file ball
        // sau khi lấy link ball rồi thì bắt đầu tráo
        srand(time(NULL));
        int ran=25;
        while(ran)
        {   ran--;
            move_(0,rand()%5+1);
            move_(6,2*rand()%5+1);
            move_(3*rand()%5+1,0);
            move_(4*rand()%5+1,6);

        }
        fog_ball_hard=0;

        up_image_ball(25,25,50,50);//trong file ball
         bool check=true;
         int time_2=0;
         while(check)//giữ màn hình SDL
         {
            while(SDL_PollEvent(&g_event))//kiểm tra các sự kiện
            {
                if(g_event.type==SDL_QUIT)//kiểm tra xem có out không
                {
                    check=false;
                    break;
                }
                if(g_event.type== SDL_MOUSEBUTTONDOWN)//các sự kiện chuột
                {
                SDL_GetMouseState(&x_mouse, &y_mouse);
                move_(x_mouse/100,y_mouse/100);
                }
            }
             timeText.str( "" );
            time_1=(SDL_GetTicks() - 0)/1000;
             timeText << time_1;
             //textSurface là link dẫn tới bề mặt của timeText sau khi được string hóa rồi con trỏ hóa
             SDL_Surface* textSurface = TTF_RenderText_Solid(font, timeText.str().c_str(), textColor);
            ApplySurface(textSurface,800,50,50,50);
            if(time_1-time_2>=1)//cái này để nó đỡ nhấp nháy khi có sự kiện chuột. thật ra là có lệnh này nó vẫn nhấp nháy. nhưng mình đã lợi dụng nhấp nháy trùng với time luôn
            {
            SDL_Surface* _800x0_ = LoadImage("image/800x0.png");
            ApplySurface(_800x0_,700,0,200,100);
            time_2=time_1;
            }
            if( x_mouse>700 and x_mouse<900 and y_mouse>100 and y_mouse<200)
            {
                if(win())
                {
        SDL_Surface* win_=LoadImage("image/win.png");
         ApplySurface(win_,0,0,900,700);
         SDL_Surface* textSurface = TTF_RenderText_Solid(font, timeText.str().c_str(), textColor);
         ApplySurface(textSurface,470,147,30,30);
         ApplySurface(textSurface,510,305,30,30);
         SDL_Delay(5000);
         check=false;
                }
            }
         }
//          int highScore = 0;
// //         string playerName;
//
//          // Kiểm tra nếu file không tồn tại, tạo mới file và ghi điểm số cao nhất ban đầu vào file
//          std::ifstream highScoreFile("highscore.txt");
//          if (!highScoreFile.is_open())
//             {
//               std::ofstream newHighScoreFile("highscore.txt");
//               newHighScoreFile << "0 no name";
//               newHighScoreFile.close();
//             }
//          else
//             {
//                highScoreFile >> highScore ;//>> playerName;
//                highScoreFile.close();
//             }
//          if(time_1<highScore)
//          {
//                      // Lưu điểm số mới vào file
//        std::ofstream highScoreFile("highscore.txt");
//        if (highScoreFile.is_open())
//        {
//            highScoreFile << time_1 << " "  ;//playerName;
//            highScoreFile.close();
//        }
//          }
//
     CleanUp();
     TTF_Quit();
     SDL_Quit();
     }
     }
































