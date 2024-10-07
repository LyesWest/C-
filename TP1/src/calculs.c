#include <stdio.h>

int main() {
    int num1;
    int num2;
    int NEWnum1;
    int NEWnum2;
    float NEWdivision;
    char op[2]; // Tableau pour stocker l'opérateur (+, -, *, /, %)

    // Demande à l'utilisateur d'entrer un opérateur pour le calcul
    printf("Entrez l'opérateur souhaité pour le calcul : ");
    scanf("%s", op);

    // Demande à l'utilisateur d'entrer deux nombres
    printf("Entrez le premier nombre et le deuxieme nombre : ");
    scanf("%d %d", &num1, &num2);

    // Utilise switch pour choisir l'opération à effectuer
    switch (op[0]) {
        case '+':
            // Addition
            int add = num1 + num2;
            printf("L'addition des nombres est égale à : %d\n", add);
            break;

        case '-':
            // Soustraction
            int soustraction = num1 - num2;
            printf("La soustraction des nombres est égale à : %d\n", soustraction);
            break;

        case '*':
            // Multiplication
            int multiplication = num1 * num2;
            printf("La multiplication des nombres est égale à : %d\n", multiplication);
            break;

        case '%':
            // Modulo
            int modulo = num1 % num2;
            printf("Le modulo des nombres est égal à : %d\n", modulo);
            break;

        case '/':
            // Vérifie que la division par zéro n'est pas tentée
            if (num1 == 0 || num2 == 0) {
                printf("Voyons, on ne peut pas diviser par 0 \n");
                printf("Entrez de nouvelles valeurs pour effectuer le calcul : ");
                // Redemande de nouvelles valeurs si l'une des valeurs est zéro
                scanf("%d %d", &NEWnum1, &NEWnum2);
                float NEWdivision = (float)NEWnum1 / NEWnum2; // Division avec les nouvelles valeurs
                printf("La division des nombres est égale à : %f\n", NEWdivision);
            }
            else {
                // Division classique si num1 et num2 sont non nuls
                float division = (float)num1 / num2;
                printf("La division des nombres est égale à : %f\n", division);
            }
            break;

        default:
            // Message par défaut si l'opérateur n'est pas reconnu
            printf("Opérateur non valide.\n");
            break;
    }
}

