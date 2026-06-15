#include "grille.hpp"
#include <numeric>

Grid make_grid(std::size_t rows, std::size_t cols, int fill) {
    // Construction imbriquée : rows lignes, chacune un vector<int>(cols, fill).
    return Grid(rows, std::vector<int>(cols, fill));
}

int grid_sum(const Grid& g) {
    int total = 0;
    // Range-for sur lignes puis éléments.
    for (const auto& ligne : g)
        total += std::accumulate(ligne.begin(), ligne.end(), 0);
    return total;
}

Grid transpose(const Grid& g) {
    if (g.empty()) return {};            // garde : pas de ligne, donc pas de colonne.
    std::size_t rows = g.size();
    std::size_t cols = g.front().size();
    Grid r(cols, std::vector<int>(rows, 0)); // dims inversées.
    for (std::size_t i = 0; i < rows; ++i)
        for (std::size_t j = 0; j < cols; ++j)
            r.at(j).at(i) = g.at(i).at(j);
    return r;
}
