#include "check.hpp"

#include "palindrome.hpp"

int main() {
    CHECK_EQ(reverse("abc"), std::string("cba"));

    CHECK(is_palindrome("kayak"));
    CHECK(is_palindrome("Kayak"));
    CHECK(!is_palindrome("hello"));
    CHECK(is_palindrome(""));

    return check::report();
}
