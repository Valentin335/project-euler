#include "temperatures.hpp"

double celsius_to_fahrenheit(double c) {
    return c * 9.0 / 5.0 + 32.0;  // littéraux double → pas de division entière
}

double fahrenheit_to_celsius(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}

const char* water_state(double celsius) {
    if (celsius <= 0.0) return "solide";   // cascade : du plus froid au plus chaud
    if (celsius < 100.0) return "liquide";
    return "gazeux";
}
