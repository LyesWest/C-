#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_OUTPUT_SIZE 1024
#define MAX_VARS 100

// Enum pour les types de données
typedef enum {
    ENTIER,
    REEL,
    CHAINE
} TypeVariable;

// Structure pour représenter une variable
typedef struct {
    char nom[50];
    TypeVariable type;
    union {
        int valeurEntier;
        float valeurReel;
        char valeurChaine[50];
    } valeur;
} Variable;

// Table des symboles
Variable tableSymboles[MAX_VARS];
int nombreVariables = 0;

// Déclarations de fonctions
int find_variable(const char* nom);
double get_variable_value(const char* nom);
void add_variable(const char* nom, TypeVariable type, const void* valeur);
void remplacer_x_par_valeur(char *expression, const char *valeur);
void infix_to_postfix(const char *infix, char *postfix);
double evaluate_postfix(const char *postfix);
void traiter_expression_lambda(char *commande);

// Structure de pile pour les opérateurs
typedef struct {
    char items[MAX_STACK_SIZE];
    int top;
} Stack;

// Structure de pile pour les opérandes
typedef struct {
    double items[MAX_STACK_SIZE];
    int top;
} OperandStack;

// Fonctions de gestion des piles
void init_stack(Stack *s) {
    s->top = -1;
}

void init_operand_stack(OperandStack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_operand_stack_empty(OperandStack *s) {
    return s->top == -1;
}

void push(Stack *s, char item) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->items[++s->top] = item;
    }
}

void push_operand(OperandStack *s, double item) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->items[++s->top] = item;
    }
}

char pop(Stack *s) {
    if (!is_empty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

double pop_operand(OperandStack *s) {
    if (!is_operand_stack_empty(s)) {
        return s->items[s->top--];
    }
    return 0;
}

char peek(Stack *s) {
    if (!is_empty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Fonction pour vérifier si un caractère est un opérateur
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Fonction pour ajouter une variable dans la table des symboles
void add_variable(const char* nom, TypeVariable type, const void* valeur) {
    int index = find_variable(nom);

    if (index == -1 && nombreVariables < MAX_VARS) {
        // Ajout d'une nouvelle variable
        strcpy(tableSymboles[nombreVariables].nom, nom);
        tableSymboles[nombreVariables].type = type;

        if (type == ENTIER) {
            tableSymboles[nombreVariables].valeur.valeurEntier = *((int*)valeur);
            printf("Variable %s définie avec la valeur %d (entier)\n", nom, *((int*)valeur));
        } else if (type == REEL) {
            tableSymboles[nombreVariables].valeur.valeurReel = *((float*)valeur);
            printf("Variable %s définie avec la valeur %.2f (nombre réel)\n", nom, *((float*)valeur));
        }
        nombreVariables++;
    } else if (index != -1) {
        // Vérifier le type pour empêcher le changement de type
        if (tableSymboles[index].type != type) {
            printf("Erreur : changement de type non autorisé pour la variable %s\n", nom);
        } else {
            // Mise à jour de la variable
            if (type == ENTIER) {
                tableSymboles[index].valeur.valeurEntier = *((int*)valeur);
                printf("Variable %s mise à jour avec la valeur %d (entier)\n", nom, *((int*)valeur));
            } else if (type == REEL) {
                tableSymboles[index].valeur.valeurReel = *((float*)valeur);
                printf("Variable %s mise à jour avec la valeur %.2f (nombre réel)\n", nom, *((float*)valeur));
            }
        }
    }
}

// Fonction pour convertir une expression infixée en notation postfixée
void infix_to_postfix(const char *infix, char *postfix) {
    Stack s;
    init_stack(&s);
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        if (isspace(infix[i])) {
            continue;
        }

        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];
            while (isdigit(infix[i + 1]) || infix[i + 1] == '.' || isalpha(infix[i + 1])) {
                postfix[j++] = infix[++i];
            }
            postfix[j++] = ' ';
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!is_empty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            if (!is_empty(&s) && peek(&s) == '(') {
                pop(&s);
            }
        } else if (is_operator(infix[i])) {
            while (!is_empty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            push(&s, infix[i]);
        }
    }

    while (!is_empty(&s)) {
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}

// Fonction pour évaluer une expression postfixée
double evaluate_postfix(const char *postfix) {
    OperandStack s;
    init_operand_stack(&s);
    char token[MAX_OUTPUT_SIZE];
    int i = 0;

    while (sscanf(postfix + i, "%s", token) == 1) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push_operand(&s, atof(token));
        } else if (isalpha(token[0])) {
            push_operand(&s, get_variable_value(token));
        } else if (is_operator(token[0])) {
            double operand2 = pop_operand(&s);
            double operand1 = pop_operand(&s);
            double result;

            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        printf("Erreur : division par zéro\n");
                        return 0;
                    }
                    break;
                default:
                    result = 0;
                    break;
            }
            push_operand(&s, result);
        }
        i += strlen(token) + 1;
    }

    return pop_operand(&s);
}

