# Chapitre 3 — Lire le monde : I/O, flux et parsing

Entrées/sorties en profondeur (`getline`, état du flux, lecture jusqu'à EOF),
`std::istringstream` pour découper une ligne, et conversion robuste
texte → nombre (`stoll`/`stod` avec `pos`).

## Le cours

Compile le support de cours :

```bash
cd cours
latexmk -pdf cours.tex     # produit cours.pdf
```

(ou, sans `latexmk` : `pdflatex cours.tex`.)

Lis `cours.pdf` **en premier**. Il couvre trois sections :

1. I/O en profondeur : lire vraiment l'entrée standard (`getline`, état du
   flux, lecture jusqu'à EOF).
2. `std::istringstream` : brancher un flux sur une chaîne pour la découper.
3. Convertir du texte en nombre, proprement (`stoll`/`stod` + `pos`).

## Les exercices

Trois exercices dans `exercices/`, dans l'ordre du tableau. L'exercice **02
est 100 % autonome** : pas de squelette, pas de tests fournis, pas de
signatures imposées — tu écris le programme complet, `main` compris.

| #  | Exercice | ★ | Thème |
|----|----------|---|-------|
| 01 | Parsing d'entiers | ★★ | `stoll` + `pos`, `istringstream`, exceptions |
| 02 | Mini-calculatrice *(autonome)* | ★★ | `getline`, `istringstream`, état du flux |
| 03 | Tokenize | ★ | `istringstream` + `>>`, découpage en mots |

## Comment travailler

Pour les exercices à squelette (**01** et **03**) :

1. Lis `enonce.md` (objectif, signatures, section *Outils* / *Aide*, cas de
   test).
2. Regarde les signatures imposées dans le `.hpp` (ne le modifie pas).
3. Complète le fichier `*_skeleton.cpp` (**ta solution**) — les commentaires
   `/* entrée → sortie */` te rappellent le contrat.
4. Compile et teste (voir `COMPILER.md`). Code retour 0 = tout passe.
5. Quand tous les tests passent, dis-le — on pourra comparer avec le corrigé.

Pour l'exercice **autonome (02)** : il n'y a ni `.hpp`, ni squelette, ni
test. Crée toi-même `calculatrice.cpp` dans le dossier de l'exercice et écris
**tout** le programme (`main` inclus) à partir de l'énoncé (entrée → sortie).
Compile-le (voir `COMPILER.md`), vérifie son comportement à la main, puis
dis-le pour comparer avec le corrigé.

## Table de couverture (règle d'or)

Aucun outil n'est exigé sans avoir été présenté — soit dans un chapitre
antérieur, soit dans le cours de ce chapitre, soit dans une section *Aide* de
l'énoncé lui-même.

| Exercice | Outils exigés | Source |
|----------|---------------|--------|
| 01 Parsing d'entiers | `std::stoll` + `pos`, `pos == s.size()` | cours ch.3 §Convertir du texte en nombre |
| 01 Parsing d'entiers | `std::istringstream` + `>>` | cours ch.3 §`std::istringstream` |
| 01 Parsing d'entiers | `std::string`, `std::vector` | cours ch.2 §`std::string` / §`std::vector` |
| 01 Parsing d'entiers | `throw` / `std::invalid_argument` | cours ch.1 §Gestion d'erreurs |
| 02 Mini-calculatrice | `std::getline(std::cin, …)` | cours ch.3 §I/O en profondeur |
| 02 Mini-calculatrice | `std::istringstream` + `>>` (`double`, `char`) | cours ch.3 §`std::istringstream` |
| 02 Mini-calculatrice | état du flux (test d'échec de `>>`) | cours ch.3 §I/O en profondeur |
| 02 Mini-calculatrice | `std::cerr`, boucle `while`, `if` | cours ch.1 §Entrées/sorties / §Structures de contrôle |
| 03 Tokenize | `std::istringstream` + `>>` | cours ch.3 §`std::istringstream` (+ section *Aide* de l'énoncé) |
| 03 Tokenize | `std::string`, `std::vector` | cours ch.2 §`std::string` / §`std::vector` |

---

Les corrigés sont dans `solutions/`, à consulter **après** avoir réussi.
