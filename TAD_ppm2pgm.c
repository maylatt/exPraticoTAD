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
 fscanf(img, "%d", &imgInput->m);

 printf("formato:%2s\nw:%u\nh:%u \nm:%d\n", imgInput->format, imgInput->w, imgInput->h, imgInput->m);

 imgInput->matrix = (ppm_pixel **)malloc((imgInput->h)*sizeof(ppm_pixel *));

for(int r = 0 ;r < (imgInput->h); r++){
  imgInput->matrix[r] = (ppm_pixel *)malloc((imgInput->w)*sizeof(ppm_pixel));
   for(int c = 0 ; c < (imgInput->w); c++){
     fscanf(img,"%d %d %d", &imgInput->matrix[r][c].r, &imgInput->matrix[r][c].g, &imgInput->matrix[r][c].b);
     //printf("%d %d %d ", imgInput->matrix[r][c].r, imgInput->matrix[r][c].g, imgInput->matrix[r][c].b);
   }
 }

 fclose(img);
 return imgInput;
}

// Implemente a função para converter a imagem colorida PPM para a imagem em escala de cinzas PGM
pgm_image * ppm_para_pgm(const ppm_image *ppm) {

  pgm_image *imgOutput;

  imgOutput = (pgm_image *)malloc(sizeof(pgm_image));

  imgOutput->format[0]= 'P';
  imgOutput->format[1]= '2';
  imgOutput->format[2]= '\0';
  imgOutput->w = ppm->w;
  imgOutput->h = ppm->h;
  imgOutput->m = 49;

  imgOutput->matrix = (pgm_pixel **)malloc((imgOutput->h)*sizeof(pgm_pixel *));

 for(int r = 0 ;r < (imgOutput->h); r++){
   imgOutput->matrix[r] = (pgm_pixel *)malloc((imgOutput->w)*sizeof(pgm_pixel));
    for(int c = 0 ; c < (imgOutput->w); c++){
      imgOutput->matrix[r][c].p = (int)((0.192156863)*(0.30*ppm->matrix[r][c].r + 0.59*ppm->matrix[r][c].g + 0.11*ppm->matrix[r][c].b));
      printf("%d", imgOutput->matrix[r][c].p);
    }
  }

  return imgOutput;


}



// Implemente a função para escrever a imagem PGM no arquivo
void escreve_pgm(const char *filename, const pgm_image *pgm) {
  FILE *img;
  img = fopen(filename, "w");
  fprintf(img, "%.2s\n", pgm->format);
  fprintf(img, "%u ", pgm->w);
  fprintf(img, "%u\n", pgm->h);
  fprintf(img, "%d\n", pgm->m);

  for(int r = 0 ;r <  (pgm->h); r++){
     for(int c = 0 ; c < (pgm->w); c++){
       fprintf(img, "%d ", pgm->matrix[r][c].p);
     }
     fprintf(img, "\n");
   }
   fclose(img);

}