// Fonction pour gérer les variables et les fonctions supplémentaires

// Fonction pour rechercher une variable dans la table des symboles
int find_variable(const char* nom) {
    for (int i = 0; i < nombreVariables; i++) {
        if (strcmp(tableSymboles[i].nom, nom) == 0) {
            return i;
        }
    }
    return -1;
}

// Fonction pour obtenir la valeur d'une variable (entier ou réel)
double get_variable_value(const char* nom) {
    int index = find_variable(nom);
    if (index == -1) {
        printf("Erreur : la variable %s n'est pas définie\n", nom);
        return 0;
    }

    if (tableSymboles[index].type == ENTIER) {
        return tableSymboles[index].valeur.valeurEntier;
    } else if (tableSymboles[index].type == REEL) {
        return tableSymboles[index].valeur.valeurReel;
    } else {
        printf("Erreur : la variable %s n'est pas un nombre\n", nom);
        return 0;
    }
}

// Fonction pour remplacer toutes les occurrences de "x" dans une expression par une valeur donnée
void remplacer_x_par_valeur(char *expression, const char *valeur) {
    char result[MAX_OUTPUT_SIZE] = "";
    int len = strlen(expression);
    int valeur_len = strlen(valeur);

    for (int i = 0; i < len; i++) {
        // Vérifie si 'x' est un terme indépendant
        if (expression[i] == 'x' &&
            (i == 0 || !isalnum(expression[i - 1])) &&    // Vérifie qu'il n'y a pas de lettre ou chiffre avant
            (i == len - 1 || !isalnum(expression[i + 1]))) // Vérifie qu'il n'y a pas de lettre ou chiffre après
        {
            strcat(result, valeur); // Remplace 'x' par la valeur donnée
        } else {
            strncat(result, &expression[i], 1); // Copie le caractère tel quel
        }
    }

    strcpy(expression, result); // Met à jour l'expression avec le résultat
}

