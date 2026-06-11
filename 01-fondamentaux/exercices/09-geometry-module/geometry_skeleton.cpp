// =====================================================================
//  geometry_skeleton.cpp — À COMPLÉTER
//
//  Renomme/copie ce fichier (ou édite-le directement) et remplis le
//  corps de chaque fonction. Pour l'instant ce sont des bouchons qui
//  renvoient des valeurs neutres : le projet COMPILE mais les tests
//  échouent. C'est normal, c'est à toi de coder.
//
//  Remarque : on inclut le .hpp puis on ROUVRE le namespace geom pour
//  y écrire les définitions. Le nom doit correspondre exactement à
//  celui des déclarations, sinon l'éditeur de liens ne te trouvera pas.
// =====================================================================
#include "geometry.hpp"

#include <stdexcept>   // std::invalid_argument (utile pour ta vraie version)
#include <cmath>       // std::sqrt, M_PI ou ta propre constante de PI

namespace geom {

    double rectangle_area(double w, double h)
    {
        // TODO: renvoyer l'aire du rectangle (largeur fois hauteur).
        (void)w;
        (void)h;
        return 0.0;  // bouchon : à remplacer
    }

    double circle_area(double r)
    {
        // TODO: si r < 0, lancer std::invalid_argument ; sinon renvoyer
        //       l'aire du disque (pi fois r au carré).
        //       Le bouchon ci-dessous NE lance PAS d'exception.
        (void)r;
        return 0.0;  // bouchon : à remplacer
    }

    double distance(double x1, double y1, double x2, double y2)
    {
        // TODO: renvoyer la distance euclidienne entre les deux points.
        (void)x1;
        (void)y1;
        (void)x2;
        (void)y2;
        return 0.0;  // bouchon : à remplacer
    }

}  // namespace geom
