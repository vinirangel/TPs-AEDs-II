#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool      short
#define true      1
#define false     0
#define equals(a, b) (((strcmp(a, b) == 0) ? true : false))
#define NUMENTRADA 1000
#define TAMLINHA   1000

struct personagem{ //Struct utilizado para guardar as informacoes relevantes
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

void lerArquivo(char* filename, struct personagem *personagem) //Le o arquivo e guarda tudo em uma variavel do struct
{
	filename[strlen(filename) - 1] = '\0';
	FILE* arquivo = fopen(filename, "rt");
	char* buffer = (char*) malloc(sizeof(char*)*1000);
	char* tmp = (char*) malloc(sizeof(char*)*1000);

	do{
		fgets(buffer,300,arquivo);
	} while(!feof(arquivo) && strstr(buffer, "'films'") == NULL);

	personagem->file = strdup(buffer);
	fclose(arquivo);
}

void setNome(struct personagem *personagem)
{
	char* cpy = strdup(personagem->file);
	char* tmp = strtok(cpy,":");

	for(int x = 0; x < 2; x++)
	{
		tmp = strtok(NULL,"'");
	}
	personagem->nome = strdup(tmp);
}

void getNome()
{
	printf(" ## %s",personagem.nome);
}

void setAltura(struct personagem *personagem)
{
	char* cpy = strdup(personagem->file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 6; x++)
	{
		tmp = strtok(NULL,"'");
	}
	personagem->altura = atoi(tmp);
}

void getAltura()
{
	printf(" ## %d",personagem.altura);
}

void setPeso(struct personagem *personagem)
{
	char* cpy = strdup(personagem->file);
	char* tmp = strtok(cpy,":");
	
	for(int x = 0; x < 10; x++)
	{
		tmp = strtok(NULL,"'");
	}
	if(strstr(tmp,"unknown"))
	{
		personagem->peso = 0;
	}
	else{
		sscanf(tmp, "%lf", &personagem->peso);
	}
}

void getPeso()
{
	if((personagem.peso - (int)personagem.peso) == 0)
	{
		printf(" ## %.0lf",personagem.peso);
	}
	else{
		printf(" ## %.1lf",personagem.peso);
	}
}

void setCorDoCabelo(struct personagem *personagem)
{
	char* cpy = strdup(personagem->file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 14; x++)
	{
		tmp = strtok(NULL,"'");
	}
	personagem->corDoCabelo = strdup(tmp);
}

void getCorDoCabelo()
{
	printf(" ## %s",personagem.corDoCabelo);
}

void setCorDaPele(struct personagem *personagem)
{
	char* cpy = strdup(personagem->file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 18; x++)
	{
		tmp = strtok(NULL,"'");
	}
	personagem->corDaPele = strdup(tmp);
}

void getCorDaPele()
{
	printf(" ## %s", personagem.corDaPele);
}

void setCorDosOlhos(struct personagem *personagem)
{
	char* cpy = strdup(personagem->file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 22; x++)
	{
		tmp = strtok(NULL,"'");
	}
	personagem->corDosOlhos = strdup(tmp);
}

void getCorDosOlhos()
{
	printf(" ## %s", personagem.corDosOlhos);
}

void setAnoNascimento(struct personagem *personagem)
{
	char* cpy = strdup(personagem->file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 26; x++)
	{
		tmp = strtok(NULL,"'");
	}
	personagem->anoNascimento  = strdup(tmp);
}

void getAnoNascimento()
{
	printf(" ## %s", personagem.anoNascimento);
}

void setGenero(struct personagem *personagem)
{
	char* cpy = strdup(personagem->file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 30; x++)
	{
		tmp = strtok(NULL,"'");
	}
	personagem->genero  = strdup(tmp);
}

void getGenero()
{
	printf(" ## %s", personagem.genero);
}

void setHomeworld(struct personagem *personagem)
{
	char* cpy = strdup(personagem->file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 34; x++)
	{
		tmp = strtok(NULL,"'");
	}
	personagem->homeworld  = strdup(tmp);
}

void getHomeworld()
{
	printf(" ## %s ## \n", personagem.homeworld);
}

void printAll() //metodo que imprime todos os gets
{
	getNome();
	getAltura();
	getPeso();
	getCorDoCabelo();
	getCorDaPele();
	getCorDosOlhos();
	getAnoNascimento();
	getGenero();
	getHomeworld();
}

bool isFim(char* s){
	return (strlen(s) >= 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M');
}

int main(int argc, char** argv)
{
	char entrada[NUMENTRADA][TAMLINHA];
	int numEntrada = 0;

	//Ler todas as entradas
	do {
		fgets(entrada[numEntrada], TAMLINHA, stdin);

	} while (isFim(entrada[numEntrada++]) == false);
	numEntrada--;

	//Usar todos os metodos de set e get para cada entrada lida anteriormente
	for(int x = 0; x < numEntrada; x++)
	{
		lerArquivo(entrada[x], &personagem);
		setNome(&personagem);
		setAltura(&personagem);
		setPeso(&personagem);
		setCorDoCabelo(&personagem);	
		setCorDaPele(&personagem);	
		setCorDosOlhos(&personagem);	
		setAnoNascimento(&personagem);	
		setGenero(&personagem);
		setHomeworld(&personagem);
		printAll();
	}

}
