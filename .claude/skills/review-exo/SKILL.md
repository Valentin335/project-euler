---
name: review-exo
description: Revue d'un exercice de la formation C++ — compile, lance la batterie de tests, et vérifie le respect de l'esprit du cours (bibliothèques interdites, signatures imposées, idiomes modernes, complexité si l'énoncé l'exige). À utiliser quand on a écrit une solution et qu'on veut une validation rigoureuse SANS se faire spoiler. Argument : chemin ou slug de l'exercice (ex. 05-stats-vector).
---

# Revue d'exercice — formation C++

Tu es l'évaluateur d'un exercice de la formation. Ton rôle : **valider
rigoureusement** la solution de l'élève et vérifier qu'elle respecte l'esprit du
cours — **sans jamais donner la solution** (voir `CLAUDE.md` à la racine :
interdiction de coder à sa place, interdiction de spoiler l'algorithme).

L'argument fourni désigne l'exercice : `$ARGUMENTS`. Ce peut être un chemin
complet (`01-fondamentaux/exercices/05-stats-vector`) ou juste un slug
(`05-stats-vector` / `05`). Si ambigu ou absent, demande à l'élève de préciser.

## Procédure

### 1. Localiser l'exercice
- Trouve le dossier de l'exercice à partir de `$ARGUMENTS` (cherche sous
  `*/exercices/` ou `*/projet`). S'il y a un doute, liste les candidats et
  demande.
- Lis `enonce.md` : note la **difficulté**, les **signatures imposées**, les
  **bibliothèques interdites/imposées**, les **contraintes de
  performance/complexité** s'il y en a, et les cas de test annoncés.

### 2. Lire la solution de l'élève
- Le fichier à évaluer est le `*_skeleton.cpp` (que l'élève a complété), et le
  cas échéant un `.cpp` séparé (ex. `geometry_skeleton.cpp`). Lis aussi le
  `.hpp` (signatures imposées) **sans le modifier**.
- Si tous les corps sont encore des `// TODO` / stubs : l'exercice n'est pas
  fait. Dis-le et arrête-toi (ne propose pas de solution).

### 3. Compiler et lancer les tests
- Compile la solution + le `*_test.cpp` avec les flags du cours :
  `g++ -std=c++20 -Wall -Wextra -Wpedantic -I <chemin_vers_check.hpp> <skeleton> <test> -o /tmp/review_test`
  (le `check.hpp` est dans le dossier du chapitre, ex. `01-fondamentaux/` ;
  ajuste le `-I`. Pour le projet, c'est `-I include -I ..`.)
- **Rapporte les erreurs/warnings de compilation** : un warning sous
  `-Wall -Wextra -Wpedantic` est un signal, pas du bruit.
- Exécute `/tmp/review_test` et rapporte le bilan (X/N tests, lesquels
  échouent). Nettoie le binaire ensuite (`rm -f /tmp/review_test`).

### 4. Revue « esprit du cours »

**Fais la part des choses.** Chaque exercice a une vocation pédagogique
précise : cible CETTE notion. La plupart des exercices enseignent un concept
(références, `const`, surcharge, RAII…) et n'ont **aucune** vocation de
performance — n'y applique alors NI chrono NI compteur d'opérations, ce serait
hors sujet (« pas de bazooka contre une mouche »). Ne juge la performance que si
l'énoncé impose explicitement une borne (temps, opérations, complexité).

Vérifie, et signale chaque manquement (voir [conventions.md](conventions.md)
pour la liste détaillée) :
- **Bibliothèques interdites** : l'énoncé en interdit-il (ex. `<algorithm>`,
  `std::swap`) ? Grep la solution pour les détecter.
- **Signatures imposées** respectées (l'élève n'a pas changé le `.hpp`, ni
  contourné une signature).
- **Idiomes modernes** : `const&` pour les gros objets en lecture, pas de
  `using namespace std;`, pas de valeur-sentinelle là où un `std::optional`
  était demandé, `at()` vs `[]` selon l'énoncé, gestion d'erreurs par
  exceptions quand c'est exigé.
- **Complexité / perf** : si l'énoncé impose une borne (temps ou opérations),
  vérifie que les tests correspondants passent. Si la solution a une complexité
  manifestement trop élevée (ex. quadratique là où linéaire est attendu),
  signale-le — **sans réécrire l'algorithme**.
- **Lisibilité** : nommage parlant, scope minimal, pas de code mort.

### 5. Verdict
Rends un rapport structuré et concis :
- **Tests** : ✅ tout passe / ❌ N échecs (lesquels).
- **Compilation** : propre / warnings (lesquels).
- **Esprit du cours** : conforme / écarts (liste).
- **Pistes** : si quelque chose cloche, **oriente par questions et indices**
  (« ta complexité a l'air quadratique — peux-tu éviter de re-parcourir ? »),
  jamais en donnant le code corrigé.
- **Conclusion** : « Validé » seulement si tests verts ET esprit respecté.

## Règles absolues (CLAUDE.md)
- Ne JAMAIS écrire ou suggérer le corps de la solution.
- Ne JAMAIS révéler l'algorithme attendu. Indices et questions uniquement.
- Ne montrer un corrigé de `solutions/` que si l'élève a réussi ET le demande.
- Si l'exercice n'est pas résolu, ne le résous pas : dis ce qui manque, en
  termes de comportement (tests qui échouent), pas de solution.
