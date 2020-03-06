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

/*char* split(char* begin, char* end, char* texto)
{
	char* tmp = strdup(texto);
	while( tmp[strchr(tmp, 
}*/

void lerArquivo(char* filename, struct personagem *personagem)
{
	filename[strlen(filename) - 1] = '\0';
	FILE* arquivo = fopen(filename, "rt");
	//int buffer_size = 5000;
	char* buffer = (char*) malloc(sizeof(char*)*1000);
	char* tmp = (char*) malloc(sizeof(char*)*1000);

	do{
		fscanf(arquivo,"%s", buffer);
		strcat(tmp, buffer);
	} while(!feof(arquivo) && strstr(buffer, "'films'") == NULL);
	
	personagem->file = strdup(tmp);
	//printf("\n%s", personagem->file);
	fclose(arquivo);
	free (buffer);
	free (tmp);
}

void setNome(struct personagem *personagem)
{
	char* cpy = strdup(personagem->file); //(char*) malloc(sizeof(char*)*1000);
	char* tmp = strtok(cpy,":");
	
	/*while(tmp != NULL && strstr(tmp,"',") != NULL )
	{
		tmp = strtok(NULL,"'");
	}*/
	for(int x = 0; x < 1; x++)
	{
		tmp = strtok(NULL,"'");
	}
	//printf("\n%s",tmp);
		//tmp = strtok(NULL,"'");
	/*int x = 0;
	while(tmp != NULL && strstr(tmp,"'height'") == NULL )
	{
		printf("\nENTREI NO LOOP");
		printf("\n%d",x);
		tmp = strtok(NULL,"'");
		x++;
	}
	tmp = strtok(NULL,"'");*/
	personagem->nome = tmp;
	printf("\n%s",personagem->nome);
	
	/*do{
	strcat(tmp, personagem->file[IndexOf(		//strstr(personagem->file, ":"))
	}while(strstr(personagem->file,",") == NULL);*/
}

void setHeight(struct personagem *personagem)
{
	char* cpy = strdup(personagem->file); //(char*) malloc(sizeof(char*)*1000);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 3; x++)
	{
		tmp = strtok(NULL,"'");
	}
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
	//printf("\n%s",entrada[0]);
	lerArquivo(entrada[0], &personagem);
	printf("\n%s", personagem.file);
	setNome(&personagem);
}
