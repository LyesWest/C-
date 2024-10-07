# Parcourt les nombres de 0 à 999
for i in range(1000):
    # Vérifie si le nombre est divisible par 4 mais pas par 6
    if (i % 4 == 0 and i % 6 != 0):
        print("Les nombres divisibles par 4 mais pas par 6 entre 1 et 1000 sont :", i)

for i in range(1000):
    # Vérifie si le nombre est pair (divisible par 2) et pas divisible par 8
    if (i % 2 == 0 and i % 8 != 0):
        print("Les nombres pairs mais pas divisibles par 8 entre 1 et 1000 sont :", i)

for i in range(1000):
    # Vérifie si le nombre est divisible par 5 et 7 mais pas par 10
    if (i % 5 == 0 and i % 7 == 0 and i % 10 != 0):
        print("Les nombres divisibles par 5 et 7 mais pas par 10 entre 1 et 1000 sont :", i)
