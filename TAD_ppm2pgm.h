#ifndef TAD_ppm2pgm_h_
#define TAD_ppm2pgm_h_

typedef unsigned char byte;

/* Cada imagem PPM consiste em (http://netpbm.sourceforge.net/doc/ppm.html):
 1. Um numero mágico que identifica o tipo do arquivo. O número mágico para imagem PPM é "P3";
 2. Espaço em branco (brancos, TABs, CRs, LFs);
 3. A largura da imagem, formatada em caractere ASCII em decimal;
 4. Espaço em branco;
 5. A altura, formatada em caractere ASCII em decimal;
 6. Espaço em branco;
 7. O máximo valor da cor (Maxval), em decimal novamente;
 8. Um simples caractere em branco (usualmente, nova linha);
 9. Um raster de linhas (a altura define a quantidade de linhas), de ordem superior a inferior. Cada linha consiste em pixels de largura, da esquerda para a direita. Cada pixel é um tripleto de amostras vermelhas, verdes e azuis, nessa ordem. Cada amostra é representada em binário puro por 1 byte.  */

/* Estruturas para armazenar a imagem PPM */
typedef struct {
	int r, g, b;
} ppm_pixel;

typedef struct {
	char format[3];
 	unsigned int w;
	unsigned int h;
	int m;
	ppm_pixel **matrix;
} ppm_image;

/* Estruturas para acessar a imagem PGM */
typedef struct {
	int p;
} pgm_pixel;

typedef struct {
	char format[3];
 	unsigned int w;
	unsigned int h;
	int m;
	pgm_pixel **matrix;
} pgm_image;

/* Implemente essas funções no arquivo TAD_ppm2pgm.c  */
ppm_image * ler_ppm(const char *filename);
pgm_image * ppm_para_pgm(const ppm_image *ppm);
void escreve_pgm(const char *filename, const pgm_image *pgm);

#endif
