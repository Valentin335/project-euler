#pragma once
//
// check.hpp — mini-harnais de test maison (chapitre 1 de la formation).
//
// Pourquoi un harnais maison ? Tant qu'on n'a pas vu CMake (chapitre 2), on
// n'installe pas Catch2. Ce header te donne l'essentiel — vérifier des
// conditions, comparer des valeurs, attendre des exceptions, afficher un
// bilan — en ~150 lignes lisibles. Au chapitre 2 on basculera vers Catch2, et
// tu retrouveras les mêmes idées en plus complet.
//
// Usage :
//
//     #include "check.hpp"
//
//     int main() {
//         CHECK(2 + 2 == 4);
//         CHECK_EQ(square(5), 25);
//         CHECK_THROWS(first_char(""), std::invalid_argument);
//         return check::report();   // 0 si tout passe, 1 sinon
//     }
//
// Compilation type (chapitre 1) :
//     g++ -std=c++20 -Wall -Wextra -Wpedantic -I <dossier_de_check.hpp>
//         exo_skeleton.cpp exo_test.cpp -o test && ./test
//
// Note : les macros (CHECK, CHECK_EQ, ...) sont nécessairement globales — c'est
// la nature du préprocesseur. Tout le reste vit dans le namespace `check`.

#include <chrono>
#include <cstdint>
#include <exception>
#include <iostream>
#include <string>
#include <type_traits>

namespace check {

// -- Bilan global, encapsulé dans un static local (pas de souci d'ordre
//    d'initialisation entre fichiers). ---------------------------------------
struct Registry {
    int passed = 0;
    int failed = 0;
};

inline Registry& registry() {
    static Registry instance;
    return instance;
}

// -- Détection « ce type est-il affichable avec operator<< ? » ---------------
//    Concept C++20 : vrai si `std::cout << valeur` compile.
template <typename T>
concept Printable = requires(std::ostream& os, const T& v) {
    { os << v } -> std::same_as<std::ostream&>;
};

// Affiche `v` si possible, sinon un marqueur générique.
template <typename T>
void print_value(std::ostream& os, const T& v) {
    if constexpr (Printable<T>) {
        os << v;
    } else {
        os << "<valeur non affichable>";
    }
}

// ---------------------------------------------------------------------------
// Compteur d'opérations.
//
// Idée : pour valider une CONTRAINTE DE COMPLEXITÉ (« trie en moins de N
// comparaisons »), mesurer le temps est fragile (machine, -O2, charge). On
// préfère COMPTER les opérations. Le compteur ci-dessous est global et remis à
// zéro avant chaque mesure.
//
// Utilisation typique : l'exercice manipule des `check::Counted<int>` au lieu
// d'`int`. Chaque comparaison (<, >, <=, >=, ==, !=, <=>) incrémente le
// compteur. On vérifie ensuite avec CHECK_OPS_UNDER.
// ---------------------------------------------------------------------------
struct OpCounter {
    std::uint64_t comparisons = 0;
};

inline OpCounter& op_counter() {
    static OpCounter instance;
    return instance;
}

inline void reset_ops() { op_counter().comparisons = 0; }
inline std::uint64_t ops() { return op_counter().comparisons; }

// Enveloppe un type comparable et compte chaque comparaison.
template <typename T>
struct Counted {
    T value{};

    Counted() = default;
    Counted(T v) : value(v) {}  // conversion implicite volontaire (ergonomie)

    friend bool operator<(const Counted& a, const Counted& b) {
        ++op_counter().comparisons;
        return a.value < b.value;
    }
    friend bool operator>(const Counted& a, const Counted& b)  { return b < a; }
    friend bool operator<=(const Counted& a, const Counted& b) { return !(b < a); }
    friend bool operator>=(const Counted& a, const Counted& b) { return !(a < b); }
    friend bool operator==(const Counted& a, const Counted& b) {
        ++op_counter().comparisons;
        return a.value == b.value;
    }
    friend bool operator!=(const Counted& a, const Counted& b) { return !(a == b); }

