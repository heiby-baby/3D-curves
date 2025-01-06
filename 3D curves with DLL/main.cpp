#include <iostream>
#include <vector>
#include <algorithm>
#include "Curve3D/include/Curve3D DLL.h"

using namespace Curve3D;

int main() {
    try {
        std::vector<std::unique_ptr<Curve>> curves;

        for (int i = 0; i < 30; i++) {
            int rand_number = rand() + 1;
            if (rand_number % 3 == 0) {
                curves.emplace_back(std::make_unique<Circle>(rand_number % 100));
            }
            if (rand_number % 3 == 1) {
                curves.emplace_back(std::make_unique<Ellipse>(rand_number % 50, rand_number % 41));
            }
            if (rand_number % 3 == 2) {
                curves.emplace_back(std::make_unique<Helix>(rand_number % 36, rand_number % 100));
            }
        }


        for (std::unique_ptr<Curve>& curve : curves) {
            Point3D point = curve->getPoint(PI / 4);
            Point3D derivative = curve->getDerivative(PI / 4);
            std::cout << "Point: " << point << std::endl;
            std::cout << "Derivative: " << derivative << std::endl;
        }

        std::vector<std::unique_ptr<Circle>> circles;

        for (size_t i = 0; i < curves.size(); i++) {
            if (dynamic_cast<Circle*>(curves[i].get())) {
                circles.emplace_back(std::unique_ptr<Circle>(static_cast<Circle*>(curves[i].release())));
                curves.erase(curves.begin() + i);
                i--;
            }
        }

        std::sort(circles.begin(), circles.end(), [](const std::unique_ptr<Circle>& a, const std::unique_ptr<Circle>& b) {
            return a->getRadius() < b->getRadius();
            });


        double TotalRadiusPar = 0.0;
#pragma omp parallel for reduction(+:TotalRadiusPar)
        for (size_t i = 0; i < circles.size(); ++i) {
            TotalRadiusPar += circles[i]->getRadius();
        }
        std::cout << "Total Radius (parallel): " << TotalRadiusPar << std::endl;

    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    getchar();

    return 0;
	return 0;
}