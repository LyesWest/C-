#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_OUTPUT_SIZE 1024

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

// Initialiser la pile
void init_stack(Stack *s) {
    s->top = -1;
}

void init_operand_stack(OperandStack *s) {
    s->top = -1;
}

// Vérifier si la pile est vide
int is_empty(Stack *s) {
    return s->top == -1;
}

int is_operand_stack_empty(OperandStack *s) {
    return s->top == -1;
}

// Empiler un élément
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

// Dépiler un élément
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

// Obtenir l'élément au sommet de la pile
char peek(Stack *s) {
    if (!is_empty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

// Définir la priorité des opérateurs
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

// Fonction pour convertir une expression infixée en notation postfixée
void infix_to_postfix(const char *infix, char *postfix) {
    Stack s;
    init_stack(&s);
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        if (isspace(infix[i])) {
            continue;
        }

        if (isdigit(infix[i])) {
            // Ajouter l'opérande directement à la sortie
            postfix[j++] = infix[i];
            while (isdigit(infix[i + 1]) || infix[i + 1] == '.') {
                postfix[j++] = infix[++i];
            }
            postfix[j++] = ' ';
        } else if (infix[i] == '(') {
            // Empiler les parenthèses ouvrantes
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            // Dépiler jusqu'à la parenthèse ouvrante
            while (!is_empty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            if (!is_empty(&s) && peek(&s) == '(') {
                pop(&s); // Supprimer la parenthèse ouvrante
            }
        } else if (is_operator(infix[i])) {
            // Traiter les opérateurs
            while (!is_empty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            push(&s, infix[i]);
        }
    }

    // Ajouter les opérateurs restants dans la pile à la sortie
    while (!is_empty(&s)) {
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0'; // Terminer la chaîne
}

// Fonction pour évaluer une expression postfixée
double evaluate_postfix(const char *postfix) {
    OperandStack s;
    init_operand_stack(&s);
    char token[MAX_OUTPUT_SIZE];
    int i = 0;

    while (sscanf(postfix + i, "%s", token) == 1) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Si le token est un nombre, le pousser sur la pile des opérandes
            push_operand(&s, atof(token));
        } else if (is_operator(token[0])) {
            // Si le token est un opérateur, dépiler deux opérandes et évaluer
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

    // Le résultat final est sur la pile
    return pop_operand(&s);
}

int main() {
    char commande[MAX_OUTPUT_SIZE];
    char infix[MAX_OUTPUT_SIZE];
    char postfix[MAX_OUTPUT_SIZE];

    while (1) {
        printf("> ");
        fgets(commande, sizeof(commande), stdin);
        commande[strcspn(commande, "\n")] = 0; // Supprime le saut de ligne

        // Détecter la commande "quit"
        if (strcmp(commande, "quit") == 0 || strcmp(commande, "quitter") == 0) {
            printf("Arrêt...\n");
            break;
        }
        
        // Si la commande est une expression arithmétique
        strcpy(infix, commande);
        infix_to_postfix(infix, postfix);
        printf("Expression en notation postfixée : %s\n", postfix);

        double result = evaluate_postfix(postfix);
        printf("Résultat de l'évaluation : %.2f\n", result);
    }

    return 0;
}
