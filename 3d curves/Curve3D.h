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
        explicit Circle(double radius) {
            if (radius <= 0) {
                throw std::invalid_argument("Radius must be positive");
            }
            this->radius = radius;
        }
        Point3D getPoint(double t) const override {
            return { this->radius * std::cos(t), this->radius * std::sin(t), 0.0 };
        }
        Point3D getDerivative(double t) const override {
            return { -this->radius * std::sin(t), this->radius * std::cos(t), 0.0 };
        }

        double getRadius() const
        { 
            return radius;
        };
    };

    class Ellipse : public Curve {
    private:
        double radiusX, radiusY;
    public:
        explicit Ellipse(double radiusX, double radiusY) {
            if (radiusX <= 0 || radiusY <= 0) {
                throw std::invalid_argument("Radius must be positive");
            }
            this->radiusX = radiusX;
            this->radiusY = radiusY;
        }
        Point3D getPoint(double t) const override {
            return { this->radiusX * std::cos(t), this->radiusY * std::sin(t), 0.0 };
        }
        Point3D getDerivative(double t) const override {
            return { -this->radiusX * std::sin(t), this->radiusY * std::cos(t), 0.0 };
        }
    };


    class Helix : public Curve {
    private:
        double radius, step;
    public:
        explicit Helix(double raduis, double step) {
            if (raduis <= 0) {
                throw std::invalid_argument("Radius must be positive");
            }
            this->radius = raduis;
            this->step = step;
        }
        Point3D getPoint(double t) const override {
            return { this->radius * std::cos(t), this->radius * std::sin(t), step * t / (2 * PI) };
        }
        Point3D getDerivative(double t) const override {
            return { -this->radius * std::sin(t), this->radius * std::cos(t), step / (2 * PI) };
        }
    };

}