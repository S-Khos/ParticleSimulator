#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"
#include "screen.h"
#include <iomanip>
#include <math.h>
#include "particle.h"
#include "swarm.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
    
    srand(time(NULL));

    Screen screen;
    if (screen.init() == false){
        return 1;
    }

    Swarm swarm;

    while (true){

        screen.clear();
        swarm.update();

        //retrieve the array of particles from swarm
        const Particle * const pParticles = swarm.getParticles();
        
        
        for (int i = 0; i < Swarm::NPARTICLES; i++){
            // make an object of each particle in the retrieved particle array
            Particle particle = pParticles[i];
            // turn particle pos from 0-1 to 1-2 and multiply it by half of width/height to map on to screen
            int x = ((particle.m_x + 1) * Screen::SCREEN_WIDTH / 2);
            int y = ((particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2);
            screen.setPixel(x, y, 255, 255, 255);
        }



        screen.update();

        if (screen.processEvents()){
            break;
        }
    }
    

    screen.terminate();
    return 0;
}


        // number of miliseconds since program has executed
            //int elapsed = SDL_GetTicks();
            //unsigned char red = (1 + sin(elapsed * rand() * 0.0001)) * 128;
            //unsigned char green = (1 + sin(elapsed * rand() * 0.0001)) * 128;
            //unsigned char blue = (1 + sin(elapsed * rand() * 0.0001)) * 128;
            