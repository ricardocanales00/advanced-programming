20 puntos

1. Explica por que este programa funciona con threads pero no podria funcionar con procesos.
Sucede que las variables globales que se tienen en el código se generarían una copia local para el cada proceso, y entonces no compartirian la misma información

2. Que pasaria si alguno de los hilos encuentra un error y termina antes que los demas?
Terminarian el resto de los hilos.