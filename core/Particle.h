#pragma once
#include <cmath>
#include "../math/Vec3.h"
#include <string>

class Particle{
public:
    Particle::Particle(const Vector3d& position,
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


    Particle();
    Particle(const Vector3d& position,
         const Vector3d& velocity,
         double mass,
         double radius);

    const Vector3d& getPosition() const;
    const Vector3d& getVelocity() const;
    double getMass() const;
    double getRadius() const;

    void setPosition(const Vector3d&);
    void setVelocity(const Vector3d&);
    void setAcceleration(const Vector3d&);
    void applyForce(const Vector3d& force);
    void setColor(const Vector3d& color);

       
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