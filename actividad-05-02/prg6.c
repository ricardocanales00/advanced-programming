// Crea un programa que cambie las mayusculas por minusculas y las minusculas por mayusculas
// en un archivo. Usa la-luna.txt.

// Usa standard i/o.
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *input;
	int v;
	char buff[1];

	input = fopen(argv[1], "r");
	if (input == NULL) {
		perror("file");
		printf("Error, debes proporcionar un archivo\n");
		exit(-1);
	}
	do {
		v = fread(buff, 1, 1, input);

		if (buff[0] >= 65 && buff[0] <= 90) {
			fprintf(stderr, "%c", buff[0] + (97-65));
		} else if (buff[0] >= 97 && buff[0] <= 122) {
			fprintf(stderr, "%c", buff[0] - (97-65));
		} else {
			fprintf(stderr, "%c", buff[0]);
		}
	} while(v > 0);
}