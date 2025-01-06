#pragma once
#include <iostream>
#include <cmath>
#include <stdexcept>

#ifndef PI
#define PI 3.141592653589
#endif // !PI

#define BUILDING_CURVE_DLL

#ifdef BUILDING_CURVE_DLL
#define CURVE_API __declspec(dllexport)
#else
#define CURVE_API __declspec(dllimport) 
#endif

namespace Curve3D {
    struct CURVE_API Point3D {
        double x, y, z;
        Point3D() : x(0), y(0), z(0) {};
        Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
        friend std::ostream& operator<<(std::ostream& os, const Point3D& point) {
            os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
            return os;
        }
    };

    class CURVE_API Curve {
    public:
        virtual Point3D getPoint(double t) const = 0;         
        virtual Point3D getDerivative(double t) const = 0;  
        virtual ~Curve() = default;                          
    };

    class CURVE_API Circle : public Curve {
    private:
        double radius;
    public:
        explicit Circle(double radius);
        Point3D getPoint(double t) const override;
        Point3D getDerivative(double t) const override;
        double getRadius() const;
    };

    class CURVE_API Ellipse : public Curve {
    private:
        double radiusX, radiusY;
    public:
        explicit Ellipse(double radiusX, double radiusY);
        Point3D getPoint(double t) const override;
        Point3D getDerivative(double t) const override;
    };

    class CURVE_API Helix : public Curve {
    private:
        double radius, step;
    public:
        explicit Helix(double radius, double step);
        Point3D getPoint(double t) const override;
        Point3D getDerivative(double t) const override;
    };
}
