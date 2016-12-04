cmake_minimum_required( VERSION 2.8.9 )
set( CMAKE_BUILD_TYPE Debug )
set( APP_NAME DrawColor )
set( CPPFLAGS -std=c++11 )

project( ${APP_NAME} )
file( GLOB SOURCES "src/*.cpp" )

link_directories( $ENV{SDL_LIB_DIR} )
include_directories( $ENV{SDL_INC_DIR} )

add_compile_options( ${CPPFLAGS} )
add_executable( ${APP_NAME} ${SOURCES} )
target_link_libraries( ${APP_NAME} SDL2 ) # libSDL2.so

