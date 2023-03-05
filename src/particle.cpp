#include "particle.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

Particle::Particle(){
    // generates a rand value between 0 and 1
    m_x = ((2.0 * rand()) / RAND_MAX) - 1;
    m_y = ((2.0 * rand()) / RAND_MAX) - 1;
    
    m_velocityRate = 0.001;
    m_xSpeed = m_velocityRate * (((2.0 * rand()) / RAND_MAX) - 1);
    m_ySpeed = m_velocityRate * (((2.0 * rand()) / RAND_MAX) - 1);

}


void Particle::update(){
    m_x += m_xSpeed;
    m_y += m_ySpeed;

    if (m_x >= 1 || m_x <= -1){
        m_x *= -1;
    }

    if (m_y >= 1 || m_y <= -1){
        m_y *= -1;
    }
}







Particle::~Particle(){

}
