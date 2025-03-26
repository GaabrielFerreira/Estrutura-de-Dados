#include <stdio.h>
#include "pilha_estatica.h"

/*Inicializa a pilha*/
void cria_pilha(Pilha *ps){
    ps->topo=-1;
}

/*Verifica se a pilha esta vazia*/
int pilha_vazia(Pilha *ps) {
    if(ps->topo == -1)
        return 1; //Pilha vazia
    else
        return 0;
}

/*Verifica se a pilha esta cheia*/
int pilha_cheia(Pilha *ps) {
    if(ps->topo == MAXPILHA-1)
        return 1; //Pilha cheia
    else 
        return 0;
}

/*Adiciona um item na pilha*/
void insere_pilha(Pilha *ps, elem_t x) {
    if(pilha_cheia(ps)) 
        return;

    ps->topo++;
    int tam = ps->topo;
    ps->item[tam] = x;
}

/*Remove um item da pilha e retorna-o*/
elem_t remove_pilha(Pilha *ps) {
    int tam = ps->topo;
    elem_t aux = ps->item[tam];
    ps->topo--;

    return aux;
}

/*Retorna o ultimo item da pilha*/
elem_t elem_topo(Pilha *ps) {
    int tam = ps->topo;
    elem_t aux = ps->item[tam];

    return aux;
}

/*Remove todos os elementos da pilha */
void libera_pilha(Pilha *ps) {
    ps->topo = -1;
}