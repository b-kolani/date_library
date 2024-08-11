# Date Library

## Description

La bibliothèque Date permet de créer et de manipuler des dates. Elle fournit des fonctions pour créer des dates, vérifier les années bissextiles, calculer le nombre de jours entre deux dates, et ajouter ou soustraire des jours à une date.

## Fichiers

- `include/date.h` : Fichier d'en-tête contenant les déclarations des fonctions.
- `src/date.c` : Fichier source contenant les implémentations des fonctions.
- `tests/main.c` : Fichier source de test pour vérifier le bon fonctionnement de la bibliothèque.
- `Makefile` : Fichier de configuration pour la compilation.

## Compilation

Pour compiler la bibliothèque et les tests, exécutez :
- `make`

## Nettoyage
- `make clean`

## Utilisation dans un autre projet
Si vous souhaitez utiliser cette bibliothèque dans un autre projet, suivez ces étapes :

1. Inclure le fichier d'en-tête :
Copiez le fichier include/date.h dans le dossier include/ de votre projet (ou à un endroit accessible par votre compilateur).

2. Ajouter la bibliothèque :
Copiez le fichier lib/libdate.a dans le dossier lib/ de votre projet (ou à un endroit accessible par votre compilateur).

3. Inclure et lier la bibliothèque dans votre projet :
Dans votre code source, incluez le fichier d'en-tête :
`#include "date.h"`

4. Lors de la compilation de votre projet, ajoutez les options pour inclure les dossiers include/ et lib/, et liez la bibliothèque :
`gcc -o my_program src/main.c -Iinclude -Llib -ldate`
-Iinclude : Spécifie le chemin vers le dossier contenant le fichier d'en-tête.
-Llib : Spécifie le chemin vers le dossier contenant la bibliothèque.
-ldate : Lien avec la bibliothèque libdate.a ou libdate.so.

## Exemple de projet
Voici un exemple de structure de projet utilisant la bibliothèque Date :

other_project/
├── include/
│   └── date.h       # Votre fichier d'en-tête
├── lib/
│   └── libdate.a    # Votre bibliothèque statique (ou libdate.so pour une dynamique)
└── src/
    └── main.c       # Son code source utilisant votre bibliothèque
