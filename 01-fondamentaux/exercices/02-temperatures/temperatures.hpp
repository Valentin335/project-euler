#pragma once
// Signatures imposées — NE PAS MODIFIER.

// Celsius → Fahrenheit.
double celsius_to_fahrenheit(double c);

// Fahrenheit → Celsius.
double fahrenheit_to_celsius(double f);

// Celsius → état de l'eau : "solide" (<=0), "liquide" (<100), "gazeux" (>=100).
const char* water_state(double celsius);
