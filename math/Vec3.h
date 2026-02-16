#pragma once

class Vector3d{
public:
    
    Vector3d();
    Vector3d(double x, double y, double z);

    Vector3d add(const Vector3d &other) const;
    Vector3d subtract(const Vector3d &other) const;
    Vector3d scale(double value) const;
    Vector3d cross(const Vector3d &other) const;
    double dot(const Vector3d &other) const;
    double magnitude() const;

    void addInPlace(const Vector3d &other);
    void subtractInPlace(const Vector3d &other);
    void scaleInPlace(double value);
    void crossInPlace(double value);

    
    double getX() const;
    double getY() const;
    double getZ() const;

private:
    double x=0;
    double y=0;
    double z=0;
    
};