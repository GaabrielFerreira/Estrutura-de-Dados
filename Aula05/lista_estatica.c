#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

// Inicializa a lista, definindo seu tamanho como 0
void cria(Lista *p_l) {
    p_l->tam = 0;
}

// Verifica se a lista está vazia
// Retorna 1 se estiver vazia, 0 caso contrário
int vazia(Lista *p_l) {
    if(p_l->tam == 0)
        return 1;
    else 
        return 0;
}

// Insere um elemento no início da lista
// Move todos os elementos para frente para abrir espaço
void insere_inicio(Lista *p_l, elem_t e) {
    if (p_l->tam == MAX) { // Verifica se a lista está cheia
        printf("Lista cheia!\n");
        return;
    }

    for(int i = p_l->tam; i>0; i--) { // Move os elementos para frente
        p_l->vet[i] = p_l->vet[i-1];
    }

    p_l->tam++;
    p_l->vet[0] = e; // Insere o elemento na primeira posição
}

// Insere um elemento no final da lista
void insere_fim(Lista *p_l, elem_t e) {
    if (p_l->tam == MAX) { // Verifica se a lista está cheia
        printf("Lista cheia!\n");
        return;
    }

    int aux = p_l->tam; // Pega a posição onde o novo elemento será inserido

    p_l->tam++;
    p_l->vet[aux] = e; // Insere o elemento no final da lista
}

// Insere um elemento de forma ordenada na lista
int insere_ordenado(Lista *p_l, elem_t e) {
    if (p_l->tam == MAX) { // Verifica se a lista está cheia
        printf("Lista cheia!\n");
        return 0;
    }

    int aux = p_l->tam;

    // Verifica se o número já existe na lista
    for (int i = 0; i < aux; i++) {
        if (p_l->vet[i] == e) {
            printf("\nNumero %d ja existe na lista na posicao %d!", e, i);
            return 0;
        }
    }

    // Encontra a posição correta para inserir mantendo a ordem
    for (int i = 0; i < aux; i++) {
        if (e < p_l->vet[i]) {
            // Move os elementos para frente para abrir espaço
            for (int j = aux; j > i; j--) {
                p_l->vet[j] = p_l->vet[j - 1];
            }
            // Insere o número na posição correta
            p_l->tam++;
            p_l->vet[i] = e;
            return 1;
        }
    }

    // Se for maior que todos os elementos, insere no final
    p_l->vet[aux] = e;
    p_l->tam++;
    return 1;
}

// Verifica se a lista está ordenada
int ordenada(Lista *p_l) {
    int aux = p_l->tam;
    
    for(int i=0; i<aux-1; i++) { //aux-1 para nao acessar posição inválida apos a ultima
        if(p_l->vet[i] > p_l->vet[i+1]) {
            printf("Lista nao ordenada!");
            return 0;
        }
    }

    printf("Lista esta ordenada!");
    return 1;
}

// Ordena a lista
void ordena(Lista *p_l) {
    int aux = p_l->tam;
    int tmp;

    //Move o maior numero para a respectiva posicao, por exemplo,
    //i=0 -> maior num vai pra ultima posicao
    //i=1 -> 2 maior num vai pra penultima posicao, etc...
    for(int i=0; i<aux-1; i++) { //
        for(int j=0; j<aux-1; j++) {
            if(p_l->vet[j] > p_l->vet[j+1]) { // Troca se estiver fora de ordem
                tmp = p_l->vet[j];
                p_l->vet[j] = p_l->vet[j + 1];
                p_l->vet[j + 1] = tmp;
            }
        }
    }
}

// Remove o primeiro elemento da lista
int remove_inicio(Lista *p_l, elem_t *p_e) {
    int aux = p_l->tam;
    if(vazia(p_l)) // Verifica se a lista está vazia
        return 0;

    *p_e = p_l->vet[0]; // Salva o primeiro elemento

    // Move os elementos para trás
    for(int i=0; i<aux-1; i++)
        p_l->vet[i] = p_l->vet[i+1]; 
    
    p_l->tam--; // Atualiza o tamanho da lista
    return 1;
}

// Remove o último elemento da lista
int remove_fim(Lista *p_l, elem_t *p_e) {
    int aux = p_l->tam;
    if(vazia(p_l))
        return 0;

    *p_e = p_l->vet[aux-1]; // Obtém o último elemento
    p_l->tam--; // Reduz o tamanho da lista
    return 1;
}

// Remove um elemento específico da lista
int remove_valor(Lista *p_l, elem_t e) {
    int aux = p_l->tam;
    if(vazia(p_l))
        return 0;

    // Procura o número na lista
    for(int i=0; i<aux; i++) {
        if(p_l->vet[i] == e) {
            // Move todos os elementos para trás
            for(int j=i; j<aux-1; j++)
                p_l->vet[j] = p_l->vet[j+1];            
            
            p_l->tam--; // Atualiza o tamanho da lista
            return 1;
        }
    }

    return 0; // Número não encontrado
}

// Inverte a ordem dos elementos da lista
void inverte(Lista *p_l) {
    int num, aux = p_l->tam;
    if(vazia(p_l))
        return;

    // Troca os elementos do início com os do final
    for(int i=0; i < aux/2; i++) {
        num = p_l->vet[i];
        p_l->vet[i] = p_l->vet[aux-1-i];
        p_l->vet[aux-1-i] = num;
    }
}

// Esvazia a lista
void libera(Lista *p_l) {
    p_l->tam=0; // Define o tamanho da lista como zero
}

// Exibe os elementos da lista
void exibe(Lista *p_l) {
    if(vazia(p_l))
        return;
        
    int aux = p_l->tam;
    for(int i=0; i<aux; i++) {
        printf("%c", p_l->vet[i]);
    }
}
