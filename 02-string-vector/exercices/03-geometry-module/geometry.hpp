#pragma once
// NE PAS MODIFIER : signatures imposées de l'exercice.
#include <stdexcept>

namespace geom {

// (largeur, hauteur) → aire du rectangle.
double rectangle_area(double w, double h);

// rayon → aire du disque ; lève std::invalid_argument si r < 0.
double circle_area(double r);

// (x1, y1, x2, y2) → distance euclidienne entre les deux points.
double distance(double x1, double y1, double x2, double y2);

}  // namespace geom
