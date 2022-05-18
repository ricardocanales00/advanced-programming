#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

// Crea un programa que cambie las mayusculas por minusculas y las minusculas por mayusculas
// en un archivo. En el programa anterior esta el ejemplo para leer argumentos de la linea de
// comandos. Usa la-luna.txt

// Usa file i/o.

int main(int argc, char *argv[]) {
	int fd, v;
	char buff[1];

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror("file");
		printf("Error, debes proporcionar un archivo\n");
		exit(-1);
	}

	do {
		v = read(fd, buff, 1);
		if (buff[0] >= 65 && buff[0] <= 90) {
			fprintf(stderr, "%c", buff[0] + (97-65));
		} else if (buff[0] >= 97 && buff[0] <= 122) {
			fprintf(stderr, "%c", buff[0] - (97-65));
		} else {
			fprintf(stderr, "%c", buff[0]);
		}
	} while(v > 0);
}