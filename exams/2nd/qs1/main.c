#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int random_line = rand() %51; 

	FILE * input;
    char arr[51][80];

	input = fopen("sayings.txt", "r");
	if (input == NULL) {
		perror("file");
		printf("Error, debes proporcionar un archivo\n");
		exit(-1);
	}

    //Por cada linea del archivo
    for (int i = 0; i<51; i ++){
        //Leer una linea en aleatorio del archivo
        fgets(arr[i],80, input);
    }

    /*for(int x = 0; x < 51; x++){
    	for(int y = 0; y < 80; y++){
    		printf("%c", data[x][y]);
    	}
    }*/

   	printf("%s", arr[random_line]);


    return 0;

}
