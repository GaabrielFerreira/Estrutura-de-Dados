/*
  Titulo: Exercicio05
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 19/02 as 13:20
  Detalhes: Elabore uma função que aloque dinamicamente um vetor de inteiros e o inicialize com um valor específico. A função recebe o tamanho do vetor e o valor de inicialização e retorna um ponteiro para o vetor criado. O protótipo a seguir deve ser utilizado: int *alocaVetor(int n, int valor);
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int *alocaVetor(int n, int valor);

int main() {
    //Aloca memoria para o ponteiro
    int *p = alocaVetor(TAM, 10);
    if(p == NULL) {
        printf("Erro na alocacao de memoria");
        return 1;
    }

    printf("Exibindo ponteiro...");
    for(int i=0; i<TAM; i++) {
        printf("\n%d", *(p+i));
    }
}

int *alocaVetor(int n, int valor) {
    int *vet = (int*)malloc(n * sizeof(int));
    if(vet == NULL) {
        printf("Erro ao alocar memoria");
        return NULL;
    }

    //Todas as posicoes do ponteiro recebem o valor "valor"
    for(int i=0; i<n; i++) {
        *(vet+i) = valor;
    }

    return vet;
}