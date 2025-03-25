/*
 * Implementacao de listas.
 */

#define MAX 50

typedef int elem_t;
typedef struct l{
  elem_t vet[MAX];
  int tam;
} Lista;

/* Inicializa uma lista */
void cria(Lista *p_l);

/* Verifica se a lista est� vazia ou nao */
int vazia(Lista *p_l);

/* Insere um elemento no inicio da lista */
void insere_inicio(Lista *p_l, elem_t e);

/* Insere um elemento no final da lista */
void insere_fim(Lista *p_l, elem_t e);

/* Insere um elemento na lista de maneira ordenada.
   Retorna 0 caso o elemento ja exista na lista. 
   Assume que a lista esta ordenada */
int insere_ordenado(Lista *p_l, elem_t e);

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l);

/* Ordena a lista */
void ordena(Lista *p_l);

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
int remove_inicio(Lista *p_l, elem_t *p_e);

/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia */
int remove_fim(Lista *p_l, elem_t *p_e);

/* Remove o numero de valor e.
   Retorna 0 caso este numero n�o tenha sido encontrado */
int remove_valor(Lista *p_l, elem_t e);

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l);

/* Remove todos os numeros da lista */
void libera(Lista *p_l);

/* Exibe o conteudo da lista */
void exibe(Lista *p_l);
