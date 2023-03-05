#include "particle.h" 

class Swarm{
    private:
        Particle * m_particles;
    
    public:
        const static int NPARTICLES = 1000;
    
    public:
        Swarm();
        ~Swarm();
        const Particle * const getParticles(){ return m_particles; };
        void update();
};
