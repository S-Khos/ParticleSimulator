#include "SDL2/SDL.h"

class Screen{
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_pixelBuffer;

    public:
        const static int SCREEN_WIDTH = 1200;
        const static int SCREEN_HEIGHT = 800;
        const char *WINDOW_TITLE = "Particle Simulator";
        
    public:
        Screen();
        bool init();
        bool processEvents();
        void terminate();
        void update();
        void clear();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

};
