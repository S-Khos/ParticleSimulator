#include "swarm.h"

Swarm::Swarm(){
    // create 5000 particle objects in an array/memory space
    m_particles = new Particle[NPARTICLES];

}

void Swarm::update(){
    // go through each particle in the particle array and update its speed
    for (int i = 0; i < NPARTICLES; i++){
        m_particles[i].update();
    }

}



Swarm::~Swarm(){
    delete [] m_particles;
}
