#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int valor;
	struct No* esquerda;
	struct No* direita;
}No;

void inserirNo(No**, int);
void exibirPre(No*);
void exibirIn(No*);
void exibirPos(No*);

int main()
{
	int c;   // N�mero de casos teste.
	int N;   // Quantidade de n�meros na �rvore.
	int n;   // N�mero que entrar� na �rvore.

	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		No* arvore = NULL;

		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &n);
			inserirNo(&arvore, n);
		}
		printf("Case %d:", i+1);
		printf("\nPre.:");
		exibirPre(arvore);

		printf("\nIn..:");
		exibirIn(arvore);

		printf("\nPost:");
		exibirPos(arvore);

		printf("\n\n");
		free(arvore);
	}

	return 0;
}

void inserirNo(No** arvore, int n)
{
	No* novo_no = (No*)malloc(sizeof(No));
	novo_no->valor = n;
	novo_no->esquerda = NULL;
	novo_no->direita = NULL;

	if (*arvore == NULL)
        *arvore = novo_no;
    else
    {
        if (n <= (*arvore)->valor)
            inserirNo(&(*arvore)->esquerda, n);
        else
        	inserirNo(&(*arvore)->direita, n);
    }
}

void exibirPre(No* arvore)
{
	if (arvore != NULL)
	{
		printf(" %d", arvore->valor);
		exibirPre(arvore->esquerda);
		exibirPre(arvore->direita);
	}
}

void exibirIn(No* arvore)
{
	if (arvore != NULL)
	{
		exibirIn(arvore->esquerda);
		printf(" %d", arvore->valor);
		exibirIn(arvore->direita);
	}
}

void exibirPos(No* arvore)
{
	if (arvore != NULL)
	{
		exibirPos(arvore->esquerda);
		exibirPos(arvore->direita);
		printf(" %d", arvore->valor);
	}
}