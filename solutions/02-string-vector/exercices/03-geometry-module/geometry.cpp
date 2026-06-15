#include "geometry.hpp"

#include <cmath>     // std::hypot, std::numbers
#include <numbers>   // std::numbers::pi
#include <stdexcept>

namespace geom {

double rectangle_area(double w, double h) {
    return w * h;
}

double circle_area(double r) {
    // Garde d'entrée : un rayon négatif n'a pas de sens.
    if (r < 0) {
        throw std::invalid_argument("circle_area : rayon negatif");
    }
    return std::numbers::pi * r * r;
}

double distance(double x1, double y1, double x2, double y2) {
    // std::hypot évite le débordement de dx*dx + dy*dy.
    return std::hypot(x2 - x1, y2 - y1);
}

}  // namespace geom
