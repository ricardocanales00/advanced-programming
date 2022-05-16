#include <stdio.h>
#include <unistd.h>

void funcion(int a, int b);

void call_3_times(int a) {
    int i;

    for(i=0; i<3; i++) {
        printf("Proceso %d, iteracion %d\n", a, i);
        sleep(1);
    }
}

nt main() {
    int i;
    call_3_times(0);
    call_3_times(1);
    call_3_times(2);
}
