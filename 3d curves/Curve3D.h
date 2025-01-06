#pragma once
#include <iostream>
#include <cmath>

#ifndef PI
#define PI 3.141592653589
#endif // !PI

namespace Curve3D {

    struct Point3D {
        double x;
        double y;
        double z;
        Point3D() : x(0), y(0), z(0) {};
        Point3D(double x, double y, double z) {
            this->x = x;
            this->y = y;
            this->z = z;
        };
        friend std::ostream& operator<<(std::ostream& os, const Point3D& point) {
            os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
            return os;
        }
    };

    // t is angle in polar sys
    class Curve {
    public:

        virtual Point3D getPoint(double t) const = 0;
        virtual Point3D getDerivative(double t) const = 0;
    };

    class Circle : public Curve {
    private:
        double radius;
    public:
        explicit Circle(double radius);
        Point3D getPoint(double t) const override;
        Point3D getDerivative(double t) const override;

        double getRadius() const;
    };

    class Ellipse : public Curve {
    private:
        double radiusX, radiusY;
    public:
        explicit Ellipse(double radiusX, double radiusY);
        Point3D getPoint(double t) const override;
        Point3D getDerivative(double t) const override;
    };


    class Helix : public Curve {
    private:
        double radius, step;
    public:
        explicit Helix(double raduis, double step);
        Point3D getPoint(double t) const override;
        Point3D getDerivative(double t) const override;
    };

}