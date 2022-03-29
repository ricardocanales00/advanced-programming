#include <stdio.h>
 
// 3. ¿Qué quieren decir los elementos de este arreglo?
/*  Respuesta = son los valores que se incrementa el valor en la variable result.
    
*/
int bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
 
// 1. ¿Qué hace la función what?
/*  Respuesta:
    Realiza 8 iteraciones, en cada una suma el valor del resultado de aplicar una mascara de bits al valor asignado en bits[num]
    y la mascara.

    Posteriormente, hace shift 4 posiciones del valor num y nuevamente agrega el valor a la suma.
*/
unsigned int what(unsigned int num) {
    int i, result = 0;
    i = sizeof(int)*2; //sizeof(int) = 4) *2 -> 8 número de repeticiones

    // Se repite 8 veces -> 7, 6, 5, 4, 3, 2, 1, 0
    while (i--) {
        //resulta almacena el valor almacenado en bits en la posicion resultante de la opacion AND
        // entre num (se traduce a binario) y Oxf que es equivalente a 15
        result += bits[num & 0xf];
        printf("Result es : %d\n", result);
        // se hace shift el valor de num 4 posciones a la derecha
        num >>= 4;
    }
    return result;
}
 

int main() {
    printf("%d\n", what(31));
    printf("%d\n", what(64));
    printf("%d\n", what(127));
    printf("%d\n", what(256));
    printf("%d\n", what(511));
    printf("%d\n", what(1024));
    printf("%d\n", what(2047));
    printf("%d\n", what(4096));

}