#include "check.hpp"
#include "grille.hpp"

int main() {
    CHECK(make_grid(2, 3, 0) == Grid({{0, 0, 0}, {0, 0, 0}}));
    CHECK(grid_sum({{1, 2}, {3, 4}}) == 10);
    CHECK(transpose({{1, 2, 3}, {4, 5, 6}}) == Grid({{1, 4}, {2, 5}, {3, 6}}));
    CHECK(transpose({}) == Grid({}));
    return check::report();
}
