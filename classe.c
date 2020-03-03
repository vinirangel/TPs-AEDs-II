#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool      short
#define true      1
#define false     0
#define equals(a, b) (((strcmp(a, b) == 0) ? true : false))
#define NUMENTRADA 1000
#define TAMLINHA   1000

struct personagem{

char* file;
char* nome;
int altura;
double peso;
char* corDoCabelo;
char* corDaPele;
char* corDosOlhos;
char* anoNascimento;
char* genero;
char* homeworld;   
}personagem;

void lerArquivo(char* filename, struct personagem *personagem)
{
    FILE* arquivo = fopen(filename, "rt");
    int buffer_size = 3000;
    //char* buffer[500] = (char *)malloc(buffer_size*sizeof(char*));

    do{
    getline(&personagem->file,&buffer_size,arquivo);
    } while(!feof(arquivo));

    fclose(arquivo);
    printf("%s\n",personagem->file);
}

bool isFim(char* s){
	return (strlen(s) >= 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M');
}

int main(int argc, char** argv)
{
	char entrada[NUMENTRADA][TAMLINHA];
	int numEntrada = 0;
    
    do {
		fgets(entrada[numEntrada], TAMLINHA, stdin);
	} while (isFim(entrada[numEntrada++]) == false);
	numEntrada--;
    
    lerArquivo(entrada[0], &personagem);
}