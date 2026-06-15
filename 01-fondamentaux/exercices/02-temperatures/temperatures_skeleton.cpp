#include "temperatures.hpp"

double celsius_to_fahrenheit(double c) {
    /* c → c * 9/5 + 32 */
    return  c * 9/5 + 32;
}

double fahrenheit_to_celsius(double f) {
    /* f → (f - 32) * 5/9 */
    return (f - 32) * 5/9 ;
}

const char* water_state(double celsius) {
    /* celsius → "solide" / "liquide" / "gazeux" */
    if (celsius <=0){
        return "solide";
    }
    if (celsius <100){
        return "liquide";
    }
    return "gazeux";
}
