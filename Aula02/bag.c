/*
 * bag.c - implementacao das operacoes realizadas na sacola
 * Autora: Tiemi C. Sakata
 */

#include <stdio.h>
#include "bag.h"

void init(Bag *b){
    for(int i=0;i<BAGSIZE; i++)
        *(b->item+i) = -1;
}

int size(Bag *b){
    int count=0;

    for(int i=0; i<BAGSIZE; i++)
        if(*(b->item+i) != -1)
            count++;

    return count;
}

/* insere elemento e retorna 1 em caso de sucesso ou 0 caso contrario. */
int insert(Bag *b, int elem){
    for(int i=0; i<BAGSIZE; i++) {
        if(*(b->item+i)==-1) {
            *(b->item+i) = elem;
            return 1;
        }
    }

    return 0;
}

int check(Bag *b, int elem){
    int count=0;
    for(int i=0; i<BAGSIZE; i++) {
        if(*(b->item+i) == elem)
            count++;
    }

    if(count==0)
        return 0;
    else
        return count;
}

/* remove elemento e retorna 1 em caso de sucesso ou 0 caso contrario. */
int delete(Bag *b, int elem){
    int aux;
    for(int i=0; i<BAGSIZE; i++) {
        if(*(b->item+i) == elem) {
            *(b->item+i) = -1;
            for(int j=i; j<BAGSIZE-1; j++) {
                if(*(b->item+j) == -1) {
                    aux = *(b->item+j);
                    *(b->item+j) = *(b->item+j+1);
                    *(b->item+j+1) = aux;
                }
            }
            
            return 1;
        }
    }

    return 0;
}


void printall(Bag *b){
    printf("\nProdutos na mochila:");
    for(int i=0; i<BAGSIZE; i++) {
        if(*(b->item+i) != -1)
            printf(" %d;", *(b->item+i));
    }
}