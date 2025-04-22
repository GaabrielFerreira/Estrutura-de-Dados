/*
 * �rvores bin�rias de busca.
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int info; /* chave */
  struct no *esq, *dir;
} No;

typedef No* Arvore;

void cria_arvore(Arvore *p);

/* Percursos */
void inorder(Arvore p);
void preorder(Arvore p);
void postorder(Arvore p);
void largura(Arvore p);

/* Retorna 1 se a chave for encontrada */
int busca (Arvore p, int chave);

/* Retorna 1 se a chave for encontrada */
int n_rec_busca(Arvore p, int chave);

/* Retorna 0 se a chave for repetida */
int  insere(Arvore *p, int chave);

/* Retorna 0 se a chave for repetida */
/* Versao nao recursiva */
int  n_rec_insere(Arvore *p, int chave);

/*Funcao usada na remove_arv para encontrar o pai*/
No *encontra_pai(Arvore *p, int chave);

/* Retorna 0 se a chave nao for encontrada */
int remove_arv(Arvore *p, int chave);

/* Verifica se p eh uma arvore de busca */
int verifica_busca(Arvore p);

