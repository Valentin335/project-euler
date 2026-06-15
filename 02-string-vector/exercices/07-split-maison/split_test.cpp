#include "check.hpp"
#include "split.hpp"

int main() {
    CHECK_EQ(split("a,b,c", ','), (std::vector<std::string>{"a", "b", "c"}));
    CHECK_EQ(split("a,,b", ','), (std::vector<std::string>{"a", "", "b"}));
    CHECK_EQ(split("", ','), (std::vector<std::string>{""}));
    CHECK_EQ(split("abc", ','), (std::vector<std::string>{"abc"}));
    CHECK_EQ(split(",x", ','), (std::vector<std::string>{"", "x"}));

    return check::report();
}
