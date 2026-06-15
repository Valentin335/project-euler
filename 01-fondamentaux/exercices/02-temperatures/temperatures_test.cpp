#include "check.hpp"
#include "temperatures.hpp"

#include <cstring>

int main() {
    CHECK_EQ(celsius_to_fahrenheit(0.0), 32.0);
    CHECK_EQ(celsius_to_fahrenheit(100.0), 212.0);
    CHECK_EQ(fahrenheit_to_celsius(212.0), 100.0);

    CHECK(std::strcmp(water_state(-5.0), "solide") == 0);
    CHECK(std::strcmp(water_state(20.0), "liquide") == 0);
    CHECK(std::strcmp(water_state(100.0), "gazeux") == 0);

    return check::report();
}
