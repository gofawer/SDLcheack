#include <iostream>
#include <SDL.h>
using namespace std;

int main()
{
    if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    } else {
        cout << "Works works ..." << endl;
        SDL_Quit();
    }

    return 0;
}