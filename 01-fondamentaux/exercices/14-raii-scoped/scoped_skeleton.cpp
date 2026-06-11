// =====================================================================
//  scoped_skeleton.cpp — À COMPLÉTER
//
//  On inclut le .hpp (qui déclare la classe) puis on écrit ici le
//  corps du constructeur et du destructeur.
//
//  Pour l'instant le DESTRUCTEUR est un bouchon : il ne fait RIEN.
//  Le projet COMPILE mais les tests échouent, c'est normal. C'est à
//  toi d'implémenter le destructeur pour qu'il tienne sa promesse.
//
//  Remarque sur le constructeur : la liste d'initialisation (le « : »
//  après la signature) n'est PAS optionnelle ici. target_ est une
//  RÉFÉRENCE : une référence doit être liée dès sa naissance et ne
//  peut pas l'être dans le corps. Sans la liste d'initialisation, le
//  code ne compilerait même pas. Ce n'est donc pas la « solution » de
//  l'exo, juste le minimum syntaxique : il t'est donné.
// =====================================================================
#include "scoped.hpp"

ScopedAppender::ScopedAppender(std::string& target, std::string on_exit)
    : target_(target), on_exit_(on_exit)
{
    // Rien à faire à la construction : on a déjà mémorisé target_ et
    // on_exit_ via la liste d'initialisation ci-dessus.
}

ScopedAppender::~ScopedAppender()
{
    // TODO: ajouter on_exit_ à target_
    // (le bouchon ne fait rien : target_ n'est pas modifié)
}
