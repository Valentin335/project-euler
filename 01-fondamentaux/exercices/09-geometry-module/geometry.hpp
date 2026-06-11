// =====================================================================
//  geometry.hpp — Interface du module (NE PAS MODIFIER)
//
//  Ce header ne contient QUE les *signatures* (déclarations) des
//  fonctions. Les définitions (corps) vont dans le .cpp.
//  Toutes les fonctions vivent dans le namespace geom.
// =====================================================================
#pragma once

namespace geom {

    // Aire d'un rectangle de largeur w et de hauteur h.
    double rectangle_area(double w, double h);

    // Aire d'un disque de rayon r.
    // Doit lancer std::invalid_argument si r < 0.
    double circle_area(double r);

    // Distance euclidienne entre les points (x1, y1) et (x2, y2).
    double distance(double x1, double y1, double x2, double y2);

}  // namespace geom
