#include <stdio.h>
#include <stdlib.h>
#include "lib/petest.h"

void fatal(char *msg){
	fprintf(stderr, "Erro: %s\n", msg);
	exit(1);
}

void usage(void){
	printf("Uso:\n\treadpe <arquivo.exe>\n");
	exit(1);
}

int main(int argc, char * argv[]){
	FILE * fh;
	unsigned char buffer[32];
	
	if (argc != 2)
		usage();

	fh = fopen(argv[1], "rb");

	if (fh == NULL)
		fatal("arquivo não encontrado ou sem permissão de leitura");

	if(fread(buffer, 32, 1, fh) != 1)
		fatal("Erro ao ler os 32 bytes do arquivo.");
	
	fclose(fh);

	if(!petest_ispe(buffer))
		fatal("hmm, o aquivo não parece um executável PE. :/");
	
	return 0;
	
	
}
	
