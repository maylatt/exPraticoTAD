#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_ppm2pgm.h"

/**
 * AEDS II - Exercício Prático sobre TAD: 50 Tons de Cinza
 *
 * Implemente cada função definida no TAD
 */
int main(int argc, char **argv) {
	if (argc != 3) {
		//Escreva aqui a verificação de erro
		printf("Agumentos invalidos! Por favor entre com: ./executableFile input.ppm output.pgm\n");
		return 1;
	}

	// Ler a entrada PPM
	ppm_image *ppm = ler_ppm(argv[1]);

	// Conveter para PGM
	pgm_image *pgm = ppm_para_pgm(ppm);

	// Escrever a saída PGM
	escreve_pgm(argv[2], pgm);

	return 0;
}
