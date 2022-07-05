#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>
#include <chrono>

// sudo apt-get install build-essential libglu1-mesa-dev libpng-dev
// g++ -fopenmp app.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -O3 -mavx2  -o app
class pomododo: public olc::PixelGameEngine{
    public:
        std::chrono::_V2::system_clock::time_point start;
        int contador;
        //auto tStart = std::chrono::high_resolution_clock::now();
    bool OnUserCreate()override{

        

        return true;
    }

    pomododo(){
        start = std::chrono::high_resolution_clock::now();
        contador = 0;
    };

    bool OnUserUpdate(float fElapsedTime)override{
        /*
        for(int i=0; i<ScreenWidth(); i++){
            for(int j=0; j<ScreenHeight(); j++){
                Draw(i,j,olc::Pixel(rand()%255,rand()%255,rand()%255));
            }
        }
        */
        auto duration = std::chrono::high_resolution_clock::now() - start;

        if(duration.count() > 10e8){
            
            start = std::chrono::high_resolution_clock::now();
            ++contador;
            if(contador == 60){
                contador = 0;
            }
        }
        FillCircle({ScreenWidth()/2, ScreenHeight()/2}, 50, {130, 130, 130});
        //FillRect({ScreenWidth()/2 - 50, ScreenHeight()/2 - 50}, {100, 100}, olc::Pixel(255, 0, 0));
        
        if(contador < 10){
            DrawString({ScreenWidth()/2 - 7, ScreenHeight()/2 - 7}, std::to_string(contador), olc::Pixel(255, 0, 0), 2);
        }
        else{
            DrawString({ScreenWidth()/2 - 14, ScreenHeight()/2 - 7}, std::to_string(contador), olc::Pixel(255, 0, 0), 2);
        
        }
        
        DrawLine( {0, ScreenHeight()/2}, {ScreenWidth(), ScreenHeight()/2} );

        DrawLine( {ScreenWidth()/2, 0}, {ScreenWidth()/2, ScreenHeight()} );
        
        //for(int i=ScreenWidth/2 - 50; i < ScreenWidth/2 + 50){

        //}
        return true;
    }
};

int main()
{
    std::cout << "Hello Pomododo!\n";
    pomododo demo;
    if (demo.Construct(1280, 720, 1, 1, false, false))
                demo.Start();
    return 0;
}