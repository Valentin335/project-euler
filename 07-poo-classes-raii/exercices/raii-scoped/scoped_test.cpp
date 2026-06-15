// =====================================================================
//  scoped_test.cpp — Tests fournis (NE PAS MODIFIER)
//
//  Compile-le avec ton scoped_skeleton.cpp pour vérifier ta solution.
//  Tant que le destructeur est un bouchon, le test échoue : c'est
//  normal. Ton but est de le faire passer.
// =====================================================================

#include "check.hpp"
#include "scoped.hpp"

#include <string>

int main()
{
    // Deux appenders dans la MÊME portée. Ils sont construits dans
    // l'ordre a puis b. À la sortie du bloc, ils sont détruits dans
    // l'ordre INVERSE : b d'abord, puis a.
    //   -> b ajoute "B", ensuite a ajoute "A"  ==>  log == "BA"
    std::string log;
    {
        ScopedAppender a(log, "A");
        ScopedAppender b(log, "B");
    }  // ici : ~b() puis ~a()
    CHECK_EQ(log, std::string("BA"));   // B détruit avant A

    // -- Pourquoi la classe est NON copiable --------------------------
    // ScopedAppender supprime son constructeur de copie. Les deux
    // lignes ci-dessous (laissées en commentaire, donc NON compilées)
    // provoqueraient une ERREUR de compilation du type
    // « use of deleted function ScopedAppender(const ScopedAppender&) ».
    // Décommente-les pour le constater par toi-même :
    //
    //     ScopedAppender original(log, "X");
    //     ScopedAppender copie(original);   // interdit : copie supprimée
    //
    // C'est voulu : copier un objet RAII dupliquerait l'action de sortie.

    return check::report();
}
