// =====================================================================
//  scoped.hpp — Interface de la classe ScopedAppender (NE PAS MODIFIER)
//
//  Ce header ne contient QUE la *déclaration* de la classe : ses
//  membres et les signatures de ses méthodes. Les *définitions* (le
//  corps du constructeur et du destructeur) vont dans le .cpp.
//
//  ScopedAppender est un objet RAII : il « tient » une ressource
//  pendant toute sa durée de vie et garantit une action à sa
//  destruction. Ici, l'action est d'ajouter une chaîne on_exit_ à la
//  fin de la chaîne référencée target_, au moment où l'objet meurt
//  (sortie de portée).
// =====================================================================
#pragma once

#include <string>

class ScopedAppender {
public:
    // Construit l'appender : mémorise une référence vers target et la
    // chaîne on_exit à rajouter plus tard, à la destruction.
    ScopedAppender(std::string& target, std::string on_exit);

    // Destructeur : doit ajouter on_exit_ à la fin de target_.
    ~ScopedAppender();

    // Classe NON copiable : on interdit explicitement la copie et
    // l'affectation. (Copier un objet qui « possède » une action de
    // sortie n'aurait pas de sens : qui exécuterait l'action ?)
    ScopedAppender(const ScopedAppender&) = delete;
    ScopedAppender& operator=(const ScopedAppender&) = delete;

private:
    std::string& target_;   // référence vers la chaîne à compléter
    std::string on_exit_;   // ce qu'on ajoutera à la destruction
};
