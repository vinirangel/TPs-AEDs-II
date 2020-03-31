#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define bool      short
#define true      1
#define false     0
#define equals(a, b) (((strcmp(a, b) == 0) ? true : false))
#define NUMENTRADA 1000
#define TAMLINHA   1000

typedef struct personagem{ //Struct utilizado para guardar as informacoes relevantes
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
}PERSONAGEM;

PERSONAGEM newPersonagem()
{
	PERSONAGEM novo;
	novo.nome = (char*)malloc(sizeof(char*)*1000);
	novo.altura = 0;
	novo.peso = 0;
	novo.corDoCabelo = (char*)malloc(sizeof(char*)*1000);
	novo.corDaPele = (char*)malloc(sizeof(char*)*1000);
	novo.corDosOlhos = (char*)malloc(sizeof(char*)*1000);
	novo.anoNascimento = (char*)malloc(sizeof(char*)*1000);
	novo.genero = (char*)malloc(sizeof(char*)*1000);
	novo.homeworld = (char*)malloc(sizeof(char*)*1000);
	return novo;
}

PERSONAGEM clone(PERSONAGEM personagem)
{
	PERSONAGEM clone;
	clone = personagem;
	return clone;
}

PERSONAGEM lerArquivo(char* filename, PERSONAGEM novo) //Le o arquivo e guarda tudo em uma variavel do struct
{
	if(filename[strlen(filename) - 1] == '\n')
	{
		filename[strlen(filename)-1] = '\0';	
		filename[strcspn(filename,"\n")] = '\0';
	}
	printf("%s\n");
	if(filename[strlen(filename) - 1] == '\n')
	{
		printf("DEU MERDA\n");
		//filename[strlen(filename)-1] = '\0';	
	}
	FILE* arquivo = fopen(filename, "rt");
	char* buffer = (char*) malloc(sizeof(char*)*1000);
	char* tmp = (char*) malloc(sizeof(char*)*1000);


	do{
		fgets(buffer,300,arquivo);
	} while(!feof(arquivo) && strstr(buffer, "'films'") == NULL);

	novo.file = strdup(buffer);
	fclose(arquivo);
	return novo;
}

PERSONAGEM setNome(PERSONAGEM novo)
{
	char* cpy = strdup(novo.file);
	char* tmp = strtok(cpy,":");

	for(int x = 0; x < 2; x++)
	{
		tmp = strtok(NULL,"'");
	}
	novo.nome = strdup(tmp);
	return novo;
}

char* getNome(PERSONAGEM novo)
{
	return novo.nome;
}

PERSONAGEM setAltura(PERSONAGEM novo)
{
	char* cpy = strdup(novo.file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 6; x++)
	{
		tmp = strtok(NULL,"'");
	}
	novo.altura = atoi(tmp);
	return novo;
}

int getAltura(PERSONAGEM novo)
{
	return novo.altura;
}

PERSONAGEM setPeso(PERSONAGEM novo)
{
	char* cpy = strdup(novo.file);
	char* tmp = strtok(cpy,":");

	for(int x = 0; x < 10; x++)
	{
		tmp = strtok(NULL,"'");
	}
	if(strstr(tmp,"unknown"))
	{
		novo.peso = 0;
	}
	else{
		sscanf(tmp, "%lf", &novo.peso);
	}
	return novo;
}

double getPeso(PERSONAGEM novo)
{
	return novo.peso;
}

PERSONAGEM setCorDoCabelo(PERSONAGEM novo)
{
	char* cpy = strdup(novo.file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 14; x++)
	{
		tmp = strtok(NULL,"'");
	}
	novo.corDoCabelo = strdup(tmp);
	return novo;
}

char* getCorDoCabelo(PERSONAGEM novo)
{
	return novo.corDoCabelo;
}

PERSONAGEM setCorDaPele(PERSONAGEM novo)
{
	char* cpy = strdup(novo.file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 18; x++)
	{
		tmp = strtok(NULL,"'");
	}
	novo.corDaPele = strdup(tmp);
	return novo;
}

char* getCorDaPele(PERSONAGEM novo)
{
	return novo.corDaPele;
}

PERSONAGEM setCorDosOlhos(PERSONAGEM novo)
{
	char* cpy = strdup(novo.file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 22; x++)
	{
		tmp = strtok(NULL,"'");
	}
	novo.corDosOlhos = strdup(tmp);
	return novo;
}

char* getCorDosOlhos(PERSONAGEM novo)
{
	return novo.corDosOlhos;
}

PERSONAGEM setAnoNascimento(PERSONAGEM novo)
{
	char* cpy = strdup(novo.file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 26; x++)
	{
		tmp = strtok(NULL,"'");
	}
	novo.anoNascimento  = strdup(tmp);
	return novo;
}

char* getAnoNascimento(PERSONAGEM novo)
{
	return novo.anoNascimento;
}

PERSONAGEM setGenero(PERSONAGEM novo)
{
	char* cpy = strdup(novo.file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 30; x++)
	{
		tmp = strtok(NULL,"'");
	}
	novo.genero  = strdup(tmp);
	return novo;
}

char* getGenero(PERSONAGEM novo)
{
	return novo.genero;
}

