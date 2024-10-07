import math
# Demande à l'utilisateur d'entrer le rayon du cercle
rayon = float(input("Entre un rayon :"))

print("ton rayon est : " + str(rayon))

# Calcul de l'aire du cercle
aire = math.pi * rayon * rayon

# Calcul du périmètre du cercle
perimetre = 2 * math.pi * rayon

# Affiche le résultat
print("l'aire est :" + str(aire), "et le perimetre est :" + str(perimetre))
