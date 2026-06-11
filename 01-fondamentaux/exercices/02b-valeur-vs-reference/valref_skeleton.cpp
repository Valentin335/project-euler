// Exercice 02b — Valeur ou référence.
// Complète le corps des fonctions ci-dessous. Les signatures sont imposées
// par valref.hpp : ne les modifie pas.
//
// L'idée centrale de cet exercice : en C++, par DÉFAUT, on passe les
// arguments PAR COPIE. La fonction reçoit son propre exemplaire ; ce
// qu'elle en fait reste chez elle. Pour agir sur la variable de l'appelant,
// on passe PAR RÉFÉRENCE avec un &. Une référence T& est un ALIAS : un autre
// nom pour la MÊME variable. La modifier modifie l'original.
#include "valref.hpp"

void double_par_copie(int x) {
    // Ici, x est une COPIE de la variable de l'appelant.
    // Le corps ci-dessous double bien x... mais c'est SANS effet visible à
    // l'extérieur : on ne fait que modifier la copie locale, qui disparaît à
    // la fin de la fonction.
    //
    // TODO: tu n'as RIEN à changer ici. Laisse cette ligne telle quelle.
    //       Observe simplement : le test attend que la variable de l'appelant
    //       reste INCHANGÉE (a == 5). C'est la preuve que x était une copie.
    (void)x;  // évite un warning, ne change rien au comportement
    x *= 2;   // modifie seulement la copie locale -> aucun effet dehors
}

void double_par_reference(int& x) {
    // Ici, x est une RÉFÉRENCE (un alias) vers la variable de l'appelant.
    // Modifier x, c'est modifier directement l'original.
    //
    // TODO: fais en sorte que la variable de l'appelant soit DOUBLÉE.
    //       Rappel : pas besoin de syntaxe spéciale grâce au &, tu manipules
    //       x exactement comme un int normal — mais cette fois ça « sort »
    //       de la fonction. Le test attend b == 10 après l'appel sur b == 5.
    (void)x;  // BIDON : à remplacer par ton code
}

void ajoute_a_tous(std::vector<int>& v, int delta) {
    // Ici, v est une RÉFÉRENCE vers le vector de l'appelant : pas de copie.
    // Tu travailles directement sur SON vector.
    //
    // TODO: ajoute delta à CHAQUE élément de v, en place.
    //       Pistes : parcours le vector (boucle for classique sur les indices,
    //       ou for-range « for (int& e : v) »), et incrémente chaque élément.
    //       Attention : si tu écris « for (int e : v) », e est une COPIE de
    //       l'élément — exactement le piège de cet exercice ! Pour modifier
    //       l'élément dans le vector, il faut une référence sur l'élément.
    //       Cas particulier à garder en tête : si v est vide, il n'y a rien à
    //       faire (la boucle ne tourne tout simplement pas).
    (void)v;      // BIDON : à remplacer par ton code
    (void)delta;  // BIDON : à remplacer par ton code
}
