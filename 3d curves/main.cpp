#include "Curve3D.h" 

using namespace Curve3D;

int main() {
    std::vector<std::unique_ptr<Curve>> curves;

    curves.emplace_back(std::make_unique<Circle>(5));
    curves.emplace_back(std::make_unique<Ellipse>(3, 4));
    curves.emplace_back(std::make_unique<Helix>(2, 1));

    // ������ � �������� � �������
    for (const auto& curve : curves) {
        Point3D point = curve->getPoint(PI / 4);  // ����� ������ ����� ->
        Point3D derivative = curve->getDerivative(PI / 4);
        std::cout << "Point: " << point << std::endl;
        std::cout << "Derivative: " << derivative << std::endl;
    }
    return 0;
}