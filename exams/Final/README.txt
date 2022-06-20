Selecciona dos de tres problemas implementar, c/u vale 25.

1. ********************************************************************************
badcopy.c
Al compilar este programa y correr:
(el comando diff es para comparar diferencias entre archivos).

$ ./badcopy himno.txt copia.txt
$ diff himno.txt copia.txt

Se encuentra que la copia es correcta, sin embargo al copiar:

$ ./badcopy logo.jpg copia.jpg
$ diff logo.jpg copia.jp
Binary files logo.jpg and copia.jpg differ

Los archivos son distintos.

Corregir el programa para que copie correctamente.

2. ********************************************************************************
himnopipe.c
Cuidado, si lo ejecutas tal cual, la terminal se cicla.

El programa debe leer el archivo himno.txt e ir enviando lo que lee para
que el hijo lo imprima una vez cada segundo, pero no sirve. Corregirlo.

3. ********************************************************************************
mfork.c
Sincronizar adecuadamente para que, sin modificar como se crean los procesos (no quitar fork),
tanto el padre como el nieto impriman un solo mensaje, sin encimarse. El regreso
de control a la consola debe ser despues de que ambos imprimen.
