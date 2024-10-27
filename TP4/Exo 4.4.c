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
