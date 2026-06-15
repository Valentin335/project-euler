#include "split.hpp"

std::vector<std::string> split(const std::string& s, char sep) {
    std::vector<std::string> champs;
    std::size_t pos = 0;
    // On découpe chaque champ délimité à droite par sep, jusqu'à npos.
    while (true) {
        const std::size_t next = s.find(sep, pos);
        if (next == std::string::npos) {
            champs.push_back(s.substr(pos));  // dernier champ (jusqu'à la fin)
            break;
        }
        champs.push_back(s.substr(pos, next - pos));  // champ [pos, next)
        pos = next + 1;                               // saute le séparateur
    }
    return champs;
}
