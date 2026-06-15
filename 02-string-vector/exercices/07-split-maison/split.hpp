#pragma once
// split.hpp — signatures imposées. NE PAS MODIFIER.

#include <string>
#include <vector>

std::vector<std::string> split(const std::string& s, char sep);  // (s, sep) → champs séparés par sep, vides conservés ; "" → {""}
