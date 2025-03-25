/*
  Titulo: Exercicio07
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 19/02 as 20:12
  Detalhes: Crie uma função que conte quantas vogais existem em uma string. A função recebe uma string e retorna o número de caracteres que são vogais (a, e, i, o, u). O protótipo correto é: int contaVogais(char *str);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
int contaVogais(char *str);

int main() {
    //Aloca memoria para o ponteiro
    char *frase = (char*)malloc(TAM * sizeof(char));
    if(frase == NULL) {
        printf("Erro na alocacao de memoria");
        return 1;
    }
    printf("Digite uma frase: ");
    scanf("%9s", frase);

    printf("\nTOTAL DE VOGAIS NA FRASE: %d", contaVogais(frase));
}

int contaVogais(char *str) {
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};
    int numVogais = 0;

    //Verifica se cada posicao do ponteiro eh vogal
    for(int i=0; i < TAM; i++) {
        for(int j=0; j < 5; j++)
            if(*(str+i) == vogais[j])
                numVogais++;
    }

    return numVogais;
}