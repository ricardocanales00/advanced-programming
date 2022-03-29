#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT "tigre.tga"
#define OUTPUT "resultado.tga"

// Pregunta 1: ¿Cuántos bytes mide la siguiente estructura?
// Res: 30 bits + padding

typedef struct {
   char id_len;                 // ID Field (Number of bytes - max 255)
   char map_type;               // Colormap Field (0 or 1)
   char img_type;               // Image Type (7 options - color vs. compression)
   int  map_first;              // Color Map stuff - first entry index
   int  map_len;                // Color Map stuff - total entries in file
   char map_entry_size;         // Color Map stuff - number of bits per entry
   int  x;                      // X-coordinate of origin 
   int  y;                      // Y-coordinate of origin
   int  width;                  // Width in Pixels
   int  height;                 // Height in Pixels
   char bpp;                    // Number of bits per pixel
   char misc;                   // Other stuff - scan origin and alpha bits
} targa_header;

// Pregunta 2: En el archivo original se pasaba el parámetro targa_header y lo cambié a pasar un apuntador a targa_header, ¿por qué es mejor así?
// Res: Ahora apunta a la dirección de memoria de la declaración de header, este apunta directamente a la memoria y eficientiza el uso

void writeheader(targa_header *h, FILE *tga) {
// Pregunta 3: fputc escribe un byte al archivo, ¿cuántos bytes se escriben aquí?
// Res: Se escriben en fputc 2 bytes

// Pregunta 4: Compara con el tamaño de la estructura, ¿qué tipo de dato es mejor que int en este caso?
// Res: short int

   fputc(h->id_len, tga);          // Write chars for ID, map, and image type
   fputc(h->map_type, tga);
   fputc(h->img_type, tga);

// Pregunta 5: La operación % y / qué hacen y ¿por qué crees que se apliquen aquí? Tip: https://en.wikipedia.org/wiki/Endianness
// Res: Se está imprimiendo dentro del seguno, acorde a esto es que se asignan por entero dos de los bits
   fputc(h->map_first % 256, tga); // Write integer, low order byte first
   fputc(h->map_first / 256, tga); // Write second byte of integer, high order
   fputc(h->map_len % 256, tga);   // Another integer 
   fputc(h->map_len / 256, tga);
   fputc(h->map_entry_size, tga);  // Write a char - only one byte
   fputc(h->x % 256, tga);         // More integers
   fputc(h->x / 256, tga);
   fputc(h->y % 256, tga);
   fputc(h->y / 256, tga);
   fputc(h->width % 256, tga);     // Even more integers
   fputc(h->width / 256, tga);
   fputc(h->height % 256, tga);
   fputc(h->height / 256, tga);
   fputc(h->bpp, tga);             // Write two chars
   fputc(h->misc, tga);
}

void readheader(targa_header *h, FILE *tga) {
// fgetc lee un byte desde el archivo
   h->id_len = fgetc(tga);          // Write chars for ID, map, and image type
   h->map_type = fgetc(tga);
   h->img_type = fgetc(tga);
   
// Pregunta 6: ¿Qué hace la siguiente operación? - compara con la pregunta 5.
// Res: Se gestiona la estructura para poder incluir lo que se agrega de la nueva imagen
   h->map_first = fgetc(tga) + fgetc(tga)*256; 
   h->map_len = fgetc(tga) + fgetc(tga)*256;   // Another integer 
   h->map_entry_size = fgetc(tga);  // Write a char - only one byte
   h->x = fgetc(tga) + fgetc(tga)*256;
   h->y = fgetc(tga) + fgetc(tga)*256;
   h->width = fgetc(tga) + fgetc(tga)*256;
   h->height = fgetc(tga) + fgetc(tga)*256;
   h->bpp = fgetc(tga);             // Write two chars
   h->misc = fgetc(tga);
}

void prepareHeader(targa_header *header, int x, int y) {
   header->id_len = 0;          /* no ID field */
   header->map_type = 0;        /* no colormap */
   header->img_type = 2;        /* trust me */
   header->map_first = 0;       /* not used */
   header->map_len = 0;         /* not used */
   header->map_entry_size = 0;  /* not used */
   header->x = 0;               /* image starts at (0,0) */
   header->y = 0;
   header->width = x;
   header->height = y;
   header->bpp = 24;            /* 24 bits per pixel */
   header->misc = 0x20;         /* scan from upper left corner */	
}

int main(void) {
   FILE *tga;               // Pointer to a FILE
   targa_header header;     // Variable of targa_header type
   int x, y;				// Size of the image
   unsigned char *data;		// Array

   tga = fopen(INPUT, "rb");
   readheader(&header, tga);  
   // Print size of the image
   printf("La imagen mide %dx%d\n", header.width, header.height);
   data = malloc(header.width * header.height * 3);

	// Read data to the array, fread reads 3 elements but header.width*header.height times
   fread(data, 3, header.width*header.height, tga);
   fclose(tga);

	// 2D iteration
   for(y = 0; y < header.height; y++)
      for(x = 0; x < header.width; x++) {
        unsigned char r, g, b, average, lightness, luminossity;
        
        // Components for red, gree, and blue (inverted in targa)
        b = data[(y * header.width + x)*3 + 0];
        g = data[(y * header.width + x)*3 + 1];
        r = data[(y * header.width + x)*3 + 2];
        
        /* Aquí modificar los valores de r, g, b */

        
        // Algoritmo 1: lightness (max(R, G, B) + min(R, G, B)) / 2.
        lightness = (max(max(r,g),b)+min(min(r,g),b))/2;
        // Algoritmo 2: luminosity 0.21 R + 0.72 G + 0.07 B.  
        luminossity = r*0.21 + g*0.72 + b*0.07;
        // Algoritmo 3:
        average = (r+g+b)/3;
        
        data[(y * header.width + x)*3 + 0] = average;
        data[(y * header.width + x)*3 + 1] = average;
        data[(y * header.width + x)*3 + 2] = average;
    }

	// Open output file
   tga = fopen(OUTPUT, "wb");
   
   writeheader(&header, tga);  
   for(y = 0; y < header.height; y++)
      for(x = 0; x < header.width; x++)	{
        fputc(data[(y * header.width + x)*3 + 0], tga);
        fputc(data[(y * header.width + x)*3 + 1], tga);
        fputc(data[(y * header.width + x)*3 + 2], tga);
	}

/* close the file */
   fclose(tga);

/* that was easy, right? */
   return 0;
}
