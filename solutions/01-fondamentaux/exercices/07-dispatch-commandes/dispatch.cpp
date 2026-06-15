#include "dispatch.hpp"

std::string apply_command(char cmd, int n) {
    switch (cmd) {
        case 'i': return "info " + std::to_string(n);
        case 'd': return "double " + std::to_string(2 * n);
        case 'n': return "neg " + std::to_string(-n);
        default:  return "inconnu";
    }
}
