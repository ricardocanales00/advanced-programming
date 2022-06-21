#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <unistd.h>


#define PORT 8000
#define SIZE 8
#define MSGSIZE 1024
#define FILE_TO_SEND "logo-tec.png"



void serve(int s) {
    char buffer[MSGSIZE];
    int size, i=0;
    struct stat buf;
    
    //breakers
    const char space[2] = " ";
    const char dot[2] = ".";

    FILE *sin = fdopen(s, "r");
    FILE *sout = fdopen(s, "w");
	
	//Token
	char *tokenSpace;
	char *tokenDot;
	
	//route & type
	char routeT[200]; // used for strtok.
	char route[200];
	char type[50];
	
    // Reads the request from the client
    while( fgets(buffer, MSGSIZE, sin) != NULL ) {
        printf("%d - [%s]\n", ++i, buffer);
        if(i == 1){
        	int index = 1;
        	//Parse 
        	tokenSpace = strtok(buffer, space);
        	while (tokenSpace != NULL){
        		if (index == 2){
        			strcpy(routeT, tokenSpace+1);
        			strcpy(route, tokenSpace+1);
				}
			index++;
        		tokenSpace = strtok(NULL,space);
			}
			tokenDot = strtok(routeT, dot);
			while (tokenDot != NULL){
				strcpy(type, tokenDot);
				tokenDot = strtok(NULL, dot);
			}	
		}
        // A blank line is found -> end of headers
        if(buffer[0] == '\r' && buffer[1] == '\n') {
            break;
        }
    }
    sleep(1);

    // Builds response
    sprintf(buffer, "HTTP/1.0 200 OK\r\n");
    fputs(buffer, sout);

    sprintf(buffer, "Date: Fri, 31 Dec 1999 23:59:59 GMT\r\n");
    fputs(buffer, sout);
    
    if (strcmp(type,"html") == 0){
    	sprintf(buffer, "Content-Type: text/html\r\n");
    	fputs(buffer, sout);	
	}
	
	else if(strcmp(type,"png") == 0){
		sprintf(buffer, "Content-Type: image/png\r\n");
    	fputs(buffer, sout);
	}

    stat(route, &buf);
    printf("Size -----------> %d\n", (int)buf.st_size);

    sprintf(buffer, "Content-Length: %d\r\n", (int)buf.st_size);
    fputs(buffer, sout);

    sprintf(buffer, "\r\n");
    fputs(buffer, sout);

    FILE *fin = fopen(route, "r");
    while ( (size = fread(buffer, 1, MSGSIZE, fin)) != 0) {
        size = fwrite(buffer, 1, size, sout);
    }

    fflush(0);
}

int main() {
    int sd, sdo, size, r;
    struct sockaddr_in sin, pin;
    socklen_t addrlen;

    // 1. Crear el socket
    sd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(PORT);

    // 2. Asociar el socket a IP:port
    r = bind(sd, (struct sockaddr *) &sin, sizeof(sin));
    if (r < 0) {
        perror("bind");
        return -1;
    }
    // 3. Establecer backlog
    listen(sd, 5);

    addrlen = sizeof(pin);
    // 4. Esperar conexion
    while( (sdo = accept(sd, (struct sockaddr *)  &pin, &addrlen)) > 0) {
        if(!fork()) {
            printf("Connected from %s\n", inet_ntoa(pin.sin_addr));
            printf("Port %d\n", ntohs(pin.sin_port));

            serve(sdo);

            close(sdo);
            exit(0);
        }
    }
    close(sd);

    sleep(1);

}