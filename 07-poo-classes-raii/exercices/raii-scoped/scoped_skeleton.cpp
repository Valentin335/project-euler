/* ScopedAppender : une classe dont le destructeur ajoute on_exit_ à la fin de
 * la chaîne référencée target_, automatiquement à la sortie de portée (RAII).
 * À compléter : le corps du destructeur. Le constructeur est fourni (la liste
 * d'initialisation est obligatoire car target_ est une référence). */
#include "scoped.hpp"

ScopedAppender::ScopedAppender(std::string& target, std::string on_exit)
    : target_(target), on_exit_(std::move(on_exit))
{
}

ScopedAppender::~ScopedAppender()
{
    /* TODO: ajouter on_exit_ à la fin de target_ */
}
