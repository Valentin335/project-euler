#include "check.hpp"
#include "optionnel.hpp"

int main() {
    CHECK(index_of({10, 20, 30}, 20) == std::optional<std::size_t>{1});
    CHECK(index_of({1, 2}, 9) == std::nullopt);

    CHECK(safe_divide(10, 2) == std::optional<int>{5});
    CHECK(safe_divide(1, 0) == std::nullopt);

    return check::report();
}
