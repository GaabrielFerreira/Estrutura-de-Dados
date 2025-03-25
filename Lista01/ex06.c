/*
  Titulo: Exercicio06
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 19/02 as 19:52
  Detalhes: Desenvolva uma função para inverter a ordem dos elementos de um vetor. O vetor deve ser modificado diretamente, sem criar uma cópia auxiliar. A assinatura da função deve ser: void inverteVetor(int *vet, int n);
*/

#define TAM 6

#include <stdio.h>
#include <stdlib.h>

void inverterVetor(int *vet, int n);

int main() {
    //Aloca memoria para o ponteiro
    int *p = (int*)malloc(TAM*sizeof(int));
    if(p == NULL) {
        printf("Erro na alocacao de memoria");
        return 1;
    }

    //Recebe valores para o ponteiro
    for(int i=0; i < TAM; i++) {
        printf("Digite o valor %d: ", i+1);
        scanf("%d", (p+i));
    }

    //Exibe ponteiro digitado
    printf("\nExibindo ponteiro...");
    for(int i=0; i < TAM; i++)
        printf("\n%d", *(p+i));

    inverterVetor(p, TAM);

    //Exibe ponteiro com valores invertido
    printf("\nExibindo ponteiro invertido...");
    for(int i=0; i < TAM; i++)
        printf("\n%d", *(p+i));
}

void inverterVetor(int *vet, int n) {
    int aux;
    for(int i=0; i < n/2; i++) { // n/2 para ele fazer as operacoes com a metade do tam
        aux = *(vet+i);          //do ponteiro, ex 1 2 3 4 5 6:
        *(vet+i) = *(vet+n-1-i); //                6 2 3 4 5 1 - i = 0
        *(vet+n-1-i) = aux;      //                6 5 3 4 2 1 - i = 1 
    }                            //                6 5 4 3 2 1 - i = 2 (Encerra o for)
}