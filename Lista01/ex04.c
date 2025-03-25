/*
  Titulo: Exercicio04
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 19/02 as 12:39
  Detalhes: Crie uma função capaz de encontrar o menor valor em um vetor de inteiros. A
  função recebe um vetor e seu tamanho como entrada e retorna o menor número
  encontrado. Utilize este protótipo: int menorElemento(int *vet, int n);
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int menorElemento(int *vet, int n);

int main() {
    //Aloca memoria para o ponteiro
    int *p = (int*)malloc(TAM*sizeof(int));
    if(p==NULL) {
        printf("Erro ao alocar memoria");
        return 1;
    }

    for(int i=0; i<TAM; i++) {
        printf("Digite o numero %d: ", i+1);
        scanf("%d", (p+i));
    }

    printf("O menor numero digitado foi: %d", menorElemento(p, TAM));
    free(p);
}

int menorElemento(int *vet, int n) {
    int menor = *vet; /*Inicia "menor" como o primeiro valor do ponteiro, 
                      pois se nao tiver valores menores, ele fica como menor.*/

    //Verifica se algum outro valor do ponteiro e menor que o primeiro
    for(int i=0; i<n; i++)
        if(*(vet+i) < menor)
            menor = *(vet+i);

    return menor;
}