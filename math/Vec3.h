#pragma once
#include <ostream>

class Vector3d{
public:
    
    Vector3d()=default;
    Vector3d(double x, double y, double z): _x(x), _y(y), _z(z) {}

    Vector3d cross(const Vector3d &other) const;
    double dot(const Vector3d &other) const;
    double magnitude() const;
    Vector3d normalize() const;

    
    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    Vector3d operator+(const Vector3d& other) const;
    Vector3d operator-(const Vector3d& other) const;
    Vector3d operator*(double scalar) const;
    bool operator==(const Vector3d& other) const;

    Vector3d& operator+=(const Vector3d& other);
    Vector3d& operator-=(const Vector3d& other);
    Vector3d& operator*=(double scalar);
    friend std::ostream& operator<<(std::ostream& os, const Vector3d& v);

    
private:
    double _x=0;
    double _y=0;
    double _z=0;
    
};