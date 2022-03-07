/*
––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
# Programación Avanzada
Módulo | 'main.c'
Ricardo Canales López | A01422699
Marzo 6, 2022
––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void leibniz(int);

int main(int argc, const char *argv[]){
	int option = 0, n = 0, m = 0;
	int globalInicial[10000];
	long Long = 1, arr[1000][1000]; 
	int arra[3] = {1000,10000,1000000};
	printf("Seleccione el ejercicio a ejecutar\n");
	printf("1) Memory allocation\n");
	printf("2) Command << for 64-bit var\n");
	printf("3) Matriz\n");
	printf("4) Comportamiento size\n");
	printf("5) Leibniz Formula\n");
    scanf("%d", &option);

    switch(option){
    	case 1:
    		printf("Tamaño de array original: ");
    		scanf("%d", &n);
    		while (1) {
    			int * numeros = (int *) malloc(n * sizeof(int)); // Se reserva la memoria original
		        printf("%lx \n", (long)numeros);
		    }
    		break;
    	case 2:
    		Long = 1;
			for (int i = 0; i < 63; ++i){
				printf("%ld \n", Long);
				Long <<= 1;
			}
    		break;
    	case 3:
    		for (int i = 0; i < 20; ++i){
    			printf("%p\n", &arr[i][0]);
    		}
    		printf("\n");
    		for (int j = 0; j < 20; ++j){
				printf("%p\n", &arr[0][j]);
			}
    		break;
    	case 4:
    		printf("Resultados ---------------------------\n");
    		printf("Variable global ----------------------\n");
    		printf("__TEXT	__DATA	__OBJC	others	dec	hex\n");
    		printf("16384	16384	0	4295000064	4295032832	100010000\n");

    		printf("Variable global inicializada ----------\n");
    		printf("__TEXT	__DATA	__OBJC	others	dec	hex\n");
    		printf("16384	16384	0	4295000064	4295032832	100010000\n");

    		printf("Variable en stack ---------------------\n");
    		printf("__TEXT	__DATA	__OBJC	others	dec	hex\n");
    		printf("16384	16384	0	4295000064	4295032832	100010000\n");

    		printf("Variable en stack inicializada ---------\n");
    		printf("__TEXT	__DATA	__OBJC	others	dec	hex \n");
    		printf("16384	16384	0	4295000064	4295032832	100010000\n");

    		printf("Array global ----------------------------\n");
    		printf("__TEXT	__DATA	__OBJC	others	dec	hex\n");
    		printf("16384	49152	0	4295000064	4295065600	100018000\n");

    		printf("Array stack ----------------------------\n");
    		printf("__TEXT	__DATA	__OBJC	others	dec	hex\n");
    		printf("16384	16384	0	4295000064	4295032832	100010000\n");
    		break;
    	case 5:
 			for (int i = 0; i < 3; ++i){
 				leibniz(arra[i]);
 			}
    		break;
    	default:
    		printf("Excercise not found\n");
    		break;
    }
	return 0;
}

void leibniz(int n){
	double signo = 1, denominador = 1, pi = 0;
    for (int i = 0; i < n; ++i) {
		pi += signo * (4 / denominador);
		signo = signo * -1;
	    denominador = denominador + 2;
    }
    printf("El valor de pi con %d iteraciones es %1.20lf\n", n, pi);
}
