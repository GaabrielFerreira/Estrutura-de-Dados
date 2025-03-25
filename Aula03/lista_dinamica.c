#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

/*
  Título: Lista Dinâmica (Simples Encadeada)
  Autores: Gabriel Ferreira RA: 236085
  Última modificação: 17/03 às 22:46
  Detalhes: Implementação das operações da TAD Lista com alocação dinâmica.
*/

// Inicializa a lista, tornando-a vazia
void cria(Lista *p_l) {
    *p_l = NULL;
}

// Verifica se a lista está vazia
int vazia(Lista *p_l) {
    if (*p_l == NULL)
        return 1;
    else 
        return 0;
}

// Insere um elemento no início da lista
void insere_inicio(Lista *p_l, elem_t e) {
    No_lista *novo = (No_lista*)malloc(sizeof(No_lista));
    novo->info = e;
    novo->prox = *p_l;  // Aponta para o antigo primeiro nó
    *p_l = novo;  // O novo nó passa a ser o primeiro
}

// Insere um elemento no final da lista
void insere_fim(Lista *p_l, elem_t e) {
    No_lista *no = (No_lista*)malloc(sizeof(No_lista)), *aux = *p_l;

    no->info = e;
    no->prox = NULL;

    if (aux == NULL) {  // Se a lista estiver vazia
        *p_l = no;
        return;
    }

    while (aux->prox != NULL)  // Percorre até o último nó
        aux = aux->prox;

    aux->prox = no;  // O último nó agora aponta para o novo nó
}

// Insere um elemento de forma ordenada na lista
int insere_ordenado(Lista *p_l, elem_t e) {
    No_lista *no = (No_lista*)malloc(sizeof(No_lista)), *aux = *p_l;
    no->info = e;
    no->prox = NULL;

    if (*p_l == NULL) {  // Lista vazia
        no->prox = *p_l;
        *p_l = no;
        return 1;
    }

    while (aux->prox != NULL && aux->prox->info < e)  // Encontra a posição correta
        aux = aux->prox;

    no->prox = aux->prox;
    aux->prox = no;
    return 1;
}

// Verifica se a lista está ordenada
int ordenada(Lista *p_l) {
    No_lista *aux = *p_l;

    while (aux != NULL && aux->prox != NULL) {
        if (aux->info > aux->prox->info) { // Se encontrar um elemento maior que o próximo, não está ordenada
            printf("Lista nao esta ordenada!");
            return 0;
        }
        aux = aux->prox;
    }

    printf("Lista esta ordenada!");
    return 1;  // A lista está ordenada
}

// Ordena a lista de forma crescente
void ordena(Lista *p_l) { //Nao consegui :(
    if (vazia(p_l)) 
        return;

    No_lista *i = *p_l, *j;
    int temp;

    while (i != NULL) {
        j = i->prox;
        while (j != NULL) {
            if (i->info > j->info) {  // Se os elementos estiverem fora de ordem, troca
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
            j = j->prox;
        }
        i = i->prox;
    }
}

// Remove o primeiro elemento da lista
int remove_inicio(Lista *p_l, elem_t *p_e) {
    if (vazia(p_l)) 
        return 0;

    No_lista *no = *p_l;
    *p_e = no->info;
    *p_l = no->prox;  // O segundo nó se torna o primeiro
    free(no);  // Libera a memória do nó removido
    return 1;
}

// Remove o último elemento da lista
int remove_fim(Lista *p_l, elem_t *p_e) {
    if (vazia(p_l)) 
        return 0; 

    No_lista *aux = *p_l, *no;

    if (aux->prox == NULL) {  // Se a lista tem apenas um elemento
        no = aux;
        *p_e = no->info;
        *p_l = NULL;  // Lista fica vazia
    } else {
        while (aux->prox->prox != NULL)  // Percorre até o penúltimo nó
            aux = aux->prox;

        no = aux->prox;
        *p_e = no->info;
        aux->prox = NULL;  // O penúltimo nó agora é o último
    }

    free(no);
    return 1;
}

// Remove um elemento específico da lista
int remove_valor(Lista *p_l, elem_t e) { //Nao consegui :(
    if (vazia(p_l)) 
        return 0;

    No_lista *aux = *p_l, *no;

    while (aux->prox != NULL && aux->prox->info != e)  // Encontra o nó com o valor
        aux = aux->prox;

    if (aux->prox == NULL) return 0;  // Se o valor não for encontrado

    no = aux->prox;
    aux->prox = no->prox;  // Remove o nó da lista
    free(no);
    return 1;
}

// Inverte a ordem dos elementos na lista
void inverte(Lista *p_l) { //Nao consegui :(
    if (vazia(p_l))
        return;

    No_lista *atual = *p_l, *anterior = NULL, *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *p_l = anterior;  // O último nó se torna o primeiro
}

// Libera toda a memória da lista
void libera(Lista *p_l) {
    No_lista *no;

    while (*p_l != NULL) {
        no = *p_l;
        *p_l = no->prox;
        free(no);  // Libera o nó
    }
}

// Exibe todos os elementos da lista
void exibe(Lista *p_l) {
    No_lista *no = *p_l;

    printf("\nExibindo lista...\nLista: ");
    while (no != NULL) {
        printf("%d ", no->info);
        no = no->prox;
    }
    printf("\n");
}
