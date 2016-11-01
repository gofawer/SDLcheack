cmake_minimum_required( VERSION 2.8.9 )
project( helloSdl )
set( CMAKE_BUILD_TYPE Debug )

link_directories( $ENV{SDL_LIB_DIR} )
include_directories( $ENV{SDL_INC_DIR} )
file( GLOB SOURCES "src/*.cpp" )

add_compile_options( -std=c++11 )
add_executable( helloSdl ${SOURCES} )
target_link_libraries( helloSdl SDL2 )
