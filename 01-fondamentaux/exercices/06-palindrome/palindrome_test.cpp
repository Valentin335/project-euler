// Tests de l'exercice 06 (fournis). Ne pas modifier.
// Compile avec ton palindrome_skeleton.cpp (voir COMPILER.md du chapitre).
#include "check.hpp"
#include "palindrome.hpp"

#include <string>

int main() {
    CHECK_EQ(reverse("abc"), std::string("cba"));
    CHECK_EQ(reverse(""), std::string(""));
    CHECK_EQ(reverse("a"), std::string("a"));

    CHECK(is_palindrome("kayak"));
    CHECK(!is_palindrome("hello"));
    CHECK(is_palindrome("Kayak"));
    CHECK(is_palindrome("A man a plan a canal Panama"));
    CHECK(is_palindrome(""));

    // --- Cas limites ajoutes ------------------------------------------------
    // reverse d'un palindrome redonne le palindrome lui-meme.
    CHECK_EQ(reverse("kayak"), std::string("kayak"));

    // Un seul caractere : c'est forcement un palindrome (rien a opposer).
    CHECK(is_palindrome("a"));

    // Deux caracteres differents : pas un palindrome.
    CHECK(!is_palindrome("ab"));

    // Insensibilite a la casse : "Ressasser" se lit pareil une fois mis en
    // minuscules ("ressasser").
    CHECK(is_palindrome("Ressasser"));

    // Phrase avec espaces et casse melangee, ASCII uniquement (pas d'accent).
    // En ignorant espaces et casse : "wasitacaroracatisaw".
    CHECK(is_palindrome("Was it a car or a cat I saw"));

    // Chiffres : la normalisation ne touche que casse et espaces, donc les
    // chiffres sont compares tels quels. "12321" est un palindrome.
    CHECK(is_palindrome("12321"));

    // Memes chiffres mais avec des espaces a ignorer : "12 3 21" -> "12321".
    CHECK(is_palindrome("12 3 21"));

    return check::report();
}