    // Affichage, pour que CHECK_EQ sur des Counted reste lisible.
    friend std::ostream& operator<<(std::ostream& os, const Counted& c) {
        return os << c.value;
    }
};

// -- Couleurs ANSI (désactivables) -------------------------------------------
inline const char* green() { return "\033[32m"; }
inline const char* red()   { return "\033[31m"; }
inline const char* reset() { return "\033[0m"; }

// -- Primitives appelées par les macros --------------------------------------
inline void record_pass() { ++registry().passed; }

inline void record_fail(const char* file, int line, const std::string& msg) {
    ++registry().failed;
    std::cout << red() << "ÉCHEC" << reset() << ' ' << file << ':' << line
              << " : " << msg << '\n';
}

template <typename A, typename B>
void check_eq(const A& a, const B& b, const char* expr_a, const char* expr_b,
              const char* file, int line, bool want_equal) {
    const bool equal = (a == b);
    if (equal == want_equal) {
        record_pass();
        return;
    }
    std::string msg = want_equal ? "CHECK_EQ(" : "CHECK_NE(";
    msg += expr_a;
    msg += ", ";
    msg += expr_b;
    msg += ")";
    std::cout << red() << "ÉCHEC" << reset() << ' ' << file << ':' << line
              << " : " << msg << "\n    gauche = ";
    print_value(std::cout, a);
    std::cout << "\n    droite = ";
    print_value(std::cout, b);
    std::cout << '\n';
    ++registry().failed;
}

// -- Mesure de temps (garde-fou anti-boucle-infinie / perf grossière) --------
// Renvoie la durée d'exécution de `fn` en millisecondes.
template <typename Fn>
double measure_ms(Fn&& fn) {
    const auto start = std::chrono::steady_clock::now();
    fn();
    const auto end = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

inline void record_time(double elapsed_ms, double limit_ms, const char* expr,
                        const char* file, int line) {
    if (elapsed_ms <= limit_ms) {
        record_pass();
        return;
    }
    std::string msg = "CHECK_UNDER_MS(";
    msg += expr;
    msg += ") : ";
    std::cout << red() << "ÉCHEC" << reset() << ' ' << file << ':' << line
              << " : " << msg << elapsed_ms << " ms > limite " << limit_ms
              << " ms\n";
    ++registry().failed;
}

inline void record_ops(std::uint64_t used, std::uint64_t limit, const char* expr,
                       const char* file, int line) {
    if (used <= limit) {
        record_pass();
        return;
    }
    std::cout << red() << "ÉCHEC" << reset() << ' ' << file << ':' << line
              << " : CHECK_OPS_UNDER(" << expr << ") : " << used
              << " opérations > limite " << limit << '\n';
    ++registry().failed;
}

// -- Bilan final -------------------------------------------------------------
// Renvoie 0 si aucun échec, 1 sinon (à utiliser comme code de retour du main).
inline int report() {
    const int passed = registry().passed;
    const int failed = registry().failed;
    const int total = passed + failed;
    std::cout << "\n----------------------------------------\n";
    std::cout << "Bilan : " << passed << '/' << total << " test(s) réussi(s).\n";
    if (failed == 0) {
        std::cout << green() << "TOUS LES TESTS PASSENT." << reset() << '\n';
        return 0;
    }
    std::cout << red() << failed << " ÉCHEC(S)." << reset() << '\n';
    return 1;
}

}  // namespace check

// ---------------------------------------------------------------------------
// Macros publiques. Le `do { ... } while (0)` permet d'utiliser ces macros
// comme une instruction normale (avec un point-virgule), même dans un `if`
// sans accolades.
// ---------------------------------------------------------------------------

#define CHECK(cond)                                                            \
    do {                                                                       \
        if (cond) {                                                            \
            ::check::record_pass();                                            \
        } else {                                                               \
            ::check::record_fail(__FILE__, __LINE__, "CHECK(" #cond ")");      \
        }                                                                      \
    } while (0)

#define CHECK_EQ(a, b)                                                         \
    ::check::check_eq((a), (b), #a, #b, __FILE__, __LINE__, true)

#define CHECK_NE(a, b)                                                         \
    ::check::check_eq((a), (b), #a, #b, __FILE__, __LINE__, false)

#define CHECK_THROWS(expr, ExceptionType)                                      \
    do {                                                                       \
        bool caught_expected = false;                                         \
        bool caught_other = false;                                            \
        try {                                                                  \
            (void)(expr);                                                      \
        } catch (const ExceptionType&) {                                       \
            caught_expected = true;                                           \
        } catch (...) {                                                        \
            caught_other = true;                                              \
        }                                                                      \
        if (caught_expected) {                                                 \
            ::check::record_pass();                                            \
        } else if (caught_other) {                                             \
            ::check::record_fail(__FILE__, __LINE__,                           \
                "CHECK_THROWS(" #expr ", " #ExceptionType                      \
                ") : exception d'un autre type levée");                       \
        } else {                                                               \
            ::check::record_fail(__FILE__, __LINE__,                           \
                "CHECK_THROWS(" #expr ", " #ExceptionType                      \
                ") : aucune exception levée");                                 \
        }                                                                      \
    } while (0)

#define CHECK_NOTHROW(expr)                                                    \
    do {                                                                       \
        try {                                                                  \
            (void)(expr);                                                      \
            ::check::record_pass();                                            \
        } catch (...) {                                                        \
            ::check::record_fail(__FILE__, __LINE__,                           \
                "CHECK_NOTHROW(" #expr ") : exception levée");                \
        }                                                                      \
    } while (0)

// Vérifie que `expr` s'exécute en moins de `limit_ms` millisecondes.
// Sert surtout de GARDE-FOU (boucle infinie, complexité catastrophique). La
// limite doit rester GÉNÉREUSE : le temps dépend de la machine et des options
// de compilation. Pour une vraie contrainte de complexité, préfère
// CHECK_OPS_UNDER.
#define CHECK_UNDER_MS(expr, limit_ms)                                         \
    do {                                                                       \
        const double elapsed__ = ::check::measure_ms([&]() { (void)(expr); });\
        ::check::record_time(elapsed__, (limit_ms), #expr, __FILE__, __LINE__);\
    } while (0)

// Remet le compteur d'opérations à zéro, exécute `expr`, puis vérifie que le
// nombre d'opérations comptées (comparaisons sur des check::Counted<T>) ne
// dépasse pas `max_ops`. Robuste et indépendant de la machine.
#define CHECK_OPS_UNDER(expr, max_ops)                                         \
    do {                                                                       \
        ::check::reset_ops();                                                  \
        (void)(expr);                                                          \
        ::check::record_ops(::check::ops(), (max_ops), #expr, __FILE__,        \
                            __LINE__);                                         \
    } while (0)
