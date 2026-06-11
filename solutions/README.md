# Corrigés

Ce dossier contient les corrigés des exercices et projets, **isolés** du reste
pour éviter tout spoil involontaire.

## Règle

Un corrigé ne se consulte qu'**après** avoir résolu l'exercice soi-même (tests
au vert) et l'avoir dit explicitement. C'est le cœur de la démarche de cette
formation : le déclic doit venir de toi.

## Organisation

Un sous-dossier par chapitre (`01-fondamentaux/`, etc.), rempli au fur et à
mesure des réussites.

## Build

Les corrigés ne sont compilés que sur demande explicite, via l'option CMake :

```bash
cmake -S . -B build -DBUILD_SOLUTIONS=ON
```
