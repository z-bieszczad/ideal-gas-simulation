#include <iostream>
#include "Vec3.h"
#include <cmath>
#include <ostream>

Vector3d Vector3d:: cross(const Vector3d &other) const{
    Vector3d vec;

    vec._x=_y*other._z -_z*other._y;
    vec._y=_z*other._x -_x*other._z;
    vec._z=_x*other._y-_y*other._x;

    return vec;
   
}

double Vector3d:: dot(const Vector3d &other) const{
    
    return _x*other._x +_y*other._y +_z*other._z;

}

double Vector3d:: magnitude() const{
    
    return sqrt(_x*_x +_y*_y +_z*_z);

}

Vector3d Vector3d:: normalize() const{
    Vector3d vec;
    double length= this->magnitude();

    if (length == 0.0){
        return Vector3d(0, 0, 0);
    }
     
    vec._x=_x/length;
    vec._y=_y/length;
    vec._z=_z/length;

    return vec;

}

//=======operators========

Vector3d Vector3d:: operator+(const Vector3d& other)const{
    Vector3d vec;

    vec._x=_x+other._x;
    vec._y=_y+other._y;
    vec._z=_z+other._z;

    return vec;
}

Vector3d Vector3d:: operator-(const Vector3d& other)const{
    Vector3d vec;

    vec._x=_x-other._x;
    vec._y=_y-other._y;
    vec._z=_z-other._z;

    return vec;
}


Vector3d Vector3d:: operator*(double scalar)const{
    Vector3d vec;

    vec._x=_x*scalar;
    vec._y=_y*scalar;
    vec._z=_z*scalar;

    return vec;

}

bool Vector3d::operator==(const Vector3d& other) const{
    const double eps= 1e-9;
    
    return std::abs(_x-other._x)<eps && std::abs(_y-other._y)<eps && std:: abs(_z-other._z)<eps;
}

Vector3d& Vector3d:: operator+=(const Vector3d& other){
    _x=_x+other._x;
    _y=_y+other._y;
    _z=_z+other._z;

    return *this;
}

Vector3d& Vector3d:: operator-=(const Vector3d& other){
    _x=_x-other._x;
    _y=_y-other._y;
    _z=_z-other._z;

    return *this;
}


Vector3d& Vector3d:: operator*=(double scalar){
    _x=_x*scalar;
    _y=_y*scalar;
    _z=_z*scalar;

    return *this;
}


std::ostream& operator<<(std::ostream& os, const Vector3d& v) {
    os << "(" << v._x << ", " << v._y << ", " << v._z << ")";
    return os;
}


//========= getters =========

double Vector3d:: getX() const{
    return _x;
}

double Vector3d:: getY() const{
    return _y;
}

double Vector3d:: getZ() const{
    return _z;
}


//setters
void Vector3d:: setX(double x){
    _x=x;
}

void Vector3d:: setY(double y) {
    _y=y;
}

void Vector3d:: setZ(double z) {
    _z=z;
}



