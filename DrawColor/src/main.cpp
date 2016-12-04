#include <iostream>
#include <string>
#include <SDL.h>

std::string getResPath( const std::string& assetName ) {
    std::string basePath = SDL_GetBasePath();
    return basePath.substr( 0, basePath.find_last_of( "\\/", basePath.length() - 2 ) + 1 ) + "/res/" + assetName;
}

int main()
{
    if( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
        std::cout << "SDL init error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow( "Hello SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 300, SDL_WINDOW_SHOWN );
    if( window == nullptr ) {
        std::cout << "Create window error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    SDL_Renderer* render = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( render == nullptr ) {
        std::cout << "Renderer error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    SDL_SetRenderDrawColor( render, 200, 100, 50, 255 );
    SDL_RenderClear( render );
    SDL_RenderPresent( render );
    SDL_Delay( 5000 );
    SDL_Quit();

    return 0;
}
