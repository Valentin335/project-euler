// =====================================================================
//  scoped.cpp — CORRIGÉ DE RÉFÉRENCE
//
//  RAII (Resource Acquisition Is Initialization) : on associe une
//  ressource/action à la durée de vie d'un objet. Le destructeur, appelé
//  AUTOMATIQUEMENT en fin de portée (et dans l'ordre inverse de
//  construction), garantit l'exécution de l'action — même en cas
//  d'exception.
// =====================================================================
#include "scoped.hpp"

#include <utility>   // std::move

// Liste d'initialisation : on initialise les membres directement (plus
// efficace que les affecter dans le corps). std::move sur on_exit transfère
// la chaîne au lieu de la copier (idiome de move, vu au ch.10).
ScopedAppender::ScopedAppender(std::string& target, std::string on_exit)
    : target_(target), on_exit_(std::move(on_exit))
{
}

// Action de sortie garantie par RAII : on complète la chaîne référencée.
ScopedAppender::~ScopedAppender()
{
    target_ += on_exit_;
}
