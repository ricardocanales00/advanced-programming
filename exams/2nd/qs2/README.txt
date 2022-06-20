30 puntos

1. Crea un proceso con un handler para SIGUSR1 que imprima su PID.

2. El proceso guarda su PID en un archivo llamado proceso.pid (puede ser file i/o o standard i/o).
3. El proceso debe crear un hijo, y ese a su vez crear otro hijo.

A 
  \
   B
    \
     C

4. El proceso C imprime su PID y el de su padre usando getpid() y getppid()
5. El proceso C hace un sleep(3), mientras los otros 2 deben quedar suspendidos (con wait).
6. Luego el proceso C lee del archivo el PID del proceso A y le manda un SIGUSR1.
7. En este momento el handler del proceso A anuncia su PID y termina todo.