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
#include<math.h>

int global, globalInicial = 1000, arreglo[100][2];

void arr_print(int *, int);
void arr_addnumers(int *, int, int *, int);

void leibniz(int);

int main(int argc, const char *argv[]){
	int option = 0, n = 0, m = 0;
	long Long = 1; 
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
    		int * numeros = (int *) malloc(n * sizeof(int)); // Se reserva la memoria original
    		int * fin = numeros + n; //Se calcula el tamaño del arreglo y guarda el valor en fin
    		arr_addnumers(numeros, n, fin, 0);
    		arr_print(numeros, n);
    		printf("¿Cuántos numeros nuevos se agregarán?");
    		scanf("%d", &m);
    		numeros = (int *) realloc(numeros, (n + m) * sizeof(int)); //Se redimenciona el array n + m
    		fin = numeros + n + m; //El recalculo del tamaño por ingreso de nuevos elementos
    		arr_addnumers(numeros, n, fin, 1);
    		arr_print(numeros, n+m);
    		free(numeros);
    		break;
    	case 2:
    		Long = 1;
			for (int i = 0; i < 63; ++i){
				printf("%ld \n", Long);
				Long <<= 1;
			}
    		break;
    	case 3:

    		break;
    	case 4:
    		printf("Variable global ----------------------\n");
    		printf("Size of % 8ld\n", sizeof(global));
    		printf("Variable global valor inicial --------\n");
    		printf("Size of % 8ld\n", sizeof(globalInicial));
    		printf("Variable en el stack -----------------\n");
    		printf("Size of  % 8ld\n", sizeof(option));
    		printf("Arreglos -----------------------------\n");
    		printf("Size of % 8ld\n", sizeof(arreglo));
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


void arr_print(int * numeros, int n){
    printf("-- Print---------\n");
    for (int i = 0; i < n; ++i) {
        printf("%p\n", (void *) &numeros[i]);
    }
    printf("\n");
}

void arr_addnumers(int * numeros, int n, int * fin, int isUpdate){
	int helper = 0;
	if (isUpdate == 1) { numeros = numeros + n; }
    for (int * aux = numeros; aux < fin; ++aux) {
    	printf("Ingresa numero: ");
    	scanf("%d", &helper);
        *aux = helper;
    }
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
