#include "check.hpp"
#include "config.hpp"

#include <map>
#include <string>

int main() {
    using Config = std::map<std::string, std::string>;

    // Cas nominal : deux entrées simples.
    CHECK(parse_config({"a=1", "b=2"}) == (Config{{"a", "1"}, {"b", "2"}}));

    // Clé en double : la dernière valeur gagne.
    CHECK_EQ(parse_config({"x=hello", "x=world"})["x"], std::string("world"));

    // Ligne sans '=' : ignorée -> map vide.
    CHECK(parse_config({"bad"}).empty());

    // Valeur vide après le '='.
    CHECK_EQ(parse_config({"k="})["k"], std::string(""));

    // Entrée vide -> map vide.
    CHECK(parse_config({}).empty());

    return check::report();
}
