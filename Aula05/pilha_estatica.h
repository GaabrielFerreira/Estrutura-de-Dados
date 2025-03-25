/****************************************************************
Prototipos e definicoes das operacoes sobre Pilhas
*****************************************************************/


/*Define o tamanho da pilha e estrutura*/
#define MAXPILHA 50

typedef char elem_t; /* Tipo do elemento */

typedef struct stack{
	 int topo; //Pilha vazia, topo = -1
	 elem_t item[MAXPILHA];
} Pilha;

/*Inicializa a pilha*/
void cria_pilha(Pilha *ps);
/*Verifica se a pilha esta vazia*/
int pilha_vazia(Pilha *ps);
/*Verifica se a pilha esta cheia*/
int pilha_cheia(Pilha *ps);
/*Adiciona um item na pilha*/
void insere_pilha(Pilha *ps, elem_t x);
/*Remove um item da pilha e retorna-o*/
elem_t remove_pilha(Pilha *ps);
/*Retorna o ultimo item da pilha*/
elem_t elem_topo(Pilha *ps);
/*Remove todos os elementos da pilha */
void libera_pilha(Pilha *ps);
