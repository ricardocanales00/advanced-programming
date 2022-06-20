#include <stdio.h>
#include "rot13.h"

// 1. Proporciona los comandos para compilar un ejecutable usando la librería estática.
/*
	Compilar usando $ gcc -o main main.c -L. lrot13
	
*/
int main() {
	char p[] = "Hola Mundo Este String Se Codifica Y Decodifica";

	rot13(p);
	printf("%s\n", p);
	rot13(p);
	printf("%s\n", p);
	
}