#pragma once
#include <cmath>
#include "../math/Vec3.h"
#include <string>

class Particle{
public:
    //constructors
    Particle(const Vector3d& position,
                   const Vector3d& velocity,
                   const Vector3d& acceleration,
                   const Vector3d& spin,
                   const Vector3d& color,
                   const Vector3d& force,
                   double mass,
                   double radius,
                   int degreesOfFreedom,
                   const std::string& type)
    : _position(position),
      _velocity(velocity),
      _acceleration(acceleration),
      _spin(spin),
      _color(color),
      _force(force),
      _mass(mass),
      _radius(radius),
      _degreesOfFreedom(degreesOfFreedom),
      _type(type)
    {}

    Particle()
    : _position(0,0,0),
      _velocity(0,0,0),
      _acceleration(0,0,0),
      _spin(0,0,0),
      _color(1,1,1),     
      _force(0,0,0),
      _mass(1.0),
      _radius(1.0),
      _degreesOfFreedom(3),
      _type("default")
    {}

    
    Particle(const Vector3d& position,
         const Vector3d& velocity,
         double mass,
         double radius)
    : _position(position),
      _velocity(velocity),
      _acceleration(0,0,0),
      _spin(0,0,0),
      _color(1,1,1),
      _force(0,0,0),
      _mass(mass),
      _radius(radius),
      _degreesOfFreedom(3),
      _type("default")
    {}


    // methods
    const Vector3d& getPosition() const;
    const Vector3d& getVelocity() const;
    double getMass() const;
    double getRadius() const;
    Vector3d getColor() const;
    Vector3d getForce() const;

    void setPosition(const Vector3d& other);
    void setVelocity(const Vector3d& other);
    void setAcceleration(const Vector3d& other);
    void applyForce(const Vector3d& force);
    void setColor(const Vector3d& color);
    void resetForces();

       
private:

    Vector3d _position;
    Vector3d _velocity;
    Vector3d _acceleration;
    Vector3d _spin;
    Vector3d _color;
    Vector3d _force;

    double _mass;
    double _radius;

    int _degreesOfFreedom;

    std::string _type;


};