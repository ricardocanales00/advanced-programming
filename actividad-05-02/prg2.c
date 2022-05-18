#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// Crea un programa que:
// 1. Abra un archivo
// 2. Cree un proceso hijo y deje al padre esperando
// 3. El hijo debe leer de la consola un mensaje mediante fgets
// 4. El hijo debe escribir ese mensaje al archivo mensaje.txt y terminar
// 5. El padre debe despertar, leer el mensaje desde el archivo e imprimirlo en la consola

// Programarlo usando standard i/o

int main() {
	char buffer[BUFSIZ];
	FILE *f;
	int n;

	f = fopen("mensaje.txt", "w+");

	if(!fork()) {
		fprintf(stderr, "Dame el mensaje: ");
		fgets(buffer, BUFSIZ, stdin);

		fprintf(f, "%s", buffer);
		// n = fwrite(buffer, 1, BUFSIZ, f);
		fclose(f);
		exit(0);
	}

	wait(0);
	f = fopen("mensaje.txt", "rw");
	n = fread(buffer, 1, BUFSIZ, f);

	printf("El mensaje era: [%s], %d bytes leidos", buffer, n);
	
}