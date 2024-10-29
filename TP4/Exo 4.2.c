#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_OUTPUT_SIZE 1024

// Structure de pile pour les opérateurs
typedef struct {
    char items[MAX_STACK_SIZE];
    int top;
} Stack;

// Initialiser la pile
void init_stack(Stack *s) {
    s->top = -1;
}

// Vérifier si la pile est vide
int is_empty(Stack *s) {
    return s->top == -1;
}

// Empiler un élément
void push(Stack *s, char item) {
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

int main() {
    char infix[MAX_OUTPUT_SIZE];
    char postfix[MAX_OUTPUT_SIZE];

    printf("Entrez une expression en notation infixée : ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0; // Supprime le saut de ligne

    infix_to_postfix(infix, postfix);
    printf("Expression en notation postfixée : %s\n", postfix);

    return 0;
}
