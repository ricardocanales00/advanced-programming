#include <stdio.h>
#include <unistd.h>
#define LINE 64

char line[LINE];
int fd[2];

void coro() {
    while(1) {
        read(fd[1], line, LINE);
        printf("%s\n", line);
    }
}

int main () {

    pipe(fd);
    if (!fork()) coro(fd);

    FILE * fin = fopen("himno.txt", "r");
    while(1) {
        fgets(line, LINE, fin);
        if (feof(fin)) break;
        write(fd[0], line, LINE);
        sleep(1);
    }

    return 0;
}
