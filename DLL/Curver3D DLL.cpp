#include "Curve3D DLL.h"
#include <cmath>
#include <stdexcept>

namespace Curve3D {
    Circle::Circle(double radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
        this->radius = radius;
    }

    Point3D Circle::getPoint(double t) const {
        return { radius * std::cos(t), radius * std::sin(t), 0.0 };
    }

    Point3D Circle::getDerivative(double t) const {
        return { -radius * std::sin(t), radius * std::cos(t), 0.0 };
    }

    double Circle::getRadius() const {
        return radius;
    }

    Ellipse::Ellipse(double radiusX, double radiusY) {
        if (radiusX <= 0 || radiusY <= 0) {
            throw std::invalid_argument("Radii must be positive");
        }
        this->radiusX = radiusX;
        this->radiusY = radiusY;
    }

    Point3D Ellipse::getPoint(double t) const {
        return { radiusX * std::cos(t), radiusY * std::sin(t), 0.0 };
    }

    Point3D Ellipse::getDerivative(double t) const {
        return { -radiusX * std::sin(t), radiusY * std::cos(t), 0.0 };
    }

    Helix::Helix(double radius, double step) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
        this->radius = radius;
        this->step = step;
    }

    Point3D Helix::getPoint(double t) const {
        return { radius * std::cos(t), radius * std::sin(t), step * t / (2 * PI) };
    }

    Point3D Helix::getDerivative(double t) const {
        return { -radius * std::sin(t), radius * std::cos(t), step / (2 * PI) };
    }
}
