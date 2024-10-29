Interpréteur en C - Gestion des Variables et des Expressions Lambda

Ce projet implémente un interpréteur en C capable de :

    Gérer des variables de types entier, réel et chaîne de caractères.
    Évaluer des expressions lambda contenant des opérations mathématiques simples.

Objectifs

    Première Partie : Gérer l'affectation et l'affichage des variables avec des restrictions sur les types.
    Deuxième Partie : Étendre l'interpréteur pour prendre en charge les expressions lambda de la forme (lambda x. expression mathématique) argument.

Fonctionnalités
Partie 1 - Gestion des Variables

    Types pris en charge : entier, réel, chaîne de caractères.
    Affectation de valeurs : permet l'affectation de valeurs à des variables avec des types spécifiques.
    Accès aux variables : permet l'affichage de la valeur d'une variable.
    Gestion des erreurs :
        Changement de type non autorisé après l'affectation initiale.
        Erreur si une variable non définie est consultée.

Partie 2 - Expressions Lambda

    Syntaxe des expressions lambda : (lambda x. expression) argument
        x : la variable à remplacer dans l'expression.
        expression : une expression mathématique qui peut inclure +, -, *, / et des parenthèses.
        argument : un nombre ou une variable définie dans l'interpréteur, qui remplace x lors de l'évaluation.
    Gestion des erreurs :
        Si x est remplacé par une variable non définie, une erreur est affichée.
        Erreur de syntaxe si la structure de l'expression lambda est incorrecte.

Compilation et Exécution

    Compiler le programme :

    bash

gcc -o interpreteur interpreteur.c

Lancer l'interpréteur :

bash

    ./interpreteur

    Le programme affiche un prompt > pour entrer des commandes.

    Quitter l'interpréteur :
        Pour quitter, tapez quit ou quitter et appuyez sur Entrée.

Exemples de Commandes
Partie 1 : Gestion des Variables

    Affectation d'une variable :

    text

> x = 4
Variable x définie avec la valeur 4 (entier)

Accès à une variable :

text

> x
Valeur de x : 4 (entier)

Changement de type (interdit) :

text

> x = 3.14
Erreur : changement de type non autorisé pour la variable x

Affectation d'une chaîne de caractères :

text

> z = "Bonjour"
Variable z définie avec la valeur "Bonjour" (chaîne de caractères)

Accès à une variable non définie :

text

    > y
    Erreur : la variable y n'est pas définie

Partie 2 : Expressions Lambda

    Exemple avec une valeur numérique :

    text

> (lambda x.x + 2 * x) 3
Résultat de l'évaluation : 9.00

Exemple avec une variable définie :

text

> y = 4
Variable y définie avec la valeur 4 (entier)

> (lambda x.(x + 2) * x) y
Résultat de l'évaluation : 24.00

Exemple avec une variable non définie :

text

    > (lambda x.x + 1) z
    Erreur : la variable z n'est pas définie

Structure du Code

    Déclarations de Types et Constantes : Définitions pour les types de données (ENTIER, REEL, CHAINE) et autres constantes (MAX_VARS, MAX_OUTPUT_SIZE).
    Fonctions de Gestion des Variables : Fonctions pour ajouter, mettre à jour, et récupérer des variables dans une table des symboles.
    Fonctions d'Évaluation des Expressions : Convertit les expressions infixées en postfixées et les évalue.
    Fonctions de Gestion des Expressions Lambda : Analyse la syntaxe des expressions lambda et effectue la substitution et l'évaluation.
    Fonction Principale main : Boucle principale qui lit les commandes, identifie les types de commandes, et appelle les fonctions appropriées.

Remarques

    Ce programme est un interpréteur simple et ne gère pas les expressions complexes ou les types avancés.
    Les expressions lambda sont limitées aux expressions mathématiques simples et ne supportent pas les fonctions imbriquées ou avancées.
    Le code peut être étendu pour ajouter de nouvelles fonctionnalités, telles que la gestion des erreurs syntaxiques avancées ou l'ajout de nouveaux types d'opérateurs.
