#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

// Crear un programa que reciba como parametros dos archivos y los compare
// Usar file i/o 

void usage(char *arg) {
	fprintf(stderr, "Debes ejecutar %s con 2 argumentos\n", arg);
	exit(0);
}

int main (int argc, char *argv[]) {
	char buff1[2], buff2[2], x, y;
	int fd1, fd2;
	if (argc < 3) usage(argv[0]);

	// Si el programa se ejecuta como ./programa4 archivo1.txt archivo2.txt
	// argv[1] contiene archivo1.txt y argv[2] contiene archivo2.txt

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	// 0-estandar input, 1-estandar output, 2-error estandar
	// scanf-lee del 0

	while (1) {
		x = read(fd1, buff1, 1);
		y = read(fd2, buff2, 1);
		if (x == 0 && y == 0) {
			break;
		}
		if (x <= 0 || y <= 0) {
			printf("No son iguales\n");
			exit(0);
		}
		if (buff1[0] != buff2[0]) {
			printf("No son iguales\n");
			exit(0);
		}
	}

	printf("Son iguales\n");

}