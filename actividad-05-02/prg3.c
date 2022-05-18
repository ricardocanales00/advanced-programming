#include <stdio.h>

// Crear un programa que lea los numeros en numeros.txt, los pares los escriba a un archivo 
// pares.txt, los numeros impares a impares.txt y los numeros primos a primos.txt

// Usar standard i/o 

int primo(int n) {
	int i;

	for (i=2; i<n; i++) {
		if (n%i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	FILE *numeros, *pares, *impares, *primos;
	int n;

	numeros = fopen("numeros.txt", "r");
	pares = fopen("pares.txt", "w");
	impares = fopen("impares.txt", "w");
	primos = fopen("primos.txt", "w");

	while(1) {
		if (feof(numeros)) break;
		fscanf(numeros, "%d", &n);
		if ( n%2 == 0 ) {
			// pares
			fprintf(pares, "%d\n", n);
		} else {
			fprintf(impares, "%d\n", n);
		}
		if (primo(n)) {
			fprintf(primos, "%d\n", n);
		}
	}
}
