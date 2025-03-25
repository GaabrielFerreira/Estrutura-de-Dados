/*
  Titulo: string.c
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 26/02 as 21:33
  Detalhes: Implementacoes das funcoes da biblioteca string.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

void tamString(char *s) {
    int count1 = 0; //Conta letras
    int count2 = 0; //Conta espacos
    int t = strlen(s);

    for(int i=0; i<t; i++) {
        if(*(s+i) == ' ')
            count2++;
        else
            count1++;
    }

    if(count1 == 0) {
        printf("\nString nao informada!");
        return;
    }

    printf("%s possui %d letras e %d espacos", s, count1, count2);
}

void cmpString(char *s) {
    char *string2 = (char*)malloc(TAM*sizeof(char));
    if(string2 == NULL) {
        printf("Erro na alocacao de memoria");
        return;
    }

    printf("String 2: ");
    scanf("%49s", string2);
    
    for(int i=0;i<TAM; i++) {
        if(*(s+i) != *(string2 +i)) {
            printf("\nAs strings digitadas sao diferentes");
            return;
        }
    }

    printf("\nAs strings digitadas sao iguais");
}

void inverteString(char *s) {
    char aux;
    int t = strlen(s);

    for(int i=0; i<t/2; i++) {
        aux = *(s+i);
        *(s+i) = *(s+TAM-i-1);
        *(s+TAM-i-1) = aux;
    }

    printf("String invertida com sucesso!\nString: %s\n", s);
}