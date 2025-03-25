/*
  Titulo: Exercicio03
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 19/02 as 12:24
  Detalhes: Implemente uma função que copie uma string para outra. Usando ponteiros, a
  função deve transferir o conteúdo de uma string para outra. O protótipo a ser seguido
  é: void copiaString(char *dest, char *orig);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

void copiaString(char *dest, char *orig);

int main() {
    //Aloca memoria para os dois ponteiros e verifica se a alocacao deu certo
    char *ori = (char *)malloc(TAM * sizeof(char));
    char *dest = (char *)malloc(TAM * sizeof(char));
    if(ori == NULL || dest == NULL) {
        printf("Erro ao alocar memoria");
        return 1;
    }

    printf("Digite uma frase: ");
    scanf("%49s", ori);

    copiaString(dest, ori);

    printf("Frase copiada: %s", dest);

    free(ori);
    free(dest);
}


void copiaString(char *dest, char *orig) {
    strcpy(dest, orig); //Funcao para copiar um string para outra 
}