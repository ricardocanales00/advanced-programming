#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <math.h>

#define THREADS 10
#define MAX_NUM 10000000

int primos[MAX_NUM];
int ocupado[MAX_NUM];

// Si x es primo regresa 1 (true)
int primo(int x) {
	int i;

	for (i=2; i<sqrt(x); i++) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}


void * criba(void * x) {
	int i;

	for (i=0; i<MAX_NUM; i++) {
		if (!ocupado[i]) {
			ocupado[i] = 1;
			//printf("%d - primo %d\n", (int)x, i);
			if (primo(i)) {
				primos[i] = 1;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	pthread_t t[THREADS];
	void *res;
	int s, i, nthreads;

	nthreads = atoi(argv[1]);
	

	for (i=0;i<MAX_NUM;i++) ocupado[i] = 0;
	for (i=0;i<MAX_NUM;i++) primos[i] = 0;


	for (i=0; i<nthreads; i++) {
	   	s = pthread_create(&t[i], NULL, criba, (void *)i); 
		if (s != 0) {
		        perror("pthread_create");
		        exit(-1);
		}
	}

	for (i=0; i<nthreads; i++) {
		s = pthread_join(t[i], &res);
		if (s != 0) {
			perror("pthread_join");
			exit(-1);
		}
	}
	//for (i=2;i<MAX_NUM;i++) if (primos[i]) printf("%d es primo\n", i);

	exit(0);
}