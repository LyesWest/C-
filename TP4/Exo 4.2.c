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
