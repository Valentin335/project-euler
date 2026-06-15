#include "check.hpp"
#include "echauffement.hpp"

int main() {
    CHECK_EQ(square(5), 25);
    CHECK_EQ(square(-3), 9);

    CHECK_EQ(sum_to(0), 0LL);
    CHECK_EQ(sum_to(100), 5050LL);
    CHECK_EQ(sum_to(100000), 5000050000LL);

    CHECK(is_even(0));
    CHECK(!is_even(7));

    return check::report();
}
