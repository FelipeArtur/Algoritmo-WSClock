#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
// definicao do working set (delta)
#define Delta 3

//Strut da pagina com seus parametros
struct pagina
{
	unsigned int id;
	unsigned int referencia;
	bool R;
};
typedef struct pagina Pagina;
//Struct do no que vai servir de apoio para apontar durante o codigo
struct no
{
	Pagina informacao;
	struct no *prox;
};
typedef struct no No;

typedef No *Clock;

unsigned int tempo = 1;
// Função de inicializar Clock
void inicializar_Clock(Clock *c)
{
	*c = NULL;
}

// gera um numero inteiro aleatorio entre 0 e o limite passado
unsigned int aleatorio(unsigned int x)
{
	return rand() % x;
}

// retorna o achar_tempo atual e o incrementa por um numero aleatorio entre 1 e 4
unsigned int achar_tempo()
{
	return tempo += aleatorio(5) + 1;
}






// Função de referenciar a pagina e quando a função terminar muda o bit R de 0 para 1
void referenciar_pag(Clock *c, unsigned int id)
{
	Clock aux = *c;
	// Utiliza o parametro id para encontrar a pagina desejada
	while (aux->informacao.id != id)
		aux = aux->prox;

	aux->informacao.R = true;
	aux->informacao.referencia = achar_tempo();
}

// Função de printar o Clock
void printar_Clock(Clock c)
{
	printf("PONTEIRO->(id: %d; ref: %d, R:%d)", c->informacao.id, c->informacao.referencia, c->informacao.R);
	Clock aux = c->prox;
	//loop para passar por todas as paginas do clock
	while (aux != c && aux != NULL)
	{
		printf(", (id: %d; ref: %d, R:%d)", aux->informacao.id, aux->informacao.referencia, aux->informacao.R);
		aux = aux->prox;
	}
	printf("\n");
}

// Funçao de subtuir pagina do WSClock
void substituir_pagina(Clock *c)
{
	unsigned int tempo = achar_tempo();
	unsigned int diferenca = tempo - Delta;
	Clock aux = *c;
	//Procura o frame que vai ser substituido
	do
	{
		
		if (aux->informacao.R)
			aux->informacao.R = false;
		else if (aux->informacao.referencia < diferenca)
		{
			//encontrou ele
			aux->informacao.referencia = tempo;
			aux->informacao.R = true;
			printf("pagina %d trocada\n", aux->informacao.id);
			*c = aux->prox;
			return;
		}
		aux = aux->prox;
	} while (aux != *c);

	// Não substituiu nenhum frame  então ele substituiu o primeiro frame 
	aux->informacao.referencia = tempo;
	aux->informacao.R = true;
	*c = aux->prox;
	printf("pagina %d trocada\n", aux->informacao.id);
}
// Função de inserir uma pagina no clock
void inserir_pagina(Clock *c, unsigned int id, unsigned int Referencia)
{
	No *aux_no = (No *)malloc(sizeof(No));
	//Parametro que ele recebe e inseri dados
	aux_no->informacao.id = id;
	aux_no->informacao.referencia = Referencia;
	aux_no->informacao.R = false;

	// Clock estah vazio
	if (*c == NULL)
	{
		aux_no->prox = NULL;
		*c = aux_no;
	}
	// Clock tem apenas um elemento
	else if ((*c)->prox == NULL)
	{
		// Insere no final da lista
		aux_no->prox = *c;
		(*c)->prox = aux_no;
	}
	// Clock tem mais de 1 elemento
	else
	{
		Clock aux = (*c)->prox;
		// Vai ate o ultimo elemento da lista
		while (aux->prox != *c)
			aux = aux->prox;

		// Insere no final da lista
		aux_no->prox = *c;
		aux->prox = aux_no;
	}
}