PERSONAGEM setHomeworld(PERSONAGEM novo)
{
	char* cpy = strdup(novo.file);
	char* tmp = strtok(cpy,":");
	for(int x = 0; x < 34; x++)
	{
		tmp = strtok(NULL,"'");
	}
	novo.homeworld  = strdup(tmp);
	return novo;
}

char* getHomeworld(PERSONAGEM novo)
{
	return novo.homeworld;
}

PERSONAGEM setAll(PERSONAGEM novo)
{
	novo = setNome(novo);
	novo = setAltura(novo);
	novo = setPeso(novo);
	novo = setCorDoCabelo(novo);	
	novo = setCorDaPele(novo);	
	novo = setCorDosOlhos(novo);	
	novo = setAnoNascimento(novo);	
	novo = setGenero(novo);
	novo = setHomeworld(novo);
	return novo;
}

void printAll(PERSONAGEM novo) //metodo que imprime todos os gets
{	
	printf(" ## %s",novo.nome);
	printf(" ## %d",novo.altura);
	if((novo.peso - (int)novo.peso) == 0)
	{
		printf(" ## %.0lf",novo.peso);
	}
	else{
		printf(" ## %.1lf",novo.peso);
	}
	printf(" ## %s",novo.corDoCabelo);
	printf(" ## %s", novo.corDaPele);
	printf(" ## %s", novo.corDosOlhos);
	printf(" ## %s", novo.anoNascimento);
	printf(" ## %s", novo.genero);
	printf(" ## %s ## \n", novo.homeworld);
}

bool isFim(char* s){
	return (strlen(s) >= 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M');
}


//=====================================================Fim Da Classe Personagem========================================================

typedef struct fila{
	PERSONAGEM array;
	int Tamanho;
}FILA;

int quantidade = 0;
int tamanho = 100;
int MAXTAM = 6;
int numEntrada = 0;
int primeiro, ultimo;
int soma = 0;
int comp = 0;
int mov = 0;

void start()
{
	primeiro = ultimo = 0;
}


PERSONAGEM remover(FILA fila[])
{
	PERSONAGEM resp = newPersonagem();
	if(primeiro == ultimo){
		printf("ERRO AO REMOVER - O ARRAY ESTA VAZIO");
		exit(1);
	}
	resp = clone(fila[primeiro].array);
	primeiro = (primeiro + 1) % MAXTAM;
	return resp;
}

void inserir(FILA fila[],PERSONAGEM personagem)
{
	if((ultimo+1) % MAXTAM == primeiro)
	{
		//printf("ERRO NA INSERCAO - O ARRAY ESTA CHEIO");
		remover(fila);
	}
	else{
		//fila[ultimo].array = lerArquivo(personagem, fila[ultimo].array);
		//fila[ultimo].array = setAll(fila[ultimo].array);
		ultimo = (ultimo + 1) % MAXTAM;
		quantidade++;
		for(int i = primeiro; i != ultimo; i = ((i+1) % MAXTAM))
		{
			soma += getAltura(fila[i].array);
		}
		printf("%d", soma/quantidade);
	}
}

void mostrar(FILA fila[])
{
	for(int i = primeiro; i != ultimo; i = ((i + 1) % MAXTAM))
	{
		printf("\n[%d] ",i);
		printAll(fila[i].array);
	}
}

int main(int argc, char** argv)
{
	char entrada[NUMENTRADA][TAMLINHA];
	char entrada2[NUMENTRADA][TAMLINHA];
	char* nome = (char*) malloc(sizeof(char*)*1000);
	int quant = 0;
	int numEntrada2 = 0;

	clock_t startTime = clock();

	//Ler todas as entradas
	do {
		fgets(entrada[numEntrada], TAMLINHA, stdin);
	} while (isFim(entrada[numEntrada++]) == false);
	numEntrada--;

	PERSONAGEM personagem[tamanho];
	FILA fila[tamanho];
	scanf("%d",&quant);
	start();

	for(int x = 0; x < numEntrada; x++)
	{
		//printf("NOME[%d] = %s\n",x,entrada[x]);
		nome = entrada[x];

		if(nome[strlen(nome) - 1] == '\n')
		{
			//printf("ENTREI NO LOOP. FILE = %s\n",nome);
			nome[strlen(nome) - 1] = '\0';	
		}
		//personagem[x] = newPersonagem();
		//personagem[x] = lerArquivo(nome,personagem[x]);
		//personagem[x] = setAll(personagem[x]);

		inserir(fila,nome);
	}

	do {
		fgets(entrada2[numEntrada2], TAMLINHA, stdin);
	} while (numEntrada2++ != quant);

	/*for(int x = 1; x < numEntrada2; x++)
	{
		//printf("FILE[%d] = %s\n",x,entrada2[x]);
		if(strstr(entrada2[x],"I /") != NULL)
		{
			nome = strstr(entrada2[x],"/");
			if(nome[strlen(nome) - 1] == '\n')
			{
				printf("ENTREI NO LOOP. FILE = %s\n",nome);
				nome[strlen(nome)-1] = '\0';	
			}
			personagem[x] = newPersonagem();
			  personagem[x] = lerArquivo(nome,personagem[x]);
			  personagem[x] = setAll(personagem[x]);
			//printf("%s\n",nome);
			//inserir(fila,personagem[x]);
		}
		//if(strstr(entrada2[x],"R ") != NULL && strstr(entrada2[x],"/" == NULL))
	}*/
}

