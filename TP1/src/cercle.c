#include <stdio.h>
int main(){

	int rayon;
	printf("rayon:");
	scanf("%d",&rayon);
	printf("la valeur du rayon est : %d\n",rayon);
	float pi = 3.14;
	int aire = pi * rayon * rayon;
	int perimetre = 2 * pi * rayon;
	printf("la valeur de l'aire est : %d\n",aire);
	printf("et le périmètre est: %d\n",perimetre);
}
