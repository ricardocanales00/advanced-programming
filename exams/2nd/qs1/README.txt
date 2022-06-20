30 puntos

Crea un programa que 

1. Lea el archivo sayings.txt 
2. Imprima una linea aleatoria de ese archivo cada vez que se ejecute. 

Aunque se puede hacer de otras maneras deberas leer primero
todo el archivo a un arreglo declarado como:

char data[51][80];

Son 51 lineas en el archivo y 80 es suficiente para guardar cada linea. Lo mas facil es usar fgets.
Recuerda que en C no puedes copiar strings con =.

Para usar numeros aleatorios primero inicializa el motor con

srandom(getpid());

y luego un numero aleatorio entre 0-51 se obtiene con random()%51.