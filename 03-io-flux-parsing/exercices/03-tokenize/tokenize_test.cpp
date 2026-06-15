#include "check.hpp"
#include "tokenize.hpp"

int main() {
    CHECK(tokenize("a b c") == (std::vector<std::string>{"a", "b", "c"}));
    CHECK(tokenize("a   b") == (std::vector<std::string>{"a", "b"}));
    CHECK(tokenize("  x  ") == (std::vector<std::string>{"x"}));
    CHECK(tokenize("") == std::vector<std::string>{});
    CHECK(tokenize("   ") == std::vector<std::string>{});

    return check::report();
}
