/*
  Titulo: Exercicio09
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 20/02 as 20:17
  Detalhes: Desenvolva uma função que localize a primeira ocorrência de um número em um
  vetor. Caso o número esteja presente, a função retorna o índice correspondente; caso
  contrário, retorna em -1. O protótipo correto é: int buscaNumero(int *vet, int n, int num);
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int buscaNumero(int *vet, int n, int num);

int main() {
    int num;
    int *p = (int*)malloc(TAM*sizeof(int));

    if(p == NULL) {
        printf("Erro ao alocar memoria");
        return 1;
    }

    for(int i=0; i<TAM; i++) {
        printf("Digite numeros: ");
        scanf("%d", (p+i));
    }

    printf("Digite numero a ser buscado: ");
    scanf("%d", &num);

    if(buscaNumero(p, TAM, num)!=-1) {
        printf("\nO numero %d esta no vetor na posicao: %d", num, buscaNumero(p, TAM, num));
    }
    else
        printf("\nO numero %d nao esta presente no vetor", num);
}

int buscaNumero(int *vet, int n, int num) {

    for(int i=0; i<n; i++) {
        if(*(vet+i) == num) {
            return i;
        }
    }
    return -1;
}
