/*
  Titulo: Exercicio02
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 19/02 as 12:08
  Detalhes: Desenvolva uma função para calcular a soma dos elementos de um vetor. O vetor
  de inteiros e seu tamanho são passados como parâmetros, e a função retorna a soma
  de seus valores. Utilize o seguinte protótipo: int somaVetor(int *vet, int n);
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int somaVetor(int *vet, int n);

int main() {
    //Aloca memoria para o onteiros e verifica se a alocacao deu certo
    int *p = (int *)malloc(TAM * sizeof(int));
    if(p == NULL) {
        printf("Erro na alocacao de memoria");
        return 1;
    }

    //Recebe os valores de cada posicao do ponteiro
    for(int i=0; i<TAM; i++) {
        printf("Digite o valor %d: ", i+1);
        scanf("%d", (p+i));
    }

    printf("\nA soma dos valores digitados e de: %d", somaVetor(p, TAM));

    free(p);
}

int somaVetor(int *vet, int n) {
    //Soma todas as posicoes do ponteiro e retorna o valor
    int soma=0;
    for (int i=0; i<n; i++)
        soma += *(vet+i);
    
    return soma;
}