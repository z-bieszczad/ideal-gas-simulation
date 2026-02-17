#include <iostream>
#include "Vec3.h"

int main() {
    // sample vectors
    Vector3d a(1.0, 2.0, 3.0);
    Vector3d b(4.0, 5.0, 6.0);

    // Test for + i +=
    Vector3d c = a + b;
    std::cout << "a + b = " << c << std::endl;

    a += b;
    std::cout << "a += b -> a = " << a << std::endl;

    // Test for - i -=
    Vector3d d = a - b;
    std::cout << "a - b = " << d << std::endl;

    a -= b;
    std::cout << "a -= b -> a = " << a << std::endl;

    // Test for  * i *=
    Vector3d e = a * 2.0;
    std::cout << "a * 2 = " << e << std::endl;

    a *= 2.0;
    std::cout << "a *= 2 -> a = " << a << std::endl;

    // Test for dot and cross
    double dot = a.dot(b);
    Vector3d cross = a.cross(b);
    std::cout << "a · b = " << dot << std::endl;
    std::cout << "a x b = " << cross << std::endl;

    // Test for magnitude and normalize
    std::cout << "Magnitude of a = " << a.magnitude() << std::endl;
    Vector3d n = a.normalize();
    std::cout << "Normalized a = " << n << std::endl;

    // Test for operator==
    Vector3d f(2.0, 4.0, 6.0);
    std::cout << "a == f? " << (a == f) << std::endl;

    return 0;
}
