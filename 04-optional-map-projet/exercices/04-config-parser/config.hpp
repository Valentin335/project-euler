#pragma once
// NE PAS MODIFIER
#include <map>
#include <string>
#include <vector>

// lignes "cle=valeur" -> map cle->valeur ; ligne sans '=' ignorée ; doublon : la dernière gagne
std::map<std::string, std::string> parse_config(const std::vector<std::string>& lignes);
