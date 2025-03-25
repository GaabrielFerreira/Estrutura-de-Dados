/*
  Titulo: string.c
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 27/02 as 17:45
  Detalhes: Aplicacao das funcoes da biblioteca string.h e string.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main () {
    int opcao;
    char *s = (char*)malloc(TAM*sizeof(char));
    if(s == NULL) {
        printf("Erro na alocacao de memoria");
        return 1;
    }

    do{
        printf("\n\nMENU\n1 - Digitar string\n2 - Calcula tamanho da string\n3 - Comparar strings\n4 - Inverter string\n5 - SAIR\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nString: ");
                scanf("%49s", s);
                break;
            case 2:
                tamString(s);
                break;
            case 3:
                cmpString(s);
                break;
            case 4:
                inverteString(s);
                break;
            case 5:
                printf("Encerrando...");
                break;
        }
    }while(opcao!=5);

    return 0;
}