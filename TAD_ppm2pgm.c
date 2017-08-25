#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_ppm2pgm.h"

/* Implemente e defina tudo que achar necessário */

// Implemente a função para ler o arquivo de entrada
ppm_image * ler_ppm(const char *filename) {
 FILE *img;
 ppm_image *imgInput;

 imgInput = (ppm_image *)malloc(sizeof(ppm_image));

 img = fopen(filename, "r");
 fscanf(img,"%2s", imgInput->format );
 fscanf(img, "%u", &imgInput->w);
 fscanf(img, "%u", &imgInput->h);
 fscanf(img, "%c", &imgInput->m);

 printf("format:%2s\nw:%u\nh:%u \nm:%d\n", imgInput->format, imgInput->w,imgInput->h,imgInput->m);

 ppm_pixel pix[imgInput->h][imgInput->w];

for(int r = 0 ;r < (imgInput->h); r++){
   printf("\n");
   for(int c = 0 ; c < (imgInput->w); c++){
     fscanf(img,"%c %c %c", &pix[r][c].r, &pix[r][c].g, &pix[r][c].b);
     printf("%d %d %d  ", (pix[r][c].r), pix[r][c].g, pix[r][c].b );
   }
 }

 imgInput->matrix = &pix;
 fclose(img);
 return imgInput;
}

// Implemente a função para converter a imagem colorida PPM para a imagem em escala de cinzas PGM
pgm_image * ppm_para_pgm(const ppm_image *ppm) {


}



// Implemente a função para escrever a imagem PGM no arquivo
void escreve_pgm(const char *filename, const pgm_image *pgm) {

}
