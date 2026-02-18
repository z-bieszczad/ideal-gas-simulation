#include <iostream>
#include "../math/Vec3.h"
#include <cmath>
#include <ostream>
#include "Particle.h"
#include "PhysicsSystem.h"


void PhysicsSystem::update(std::vector<Particle>& particles, double dt){

    for(auto &p: particles){
        integrate(p, dt);
    }

    handleWallCollisions(particles);
    handleParticleCollisions(particles);


    for(auto &p: particles){
        updateColorFromVelocity(p);
    }

}

void PhysicsSystem::integrate(Particle& p, double dt) {
    Vector3d newPos = p.getPosition();
    newPos = newPos + p.getVelocity();
    p.setPosition(newPos);
}


void PhysicsSystem:: handleParticleCollisions(std::vector<Particle>& particles){

    size_t size=particles.size();

    for(size_t i=0; i<size; ++i){
        for(size_t j=i+1; j<size; ++j){
            Particle& p1= particles[i];
            Particle& p2= particles[j];

            Vector3d delta= p1.getPosition()- p2.getPosition();
            double dist= delta.magnitude();
            double sumRadii= p1.getRadius()+ p2.getRadius();

            // checking distance between particles
            if(dist <sumRadii){
                Vector3d vRel=p1.getVelocity()-p2.getVelocity();
                Vector3d normal=delta.normalize();
                double vRelDotNormal=vRel.dot(normal);
                
                // checking if particles are getting close 
                if(vRelDotNormal<0){
                    
                    double mass1=p1.getMass();
                    double mass2=p2.getMass();

                    Vector3d velocity1=p1.getVelocity();
                    Vector3d velocity2=p2.getVelocity();

                    double impulse=(2*vRelDotNormal)/(mass1+mass2);

                    velocity1=velocity1-normal*impulse*mass2;
                    velocity2=velocity2+normal*impulse*mass1;

                    p1.setVelocity(velocity1);
                    p2.setVelocity(velocity2);

                    double penetration=(sumRadii)-dist;
                    Vector3d correction=normal*(penetration/2.0);

                    p1.setPosition(p1.getPosition()+ correction);
                    p2.setPosition(p2.getPosition()- correction);
                }

            }
        }
    }
}


