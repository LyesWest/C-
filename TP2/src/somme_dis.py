import dis

# Fonction pour calculer la somme des entiers de 0 à n-1
def calculer_somme(n: int) -> int:
    somme = 0
    # Boucle for pour parcourir tous les entiers de 0 à n-1
    for i in range(n):
        somme += i
    return somme

def main() -> None:
    n = 10
    resultat = calculer_somme(n)
    print(f"La somme des entiers de 0 à {n-1} est {resultat}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_somme)
    main()

# Version modifiée de `calculer_somme` avec une boucle while
def calculer_somme_while(n: int) -> int:
    somme = 0
    i = 0
    # Boucle while pour parcourir les entiers de 0 à n-1
    while i < n:
        somme += i
        i += 1
    return somme

# Analyse du bytecode de la version modifiée
dis.dis(calculer_somme_while)

