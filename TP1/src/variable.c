#include <stdio.h>

int main() {
    // Déclaration de variables avec leur valeurs
    char c = 'z';
    signed char sc = -115;
    unsigned char uc = 200;
    short s = -32760;
    unsigned short us = 65530;
    int i = -2147483640;
    unsigned int ui = 4294967290;
    long int li = -9223372036854775800;
    unsigned long int uli = 18446744073709551610U;
    long long int lli = -9223372036854775800LL;
    unsigned long long int ulli = 18446744073709551610ULL;
    float f = 3.14159f;
    double d = 3.141592653589793;
    long double ld = 3.14159265358979323846L;

    // Affichage des valeurs des variables
    printf("char: %c\n", c);
    printf("signed char: %d\n", sc);
    printf("unsigned char: %u\n", uc);
    printf("short: %d\n", s);
    printf("unsigned short: %u\n", us);
    printf("int: %d\n", i);
    printf("unsigned int: %u\n", ui);
    printf("long int: %ld\n", li);
    printf("unsigned long int: %lu\n", uli);
    printf("long long int: %lld\n", lli);
    printf("unsigned long long int: %llu\n", ulli);
    printf("float: %f\n", f);
    printf("double: %lf\n", d);
    printf("long double: %Lf\n", ld);

}
