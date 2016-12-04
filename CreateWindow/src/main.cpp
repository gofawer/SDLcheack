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

    SDL_Window* window = SDL_CreateWindow( "Hello SDL Window", 0, 0, 300, 200, SDL_WINDOW_SHOWN );
    if( window == nullptr ) {
        std::cout << "Create window error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    SDL_Renderer* render = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( render == nullptr ) {
        SDL_DestroyWindow( window );
        std::cout << "Renderer error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Surface* surface = SDL_LoadBMP( getResPath( "circle.bmp" ).c_str() );
    if( surface == nullptr ) {
        std::cout << "Surface error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface( render, surface );
    if( texture == nullptr ) {
        std::cout << "Texture error: " << SDL_GetError() << std::endl;
    }

    for( int i = 0; i < 3; i++ ) {
        SDL_RenderClear( render );
        SDL_RenderCopy( render, texture, nullptr, nullptr );    // Draw
        SDL_RenderPresent( render );    // update screen
        SDL_Delay( 1000 );
    }

    SDL_FreeSurface( surface );
    SDL_DestroyTexture( texture );
    SDL_DestroyRenderer( render );
    SDL_DestroyWindow( window );
    SDL_Quit();

    return 0;
}
