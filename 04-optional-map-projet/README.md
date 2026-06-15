# Chapitre 4 — Choisir et compter : optional, map, algorithmes

Modéliser proprement « une valeur ou rien » avec `std::optional`, associer et
compter avec `std::map`, et appeler les algorithmes essentiels de la STL
(`std::sort`, `std::accumulate`, `std::min_element`/`std::max_element`). Le
chapitre se termine par le **projet de synthèse** qui réunit tout depuis le
chapitre 1.

## Le cours

Compile le support de cours :

```bash
cd cours
latexmk -pdf cours.tex     # produit cours.pdf
```

(à défaut de `latexmk` : `pdflatex cours.tex`.)

Lis `cours.pdf` **en premier**. Il présente les outils du chapitre « en boîte
noire » — juste ce qu'il faut pour les employer sans se tromper : les quatre
algorithmes utiles, `std::optional`, `std::map` (avec l'idiome `++m[cle]` et le
parcours trié), puis le cadrage du projet de synthèse.

## Les exercices

Quatre exercices en difficulté croissante, dans `exercices/`. Suis l'ordre du
tableau de haut en bas.

| #  | Exercice | ★ | Thème |
|----|----------|---|-------|
| 01 | Valeur ou rien | ★ | `std::optional`, `nullopt` |
| 02 | Compteur de mots | ★★★ | `std::map`, comptage, tri par clé — **tu écris tout le programme** |
| 03 | Moyenne ou rien | ★ | `std::optional` + `std::accumulate`/`std::sort` |
| 04 | Config parser | ★★ | `std::map`, parsing `cle=valeur` |

L'exercice **02 est 100 % autonome** : pas de squelette, ni de `.hpp`, ni de
tests fournis. Tu écris le programme complet (`main` inclus) à partir de
l'énoncé, puis tu compares avec le corrigé.

## Comment travailler

Pour les exercices **01, 03, 04** (avec squelette) :

1. Lis `enonce.md` (objectif, signatures, section `## Outil`/`## Aide`, cas de
   test).
2. Regarde les signatures imposées dans le `.hpp` (ne le modifie pas).
3. Complète le fichier `*_skeleton.cpp` (**ta solution**) — les commentaires
   `/* entrée → sortie */` rappellent le contrat.
4. Compile et teste (voir `COMPILER.md`). Code retour 0 = tout passe.
5. Quand tous les tests passent, dis-le — on pourra comparer avec le corrigé.

Pour l'exercice **02 (autonome)** : crée `compteur.cpp` dans son dossier et
écris **tout** le programme (`main` compris) à partir de l'énoncé (entrée →
sortie attendue). Compile-le seul (voir `COMPILER.md`), vérifie le comportement
à la main, puis compare avec le corrigé.

## Le projet de synthèse

Dans `projet/` : un **mini-REPL de statistiques** (★★★★). Une boucle
lecture-évaluation-affichage qui maintient une liste de `double` et exécute des
commandes (`add`, `sum`, `mean`, `min`/`max`, `median`, `sort`, `list`,
`clear`, `help`, `quit`). Il réunit **tout** ce que tu as vu des chapitres 1 à
4 : I/O et parsing de flux, `std::string`/`std::vector`, `std::optional` et
`std::map`, exceptions, séparation `.hpp`/`.cpp`, namespaces.

L'architecture est imposée (`include/stats.hpp`, `src/stats_skeleton.cpp`,
`src/main_skeleton.cpp`, `tests/stats_test.cpp`) ; voir `projet/enonce.md` et
`projet/COMPILER.md`. À faire **une fois les exercices digérés**. Il sert de
pont vers le chapitre 5 : on le « cmakifiera » (bibliothèque `stats`,
exécutable `stats_repl`, tests migrés vers Catch2/`ctest`).

## Table de couverture (règle d'or)

Aucun outil n'est exigé sans avoir été présenté — soit dans un chapitre
antérieur, soit dans le cours de ce chapitre, soit dans une section `## Aide` de
l'énoncé.

| Exercice | Outils exigés | Source |
|----------|---------------|--------|
| 01 — Valeur ou rien | `std::optional<T>`, `std::nullopt`, `.has_value()`/`.value()` | cours ch.4 §`std::optional<T>` ; aussi §`## Outil` de l'énoncé |
| 01 — Valeur ou rien | boucle/comparaison, `std::vector`, `std::size_t` | ch.1 (boucles, types) ; ch.2 (`std::vector`) |
| 02 — Compteur de mots | `std::map<std::string,int>`, `++m[cle]`, structured bindings | cours ch.4 §`std::map` (et §« compter des mots ») ; aussi §`## Outils utiles` de l'énoncé |
| 02 — Compteur de mots | `std::cin >> mot` / `std::getline`, `std::string` | cours ch.4 (exemple « compter des mots ») ; ch.3 (`getline`, flux) ; ch.2 (`std::string`) |
| 03 — Moyenne ou rien | `std::optional<double>`, `std::nullopt` | cours ch.4 §`std::optional<T>` |
| 03 — Moyenne ou rien | `std::accumulate` (init `0.0`), `std::sort` | cours ch.4 §`<algorithm>`/`<numeric>` ; aussi §`## Aide` de l'énoncé |
| 04 — Config parser | `std::map<std::string,std::string>`, `m[cle] = val` | cours ch.4 §`std::map` ; aussi §`## Aide` de l'énoncé |
| 04 — Config parser | `std::string::find`, `std::string::npos`, `substr` | ch.2 (`std::string`) ; rappelé en §`## Aide` de l'énoncé |

Les corrigés sont dans `solutions/`, à consulter **après** avoir réussi.
