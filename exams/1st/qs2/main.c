#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    int bytes;
    int words;
    int lines;
} data_count;

// 1. Escribir la función count_data que recibe un string (el contenido de un archivo) y 
// llena la estructura d con la cantidad de bytes, palabras y líneas
void count_data(char *p, data_count *d) {
    int l, w, b;

    l = w = b = 0;

    while(1) {
        // Así va recorriendo el string caracter por caracter, hasta el 0 final
        if(*p == 0) break;

        // Implementar algoritmo aquí.
        if(*p != ' ' && (*p != '\0' || *p != '\n')){
            b++;
        }
        if(*p == '\t' || *p == '\n' || *p == '\0'){
            l++;
        }
        if(*p == ' '|| *p == '\t' || *p == '\n' || *p == '\0'){
            w++;
        }
        p++;
    };

    d->bytes = b;
    d->words = w;
    d->lines = l;    
}

int main(int argc, char *argv[]) {
    struct stat buf;
    char *string;
    int file_descriptor;
    data_count result;

    if (argc < 2) {
        fprintf(stderr, "Sintaxis: %s <filename>\n", argv[0]);
        return -1;
    }

    // Abrir el archivo y leer el contenido
    file_descriptor = open(argv[1], O_RDONLY); 
    if (file_descriptor < 0) return -1;
    fstat(file_descriptor, &buf);
    string = malloc(buf.st_size+1);
    read(file_descriptor, string, buf.st_size);
    string[buf.st_size] = 0;

    // En string va todo el archivo, quiero el resultado en result
    count_data(string, &result);

    printf("lineas=%d, palabras=%d, caracteres=%d\n",
        result.lines,
        result.words,
        result.bytes);

    return 0;
}