#include "check.hpp"
#include "histogram.hpp"

int main() {
    CHECK_EQ(count_char("banana", 'a'), 3);
    CHECK_EQ(count_char("banana", 'z'), 0);
    CHECK_EQ(count_char("", 'a'), 0);

    const std::vector<int> h = char_histogram("aAbB!");
    CHECK_EQ(h.size(), static_cast<std::size_t>(26));
    CHECK_EQ(h[0], 2);  // a / A
    CHECK_EQ(h[1], 2);  // b / B
    CHECK_EQ(h[2], 0);  // c

    return check::report();
}