void traiter_expression_lambda(char *commande) {
    // Étape 1 : Vérifier que la commande commence bien par "(lambda "
    if (strncmp(commande, "(lambda ", 8) != 0) {
        printf("Erreur : syntaxe incorrecte pour l'expression lambda\n");
        return;
    }

    // Étape 2 : Trouver la position du point '.' et des parenthèses
    char *dot = strchr(commande, '.');
    char *close_paren = strrchr(commande, ')');
    if (!dot || !close_paren || close_paren <= dot) {
        printf("Erreur : syntaxe incorrecte pour l'expression lambda\n");
        return;
    }

    // Étape 3 : Extraire la variable (celle qui se trouve entre "lambda" et ".")
    char variable[50];
    strncpy(variable, commande + 8, dot - (commande + 8));
    variable[dot - (commande + 8)] = '\0';

    // Supprimer les espaces autour de la variable
    char *var_start = variable;
    while (isspace(*var_start)) var_start++;
    char *var_end = var_start + strlen(var_start) - 1;
    while (var_end > var_start && isspace(*var_end)) {
        *var_end = '\0';
        var_end--;
    }

    // Étape 4 : Extraire l'expression mathématique
    char expression[MAX_OUTPUT_SIZE];
    strncpy(expression, dot + 1, close_paren - (dot + 1));
    expression[close_paren - (dot + 1)] = '\0';

    // Étape 5 : Extraire l'argument après la dernière parenthèse fermante
    char argument[50];
    strcpy(argument, close_paren + 1);
    while (isspace(*argument)) memmove(argument, argument + 1, strlen(argument));  // Supprime les espaces de début

    if (strlen(argument) == 0) {
        printf("Erreur : argument manquant pour l'expression lambda\n");
        return;
    }

    // Étape 6 : Vérifier si l'argument est un nombre ou une variable définie
    double valeurArgument;
    if (isdigit(argument[0]) || (argument[0] == '-' && isdigit(argument[1]))) {
        // Argument est un nombre
        valeurArgument = atof(argument);
    } else {
        // Argument est une variable
        int index = find_variable(argument);
        if (index == -1) {
            printf("Erreur : la variable %s n'est pas définie\n", argument);
            return;
        }
        valeurArgument = get_variable_value(argument);
    }

    // Étape 7 : Remplacer toutes les occurrences de la variable dans l'expression
    char valeurStr[50];
    sprintf(valeurStr, "%.2f", valeurArgument);
    remplacer_x_par_valeur(expression, valeurStr);

    // Étape 8 : Convertir en postfixe et évaluer l'expression
    char postfix[MAX_OUTPUT_SIZE];
    infix_to_postfix(expression, postfix);
    double result = evaluate_postfix(postfix);
    printf("Résultat de l'évaluation : %.2f\n", result);
}


int main() {
    // La boucle principale de l'interpréteur...
    char commande[MAX_OUTPUT_SIZE];

    printf("Bienvenue dans l'interpréteur ! Tapez 'quit' ou 'quitter' pour arrêter.\n");

    while (1) {
        printf("> ");
        fgets(commande, sizeof(commande), stdin);
        commande[strcspn(commande, "\n")] = 0; // Supprime le saut de ligne

        // Détecter la commande "quit" ou "quitter" pour sortir de la boucle
        if (strcmp(commande, "quit") == 0 || strcmp(commande, "quitter") == 0) {
            printf("Arrêt...\n");
            break;
        }

        // Vérifier si la commande est une expression lambda
        if (strncmp(commande, "(lambda", 7) == 0) {
            traiter_expression_lambda(commande);
        } else {
            // Traitement des affectations ou des accès aux variables classiques
            char nomVar[50];
            char valeurVar[50];

            if (sscanf(commande, "%s = %s", nomVar, valeurVar) == 2) {
                // Gestion des affectations de variables
                if (isdigit(valeurVar[0]) || (valeurVar[0] == '-' && isdigit(valeurVar[1]))) {
                    // Entier ou réel
                    if (strchr(valeurVar, '.')) {
                        float fValue = atof(valeurVar);
                        add_variable(nomVar, REEL, &fValue);
                    } else {
                        int iValue = atoi(valeurVar);
                        add_variable(nomVar, ENTIER, &iValue);
                    }
                } else if (valeurVar[0] == '"' && valeurVar[strlen(valeurVar) - 1] == '"') {
                    // Chaîne de caractères
                    valeurVar[strlen(valeurVar) - 1] = '\0';  // Retire la dernière guillemet
                    add_variable(nomVar, CHAINE, valeurVar + 1);
                } else {
                    printf("Erreur : type de valeur non supporté.\n");
                }
            } else if (sscanf(commande, "%s", nomVar) == 1) {
                // Accéder à la valeur de la variable
                get_variable_value(nomVar);
            } else {
                printf("Commande non reconnue.\n");
            }
        }
    }

    return 0;
}
