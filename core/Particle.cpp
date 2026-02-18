#include <iostream>
#include "../math/Vec3.h"
#include <cmath>
#include <ostream>
#include "Particle.h"


// getters 
const Vector3d& Particle:: getPosition() const{
    return _position;
}

const Vector3d& Particle:: getVelocity() const{
    return _velocity;
}

double Particle:: getMass() const{
    return _mass;
}

double Particle:: getRadius() const{
    return _radius;
}

Vector3d Particle:: getForce() const{
    return _force;
}

Vector3d Particle:: getColor() const{
    return _color;
}

// setters
void Particle::setPosition(const Vector3d& other){
    _position=other;
}

void Particle::setVelocity(const Vector3d& other){
    _velocity=other;
}

void Particle::setAcceleration(const Vector3d& other){
    _acceleration=other;
}


void Particle:: applyForce(const Vector3d& force){
    _force=_force+force;
}

void Particle:: setColor(const Vector3d& color){
    _color=color;
}

void Particle::resetForces(){
    _force = Vector3d(0,0,0);
}


