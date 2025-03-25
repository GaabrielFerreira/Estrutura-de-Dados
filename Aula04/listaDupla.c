#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

/* Inicializa uma lista */
void cria(Lista *p_l){
    *p_l = NULL;
}

/* Verifica se a lista está vazia ou não */
int vazia(Lista *p_l){
    if(*p_l == NULL)
        return 1;
    else
        return 0;
}

/* Insere um elemento no início da lista */
void insere_inicio(Lista *p_l, elem_t e){
    No_lista *no;
    no = (No_lista*)malloc(sizeof(No_lista));
    
    no->info = e;
    no->prox = *p_l;
    no->ant = NULL;

    //Se a lista nao esta vazia
    if(*p_l != NULL) //Necessario para que o antigo inicio da lista aponte para 
        (*p_l)->ant = no; //o novo inicio da lista, mantendo ant e prox atualizados
    

    *p_l = no; //Garante que o inicio da lista aponte para o atual primeiro no
}

/* Insere um elemento no final da lista */
void insere_fim(Lista *p_l, elem_t e){
    No_lista *no;
    no = (No_lista*)malloc(sizeof(No_lista));
    no->info = e;
    no->prox = NULL;

    //Se a lista estiver vazia
    if(vazia(p_l)) {
        no->ant=NULL; //ant é null pq o no sera o primeiro elem
        *p_l = no; //lista recebe a alteracao
        return;
    }
    //Se nao estiver vazia, percorre a lista ate o ultimo elem
    else { 
        No_lista *aux;
        aux = *p_l;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        
        aux->prox = no; //Ultimo elem que era NULL recebe no
        no->ant = aux; //ant do ultimo elem aponta para aux (que era o ultimo no)
    }
}

/* Insere um elemento na lista de maneira ordenada.
   Retorna 0 caso o elemento já exista na lista. 
   Assume que a lista está ordenada */
int insere_ordenado(Lista *p_l, elem_t e){
    No_lista *no;
    no = (No_lista*)malloc(sizeof(No_lista));
    no->info = e;

    if(vazia(p_l) || (*p_l)->info > e) //Se o numero for o menor da lista
        insere_inicio(p_l, e); //Sera inserido no inicio
    
    No_lista *aux;
    aux = *p_l;
    //Encontrar a posicao correta para inserir na ordem
    while(aux->prox != NULL && aux->prox->info < e) {
        if(aux->info == e) { //Se o numero ja estiver na lista, return 0
            printf("\nNumero ja esta na lista!");
            return 0;
        }
        aux = aux->prox;
    }


    no->prox = aux->prox; //Ajustes dos ponteiros
    no->ant = aux;

    if(aux->prox != NULL) //Se o num nao for o maior (prox NULL)
        aux->prox->ant = no; //ajusta o ponteiro do prox

    aux->prox = no;
    return 1;
}

/* Verifica se a lista está ordenada */
int ordenada(Lista *p_l){
    if(vazia(p_l) || (*p_l)->prox == NULL) //Se a lista esta vazia ou com apenas 1 elem
        return 1;
    
    No_lista *aux;
    aux = *p_l;
    
    //Percorre a lista procurando verificando se o prox é maior q o atual
    while(aux->prox != NULL) {
        if(aux->info > aux->prox->info) { //Se prox for maior, lista nao ordenada
            printf("Lista nao ordenada!");
            return 0;
        }
        aux = aux->prox;
    }

    printf("Lista esta ordenada!");
    return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l){ //Nao consegui :(
    if(vazia(p_l) || (*p_l)->prox == NULL) //Se a lista esta vazia ou com apenas 1 elem
        return;

    No_lista *no;
    int aux;

    do {
        aux = 0;
        no = *p_l;

        while (no->prox != NULL) {
            if (no->info > no->prox->info) {
                elem_t temp = no->info;
                no->info = no->prox->info;
                no->prox->info = temp;
                aux = 1;
            }
            no = no->prox;
        }
    } while (aux);
}

/* Remove o elemento que está no início da lista.
   Retorna 0 caso a lista esteja vazia */
int remove_inicio(Lista *p_l, elem_t *p_e){
    if(vazia(p_l))
        return 0;
    
    *p_e = (*p_l)->info; //Salva o primeiro valor
    *p_l = (*p_l)->prox; //Atualiza a lista para o segundo (atual primeiro)

    if(*p_l != NULL) //Se a lista tiver mais que 1 elem
        (*p_l)->ant = NULL; //ant do atual 1 elem, recebe NULL

    return 1;
}

/* Remove o elemento que está no final da lista.
   Retorna 0 caso a lista esteja vazia */
int remove_fim(Lista *p_l, elem_t *p_e){
    if(vazia(p_l))
        return 0;

    No_lista *aux;
    aux = *p_l;
    while(aux->prox != NULL) //Percorre a lista ate o ultimo elem
        aux = aux->prox;

    *p_e = aux->info; //Salva o ultimo elem

    if(aux->ant != NULL) //Se a lista tiver mais que 1 elem
        aux->ant->prox = NULL; //Ajusta o prox do penultimo (atual ultimo) pra NULL
    else //Se era o unico elem, lista fica vazia
        *p_l = NULL;

    return 1;
}

/* Remove o nó de valor e.
   Retorna 0 caso este nó não tenha sido encontrado */
int remove_valor(Lista *p_l, elem_t e){
    if(vazia(p_l))
        return 0;

    No_lista *aux;
    aux = *p_l;

    //Encontra elem a ser removido
    while(aux != NULL && aux->info != e) 
        aux = aux->prox;

    if(aux == NULL) //Elem nao encontrado na lista para remover
        return 0;
    
    if(aux->ant != NULL) //Se o ant do elem removido nao for NULL, ajusta pont
        aux->ant->prox = aux->prox;

    if(aux->prox != NULL) //Se o prox do elem removido nao for NULL, ajusta pont
        aux->prox->ant = aux->ant;
    
    return 1;
}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l){ //Nao consegui :(
    if(vazia(p_l) || (*p_l)->prox == NULL) //Se a lista esta vazia ou com apenas 1 elem
        return;
    
    No_lista *aux, *no = NULL;
    aux = *p_l;
    
    while(aux != NULL) {
        no = aux->ant;
        aux->ant = aux->prox;
        aux->prox = no;

        aux = aux->ant; 
    }

    if (no != NULL)
        *p_l = no->ant;
}

/* Remove todos os nós da lista */
void libera(Lista *p_l){
    No_lista *aux, *no;
    aux = *p_l;
    while(aux != NULL) {
        no = aux;
        aux = aux->prox;
        free(no);
    }

    *p_l = NULL;
}

/* Exibe o conteúdo da lista */
void exibe(Lista *p_l){
    No_lista *no = *p_l;

    printf("\nExibindo lista...\nLista: ");
    while (no != NULL) {
        printf("%d ", no->info);
        no = no->prox;
    }
    printf("\n");
}
