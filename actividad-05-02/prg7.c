// Escribe un programa que cuente la cantidad de lineas en un archivo. Usa la-luna.txt

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *input;
	int v, c=0;
	char buff[1];
	input = fopen(argv[1], "r");
	if (input == NULL) {
		perror("file");
		printf("Error, debes proporcionar un archivo\n");
		exit(-1);
	}
	for(;;) {
		v = fread(buff, 1, 1, input);
		if (v <= 0) break;

		if (buff[0] == '\n') {
			c++;
		}
	} 
	printf("Hay %d lineas\n", c);
}