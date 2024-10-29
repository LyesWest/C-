# Bibliothèques

### stdio.h  
Fournit les fonctions d'entrée/sortie standard telles que `printf` et `scanf`.

### string.h  
Contient des fonctions pour manipuler les chaînes de caractères, comme `strcpy()`, `strstr()`, `strlen()`, etc.

### time.h  
Permet de travailler avec la date et l'heure, par exemple avec `time()`, `localtime()`, etc., pour afficher la date et l'heure actuelles.

### ctype.h  
Fournit des fonctions pour tester et manipuler les caractères, comme `tolower()` pour convertir une lettre en minuscule.

# Fonctionnalités principales

- **Interpréteur de commandes simple** : Le programme simule un interpréteur de commandes, qui peut traiter différentes commandes saisies par l'utilisateur.
- **Commandes disponibles** :
  - `quit` / `quitter` : Quitte le programme.
  - `echo <texte>` : Répète le texte fourni par l'utilisateur.
  - `date` : Affiche la date et l'heure actuelles.
  - `version` : Affiche la version de l'interpréteur de commandes.
  - `help` / `aide` : Affiche une liste des commandes disponibles.
- **Boucle principale** : Le programme attend des commandes de l'utilisateur jusqu'à ce que la commande `quit` ou `quitter` soit saisie.

# Références

- Groupe de travail de Cedric Darmaisin et Adel Ayadi  
- [Wikipedia](http://www.wikipedia.org)  
- [OpenClassroom](https://openclassroom.com)  
- ChatGPT.com

# Difficulté
- Utilisation de boucles en C pour gérer les entrées utilisateurs.
- Gestion des structures `struct` pour associer les commandes à leurs fonctions correspondantes.

