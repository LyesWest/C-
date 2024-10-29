# Bibliothèques

### stdio.h  
Fournit les fonctions d'entrée/sortie standard telles que `printf` et `scanf`.

### ctype.h  
Contient des fonctions pour manipuler les caractères, comme `isdigit()` pour tester si un caractère est un chiffre.

### string.h  
Contient des fonctions pour manipuler les chaînes de caractères, comme `strcpy()`, `strstr()`, `strlen()`, etc.

### stdlib.h  
Utilisé pour la conversion de chaînes en nombre avec `atof()`, ainsi que pour la gestion de la mémoire dynamique.

# Fonctionnalités principales

- **Conversion Infixe vers Postfixe** : Le programme convertit une expression arithmétique en notation infixée (par exemple, "3 + 4 * 5") vers une notation postfixée (par exemple, "3 4 5 * +").
- **Évaluation des Expressions Postfixées** : Le programme évalue l'expression arithmétique en notation postfixée en utilisant une pile pour gérer les opérandes et les opérateurs.
- **Gestion des Parenthèses** : Le programme gère les expressions avec parenthèses pour évaluer correctement les priorités des opérations.
- **Interpréteur de Commandes** : Permet de saisir des expressions arithmétiques directement dans l'interpréteur et de recevoir une réponse.
- **Commandes disponibles** :
  - `quit` / `quitter` : Quitte le programme.

# Structures de données

- **Stack (Pile d'opérateurs)** : Utilisée pour empiler les opérateurs pendant la conversion infixée vers postfixée.
- **OperandStack (Pile d'opérandes)** : Utilisée pour empiler les opérandes pendant l'évaluation des expressions postfixées.

# Références

- Groupe de travail de Cedric Darmaisin et Adel Ayadi  
- [Wikipedia](http://www.wikipedia.org)  
- [OpenClassroom](https://openclassroom.com)  
- ChatGPT.com

# Difficulté
- Utilisation des piles pour gérer les opérandes et les opérateurs.
- Conversion entre les notations infixée et postfixée.
- Gestion des priorités des opérations et des parenthèses.
