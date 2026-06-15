#include "check.hpp"
#include "dispatch.hpp"

int main() {
    CHECK_EQ(apply_command('i', 5), std::string("info 5"));
    CHECK_EQ(apply_command('d', 5), std::string("double 10"));
    CHECK_EQ(apply_command('n', 5), std::string("neg -5"));
    CHECK_EQ(apply_command('x', 5), std::string("inconnu"));

    return check::report();
}
