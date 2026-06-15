#include "config.hpp"

std::map<std::string, std::string> parse_config(const std::vector<std::string>& lignes) {
    std::map<std::string, std::string> config;
    for (const std::string& ligne : lignes) {
        const std::size_t pos = ligne.find('=');
        if (pos == std::string::npos) continue;  // pas de '=' : on ignore
        const std::string cle = ligne.substr(0, pos);
        const std::string val = ligne.substr(pos + 1);
        config[cle] = val;  // doublon : la dernière valeur écrase la précédente
    }
    return config;
}
