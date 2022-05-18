#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

FILE *file;

void handler(int sig){
    printf("A Process - PID [%d]\n",getpid());
}

int main () {
  int n;
  file = fopen("proceso.pid","w+");
  if (!fork()){
    fprintf(file, "%d", getpid());
    fflush(file);
    signal(SIGUSR1, handler);
    if(!fork()){
      if(!fork()){
        printf("C Process - PID [%d] - Parent's ID [%d]\n", getpid(), getppid());
        sleep(3);
        file = fopen("proceso.pid","rw");
        fscanf(file, "%d", &n);
        kill((pid_t)n,SIGUSR1);
      }
      wait(0);
    }
    wait(0);
  }
}