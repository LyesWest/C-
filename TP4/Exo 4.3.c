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
    char infix[MAX_OUTPUT_SIZE];
    char postfix[MAX_OUTPUT_SIZE];

    printf("Entrez une expression en notation infixée : ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0; // Supprime le saut de ligne

    infix_to_postfix(infix, postfix);
    printf("Expression en notation postfixée : %s\n", postfix);

    double result = evaluate_postfix(postfix);
    printf("Résultat de l'évaluation : %.2f\n", result);

    return 0;
}
