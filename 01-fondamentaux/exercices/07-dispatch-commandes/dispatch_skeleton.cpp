#include "dispatch.hpp"

std::string apply_command(char cmd, int n) {
    /* cmd, n → "info n" / "double 2n" / "neg -n" / "inconnu" */
    if (cmd == 'i'){
        return "info " + std::to_string(n); 
    }
    if (cmd == 'd'){
        return "double " + std::to_string(2*n); 
    }
    if (cmd == 'n'){
        return "neg " + std::to_string(-n); 
    }
    return "inconnu";
}
