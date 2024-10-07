import sys

def display_size(value_type, value_name):
    print(f"Taille de {value_name} ({value_type.__name__}): {sys.getsizeof(value_type())} octets")

def main():
    # Char
    display_size(int, 'char (simulé avec un entier)')
    display_size(bytes, 'unsigned char (simulé avec bytes de taille 1)')

    # Short (Python n'a pas de type 'short', donc on utilise int pour simuler)
    display_size(int, 'signed short')
    display_size(int, 'unsigned short')

    # Int
    display_size(int, 'signed int')
    display_size(int, 'unsigned int (simulé avec int en Python)')

    # Long int
    display_size(int, 'signed long int')
    display_size(int, 'unsigned long int (simulé avec int en Python)')

if __name__ == "__main__":
    main()
