/*
  Titulo: Exercicio01
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 19/02 as 11:59
  Detalhes: Crie uma função que troque os valores de dois inteiros entre si. Para isso, a função deve receber dois ponteiros para inteiros e realizar a troca diretamente na memória. O protótipo da função é: void troca(int *a, int *b); 
*/


#include <stdio.h>

void troca(int *a, int *b);

int main () {
    int a = 5, b = 8;
    printf("Valores Iniciais...\n%d e %d", a, b);
    troca(&a, &b);
    printf("\n\nValores Finais...\n%d e %d", a, b);
}

void troca(int *a, int *b) {
    //Inverte os valores do ponteiro "a" e "b"
    int aux = *a;
    *a = *b;
    *b = aux;
}