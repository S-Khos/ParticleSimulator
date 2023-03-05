#ifndef PARTICLE_H_
#define PARTICLE_H_

class Particle{

    public:
        double m_x;
        double m_y;
        double m_velocityRate;
        double m_xSpeed;
        double m_ySpeed;


    public:
        Particle();
        ~Particle();
        void update();


};

#endif