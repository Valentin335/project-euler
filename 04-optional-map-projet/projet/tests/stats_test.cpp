// Tests du projet de synthèse (fournis). Ne pas modifier.
// Ils valident les fonctions de stats.hpp (pas la boucle REPL).
// Compilation : voir COMPILER.md du projet.
#include "check.hpp"
#include "stats.hpp"

#include <stdexcept>
#include <string>
#include <vector>

// Comparaison de doubles à une tolérance près.
static bool approx(double a, double b) {
    const double diff = a - b;
    return (diff < 1e-9) && (diff > -1e-9);
}

int main() {
    using std::vector;
    using std::string;

    // --- sum -----------------------------------------------------------------
    CHECK(approx(stats::sum({1, 2, 3, 4}), 10.0));
    CHECK(approx(stats::sum({}), 0.0));
    CHECK(approx(stats::sum({-5, 5}), 0.0));

    // --- mean ----------------------------------------------------------------
    CHECK(approx(stats::mean({2, 4, 6}), 4.0));
    CHECK(approx(stats::mean({1, 2}), 1.5));
    CHECK_THROWS(stats::mean(vector<double>{}), std::domain_error);

    // --- min / max -----------------------------------------------------------
    CHECK(approx(stats::min_value({3, -1, 2}), -1.0));
    CHECK(approx(stats::max_value({3, -1, 2}), 3.0));
    CHECK_THROWS(stats::min_value(vector<double>{}), std::domain_error);
    CHECK_THROWS(stats::max_value(vector<double>{}), std::domain_error);

    // --- median --------------------------------------------------------------
    CHECK(approx(stats::median({3, 1, 2}), 2.0));          // impair
    CHECK(approx(stats::median({4, 1, 3, 2}), 2.5));       // pair -> moyenne
    CHECK(approx(stats::median({5}), 5.0));
    CHECK_THROWS(stats::median(vector<double>{}), std::domain_error);

    // --- sort_in_place -------------------------------------------------------
    {
        vector<double> v{3, 1, 2};
        stats::sort_in_place(v);
        CHECK(v == (vector<double>{1, 2, 3}));
    }
    {
        vector<double> v{3, 1, 2};
        stats::sort_in_place(v, false);
        CHECK(v == (vector<double>{3, 2, 1}));
    }

    // --- tokenize ------------------------------------------------------------
    CHECK(stats::tokenize("add 1 2 3") == (vector<string>{"add", "1", "2", "3"}));
    CHECK(stats::tokenize("   ") == (vector<string>{}));
    CHECK(stats::tokenize("") == (vector<string>{}));
    CHECK(stats::tokenize("one   two") == (vector<string>{"one", "two"}));

    // --- parse_numbers -------------------------------------------------------
    {
        const vector<string> toks{"add", "1", "2.5"};
        CHECK(stats::parse_numbers(toks, 1) == (vector<double>{1.0, 2.5}));
    }
    CHECK_THROWS(stats::parse_numbers(vector<string>{"x"}, 0), std::invalid_argument);

    return check::report();
}
