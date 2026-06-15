#include "check.hpp"

#include "geometry.hpp"

#include <cmath>

int main() {
    CHECK_EQ(geom::rectangle_area(3, 4), 12.0);

    // circle_area(1) ~ 3.14159
    CHECK(std::abs(geom::circle_area(1) - 3.14159) < 1e-4);

    CHECK_THROWS(geom::circle_area(-1), std::invalid_argument);

    CHECK_EQ(geom::distance(0, 0, 3, 4), 5.0);

    return check::report();
}
