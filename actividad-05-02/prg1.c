#include <stdio.h>  // printf, BUFSIZ
#include <stdlib.h> // exit
#include <unistd.h> // fork
#include <fcntl.h>  // open, read, write
#include <sys/wait.h> // wait

// Crea un programa que:
// 1. Abra un archivo
// 2. Cree un proceso hijo y deje al padre esperando
// 3. El hijo debe leer de la consola un mensaje mediante fgets
// 4. El hijo debe escribir ese mensaje al archivo mensaje.txt y terminar
// 5. El padre debe despertar, leer el mensaje desde el archivo e imprimirlo en la consola

// Programarlo usando file i/o

// Segmento de datos, para que no se guarden datos del stack en el archivo
char buffer[BUFSIZ];

int main() {
	// char buffer[BUFSIZ];
	int fd, n;

	fd = open("mensaje.txt", O_RDWR | O_TRUNC | O_CREAT, 0644);
        // user  gr    other
	// r w - r - - r - -
        // 4 2 1 4 2 1 4 2 1
        // 1 1 0 1 0 0 1 0 0

	if(fork() == 0) {
		// stdin, stdout, stderr
		fprintf(stderr, "Escribe el mensaje: ");
		fgets(buffer, BUFSIZ, stdin);
		write(fd, buffer, BUFSIZ);

		exit(0);
		
	}

	wait(0);
	fd = open("mensaje.txt", O_RDONLY);
	n = read(fd, buffer, BUFSIZ);
	printf("El mensaje fue [%s] %d\n", buffer, n);
}
