#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>

class pomododo: public olc::PixelGameEngine{
    public:
    bool OnUserCreate()override{
        return true;
    }
    bool OnUserUpdate(float fElapsedTime)override{
        for(int i=0; i<ScreenWidth(); i++){
            for(int j=0; j<ScreenHeight(); j++){
                Draw(i,j,olc::Pixel(rand()%255,rand()%255,rand()%255));
            }
        }
        return true;
    }
};

int main()
{
    std::cout << "Hello Pomododo!\n";
    pomododo demo;
    if (demo.Construct(500, 500, 1, 1, false, false))
                demo.Start();
    return 0;
}