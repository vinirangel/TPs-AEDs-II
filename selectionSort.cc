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

typedef struct lista{
	PERSONAGEM array;
	int Tamanho;
}LISTA;

int quantidade = 0;
int tamanho = 100;
int numEntrada = 0;
int comp = 0;

void construirLista(char linha[][TAMLINHA], int numEntrada, LISTA lista[])
{
	for(int x = 0; x < numEntrada; x++)
	{
		lista[x].array = lerArquivo(linha[x],lista[x].array);
		lista[x].array = setAll(lista[x].array);
		quantidade++;
	}
}

void inserirInicio(LISTA lista[],PERSONAGEM personagem)
{
	if(quantidade < tamanho)
	{
		for(int x = quantidade; x > 0; x--)
		{
			lista[x].array = clone(lista[x-1].array);
		}
		lista[0].array = clone(personagem);
		quantidade++;
	}
	else{
		printf("\nO array esta cheio");
	}
}

void inserir(LISTA lista[],PERSONAGEM personagem,int pos)
{
	if(quantidade < tamanho)
	{
		for(int x = quantidade; x > pos; x--)
		{
			lista[x].array = clone(lista[x-1].array);
		}
		lista[pos].array = clone(personagem);
		quantidade++;
	}
	else{
		printf("\nO array esta cheio");
	}
}

void inserirFim(LISTA lista[],PERSONAGEM personagem)
{
	if(quantidade < tamanho)
	{
		lista[quantidade].array = clone(personagem);
		quantidade++;
	}
	else{
		printf("\nO array esta cheio");
	}
}

PERSONAGEM removerInicio(LISTA lista[])
{
	PERSONAGEM resp = clone(lista[0].array);
	setNome(resp);

	if(quantidade != 0)
	{
		quantidade--;
		for(int x = 0; x < quantidade; x++)
		{
			lista[x].array = clone(lista[x+1].array);
		}
	}
	return resp;
}

PERSONAGEM remover(LISTA lista[], int pos)
{
	PERSONAGEM resp = clone(lista[pos].array);

	if(quantidade > 0 && pos >= 0 && pos < quantidade)
	{
		quantidade--;

		for(int x = pos; x < quantidade; x++)
		{
			lista[x].array = clone(lista[x+1].array);
		}
		setNome(resp);
	}
	return resp;
}

PERSONAGEM removerFim(LISTA lista[])
{
	PERSONAGEM resp = clone(lista[quantidade].array);

	if(quantidade > 0)
	{
		quantidade--;
		lista[quantidade].array = setNome(lista[quantidade].array);
	}
	return lista[quantidade].array;
}

/*void sort(LISTA lista[],int i, int j, int size, int flag )
{
	PERSONAGEM tmp;

	if( i < size)
	{
		if(flag)
		{
			j = i + 1;
		}
		if(j < size)
		{
			if(strcmp( getNome(lista[i].array), getNome(lista[j].array)) > 0 )
			{
				tmp = clone(lista[i].array);
				lista[i].array = clone(lista[j].array);
				lista[j].array = clone(tmp);
			}
			sort(lista, i, j + 1, size, 0);
		}
		sort(lista, i + 1, 0, size, 1);
	}
}*/



void mostrarArray(LISTA lista[])
{
	for(int x = 0; x < quantidade; x++)
	{
		lista[x].array = setAll(lista[x].array);
	}

	for(int x = 0; x < quantidade; x++)
	{
		printf("[%d] ",x);
		printAll(lista[x].array);
	}
}

int main(int argc, char** argv)
{
	char entrada[NUMENTRADA][TAMLINHA];
	char entrada2[NUMENTRADA][TAMLINHA];
	char* nome = (char*) malloc(sizeof(char*)*1000);
	int numEntrada2 = 0;

	clock_t startTime = clock();

	//Ler todas as entradas
	do {
		fgets(entrada[numEntrada], TAMLINHA, stdin);
	} while (isFim(entrada[numEntrada++]) == false);
	numEntrada--;

	PERSONAGEM personagem[tamanho];
	LISTA lista[tamanho];
	construirLista(entrada,numEntrada,lista);

	sort(lista, 0 , 0 , quantidade, 1);
	mostrarArray(lista);
}
