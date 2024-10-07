# Demande à l'utilisateur d'entrer deux nombres et un opérateur
num1 = int(input("Entrez le premier nombre : "))
num2 = int(input("Entrez le deuxième nombre : "))
op = input("Entrez l'opérateur (+, -, *, /, %, &, |, ~) : ")

# Vérifie l'opérateur et effectue l'opération correspondante
if op == '+':
    result = num1 + num2
elif op == '-':
    result = num1 - num2
elif op == '*':
    result = num1 * num2
elif op == '/':
    result = num1 / num2
elif op == '%':
    result = num1 % num2
elif op == '&':
    result = num1 & num2
elif op == '|':
    result = num1 | num2
elif op == '~':
    result = ~num1  # Opérateur NOT prend seulement num1
else:
    result = "Opérateur invalide"

# Affiche le résultat
print(f"Le résultat de l'opération est : {result}")

