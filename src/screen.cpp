#include "screen.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_pixelBuffer(NULL){

}

bool Screen::init(){

    // check for SDL init error
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "+ SDL init failed." << endl;
        return false;
    }
    cout << "+ SDL init successful." << endl;

    // create window
    m_window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // check for SDL window error
    if (m_window == NULL){
        SDL_Quit();
        printf("+ Window Error: %s", SDL_GetError());
        return false;
    }

    // create renderer object, presentVsync is syncing with native screen frame rate
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (m_renderer == NULL){
        cout << "+ Renderer creation failed." << endl;
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    // create texture
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if (m_texture == NULL){
        cout << "+ Texture creation failed." << endl;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    // buffer -> area of memory allocated for the pixels on the screen
    m_pixelBuffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    // assignign a block of memory to each pixel on screen - 0 is the value thats placed in all mem cells
    memset(m_pixelBuffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));


    return true;

}

bool Screen::processEvents(){
    SDL_Event event;
    // poll event fetches recent events that takes the address of sdl_event
    // loop will iterate when &event returns true, whenever there is an event happening
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            cout << "+ Window closed." << endl;
            return true;
        }
    }
    return false;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
    
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT){
        return;
    }
    
    Uint32 colour = 0;

    colour += red;
    colour <<= 8;
    colour += green;
    colour <<= 8;
    colour += blue;
    colour <<= 8;
    colour += 0xFF;
   
    m_pixelBuffer[(y * SCREEN_WIDTH + x)] = colour;
    
}

void Screen::update(){
    // update texture for pixels on screen
    SDL_UpdateTexture(m_texture, NULL, m_pixelBuffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void Screen::clear(){
    memset(m_pixelBuffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

void Screen::terminate(){
    delete [] m_pixelBuffer;
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);    
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    cout << "+ Program terminated." << endl;
    
}
