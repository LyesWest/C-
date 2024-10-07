import math
import dis

# Fonction pour calculer l'aire d'un cercle
def calculer_aire(rayon: float) -> float:
    return math.pi * rayon * rayon

# Fonction principale pour tester la fonction calculer_aire
def main() -> None:
    rayon: float = 5.0
    aire: float = calculer_aire(rayon)
    print(f"L'aire du cercle de rayon {rayon:.2f} est {aire:.2f}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_aire)
    main()

"""

   - **LOAD_GLOBAL** : Charge une variable globale (comme `math.pi`).
   - **LOAD_FAST** : Charge une variable locale (ici `rayon`).
   - **BINARY_MULTIPLY** : Effectue une multiplication entre les deux valeurs en haut de la pile.
   - **RETURN_VALUE** : Retourne la valeur résultante.

   
"""
