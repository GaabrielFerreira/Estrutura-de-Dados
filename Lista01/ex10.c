/*
  Titulo: Exercicio10
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 21/02 as 20:11
  Detalhes: Implemente uma função que copie um vetor para um novo vetor alocado dinamicamente. O tamanho e o conteúdo do vetor original devem ser preservados. A
  função deve seguir o protótipo: int *copiaVetor(int *vet, int n);
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int *copiaVetor(int *vet, int n);

int main() {
    int vet[TAM];
    //Recebendo valores no vetor
    for(int i=0; i<TAM; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", (vet+i));
    }

    int *p = copiaVetor(vet, TAM);
    if(p != NULL) {
        printf("\nExibindo vetor copiado...\n");
        for(int i=0;i<TAM; i++)
            printf("%d\n", *(p+i));
        
        free(p);
    }
    else
        printf("Erro na alocacao de memoria");
}

int *copiaVetor(int *vet, int n) {
    int *aux = (int*)malloc(n*sizeof(int));
    if(aux==NULL) {
        printf("Erro na alocacao de memoria");
        return NULL;
    }

    for(int i=0;i<n;i++) {
      *(aux+i) = vet[i];
    }

    return aux;
}