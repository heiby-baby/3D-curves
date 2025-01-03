#include "Curve3D.h" 

using namespace Curve3D;

int main() {
    std::vector<std::unique_ptr<Curve>> curves;

    curves.emplace_back(std::make_unique<Circle>(5));
    curves.emplace_back(std::make_unique<Ellipse>(3, 4));
    curves.emplace_back(std::make_unique<Helix>(2, 1));

    // Доступ к объектам в векторе
    for (const auto& curve : curves) {
        Point3D point = curve->getPoint(PI / 4);  // Вызов метода через ->
        Point3D derivative = curve->getDerivative(PI / 4);
        std::cout << "Point: " << point << std::endl;
        std::cout << "Derivative: " << derivative << std::endl;
    }
    return 0;
}