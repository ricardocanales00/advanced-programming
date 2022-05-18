#include <stdio.h>
#include <string.h>
// Archivo binario con registros

// Lee el archivo estados.txt y llena un arreglo de apuntadores a las siguientes estructuras.

// Calcula la poblacion total del pais (los datos vienen de statista y estan en miles, por
// eso el punto decimal).

// Guarda en un archivo estados.bin la informacion en forrmato bianrio (no ASCII).


struct estado {
	char nombre[32];
	float poblacion;
};

int main() {
	FILE *fin, *fout;
	char line[64], *token;
	char nombre[64];
	float f;

	struct estado estados[31];
	int i=0;

	fin = fopen("estados.txt", "r");
	for(;;) {
		if (feof(fin)) break;
		fgets(line, 64, fin);

		token = strtok(line, "|");
		//printf("%s \n", token);
		//estados[i].nombre = token;  ERROR
		strncpy(estados[i].nombre, token, 32);

		token = strtok(NULL, "|");
		sscanf(token, "%f", &f);
		//printf("%f \n", f);
		estados[i].poblacion = f;
		i++;
	}

	for (i=0; i<31; i++) {
		printf("Nombre: %s, poblacion: %.2f\n", estados[i].nombre, estados[i].poblacion);
	}

	fout = fopen("estadosb.bin", "w+");
	fwrite(estados, sizeof(struct estado), 31, fout);

}