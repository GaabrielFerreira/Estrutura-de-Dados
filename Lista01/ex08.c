/*
  Titulo: Exercicio08
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 20/02 as 13:48
  Detalhes: Implemente uma função para concatenar duas strings. A segunda string deve ser
  anexada ao final da primeira. Utilize o seguinte protótipo: void concatenaString(char
  *dest, char *orig);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 25

void concatenaString(char *dest, char *orig);

int main() {
    //Aloca memoria para os dois ponteiros e verifica se a alocacao deu certo
    char *str1 = (char*)malloc((TAM*2)*sizeof(char));
    char *str2 = (char*)malloc((TAM)*sizeof(char));
    if(str1 == NULL || str2 == NULL) {
        printf("Erro ao alocar memoria");
        return 1;
    }

    printf("Frase 1: ");
    scanf("%24s", str1);
    printf("Frase 2: ");
    scanf("%24s", str2);

    concatenaString(str1, str2);

    free(str1);
    free(str2);
}

void concatenaString(char *dest, char *orig) {
    int i=strlen(dest);

    printf("\n\nFrase 1 + Frase 2:\n%s+%s = ", dest, orig);
    //Inicia o destino em sua ultima posicao e vai adicionando a origem e o \0 no final
    for(int j=0; j < ((int)strlen(orig)); i++, j++) {
        *(dest+i) = *(orig+j);
    }
    *(dest+i) = '\0';

    printf("%s", dest);
}