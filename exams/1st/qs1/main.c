#include <stdio.h>
#define I2S(x) ((short *) x)

int main() {
    int i, x[10];

    for(i=0; i<10; i++) {
        x[i] = i;
    }

    // ¿Por qué se imprimen alternados con 0 los numeros asignados en el for anterior?
    /*  Respuesta:
        Está casteando el valor del entero que se tiene en x[i] a un short int. Considerando que un
        int tiene 32 bytes y un short 16 bytes, se podría interpretar como que lo que está truncando y asigniando
        el resto del valor al siguiente.

        Espacio equivalente a 0 -> Imprime bits de 0 (0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0)                  -> Imprime 0
        Espacio equivalente a 1 -> Imprime los primeros 16 bits de 1 (0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0)  -> Imprime 0
        Espacio equivalente a 2 -> Imprime los segundos 16 bits de 1 (0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1)  -> Imprime 1
        Espacio equivalente a 3 -> Imprime los primeros 16 bits de 2 (0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0)  -> Imprime 0
        Espacio equivalente a 4 -> Imprime los segundos 16 bits de 2 (0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0)  -> Imprime 2
        Espacio equivalente a 5 -> Imprime los primeros 16 bits de 3 (0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0)  -> Imprime 0
        Espacio equivalente a 6 -> Imprime los segundos 16 bits de 3 (0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1)  -> Imprime 3
        Espacio equivalente a 7 -> Imprime los primeros 16 bits de 4 (0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0)  -> Imprime 0
        Espacio equivalente a 8 -> Imprime los segundos 16 bits de 4 (0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0)  -> Imprime 4
        Espacio equivalente a 9 -> Imprime los primeros 16 bits de 5 (0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0)  -> Imprime 0
    */
    for(i=0; i<10; i++) {
        printf("%d\n", *I2S(x+i));
    }
    
}
