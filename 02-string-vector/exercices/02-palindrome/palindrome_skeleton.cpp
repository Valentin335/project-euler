#include "palindrome.hpp"

std::string reverse(const std::string& s) {
    /* s → s inversée */
    std::string reverse_s(s.rbegin(),s.rend());
    return {};
}

bool is_palindrome(const std::string& s) {
    /* s → palindrome ? (casse/espaces ignorés) */
    std::string s_clean;
    s_clean.reserve(s.size());
    for (auto &x:s){
        if (!std::isspace(x)){
            s_clean.push_back(static_cast<char>(std::tolower(x)));
        }
    }


    return std::equal(s.begin(),s.end(),s.rbegin());
}
