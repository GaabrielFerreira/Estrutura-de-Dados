/*
  Titulo: Expressao Infixa para Posfixa
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 25/03 as 21:22
  Detalhes: Implemente em linguagem C o algoritmo que transforma uma expressão infixa em posfixa (visto em sala de aula). Este programa deve utilizar o TAD pilha, cuja operações estão definidas no arquivo pilha_estatica.h. A saída, isto é, a expressão posfixa, deve ser armazenada em uma lista estática, cujas operações estão definidas no arquivo lista_estatica.h.
    Considere:
        operandos: caracter de 'A' a 'Z';
        operadores: + - * / ^ (^ é o símbolo para potência).
        parênteses: ( )
        expressão infixa correta 
*/

#include <stdio.h>
#include "lista_estatica.h"
#include "pilha_estatica.h"

int main() {
    Pilha p;
    Lista l;
    char letras[26]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char operadores[5] = {'+', '-', '*', '/', '^'};
    char infixa[MAX];
    int aux; //1 para operando, 2 para operador, 3 para ( e 4 para )
    char aux2, aux3; //aux2 recebe posicao da expressao e aux3 recebe topo da pilha

    cria(&l);
    cria_pilha(&p);
    printf("Expressao infixa: ");
    fgets(infixa, MAX, stdin);

    int i=0, j;
    while(infixa[i] != '\0') {//Le todas as posicoes da expressao Infixa
        aux=0;
        aux2 = infixa[i];
        for(j=0; j<26; j++) {
            if(aux2 == letras[j]) //Verifica se é Operando
                aux = 1;
        }

        for(j=0; j<5; j++) {
            if(aux2 == operadores[j]) { //Verifica se é Operador
                aux = 2;
            } 
        }

        if(aux2 == '(') //Verifica se é (
            aux = 3;
        else if(aux2 == ')') //Verifica se é )
            aux = 4;

        switch(aux) {
            case 1: //SE FOR LETRA
                insere_fim(&l, aux2); //SAIDA
                break;
            case 2: //SE FOR OPERADOR
                aux3 = elem_topo(&p);
                switch(aux2) { //Verifica prioridade do operador (> ou >=)
                    case '+': ////Se entrada for + e topo da pilha for qualquer operador
                        if(aux3 == '-' || aux3 == '+' || aux3 == '*' || aux3 == '/' ||aux3 == '^') {
                            insere_fim(&l, aux3);
                            remove_pilha(&p);
                        }
                        break;
                    case '-': //Se entrada for - e topo da pilha for qualquer operador
                        if(aux3 == '-' || aux3 == '+' || aux3 == '*' || aux3 == '/' ||aux3 == '^') {
                            insere_fim(&l, aux3); //Topo da pilha vai pra saida
                            remove_pilha(&p); //Remove esse elem do topo
                        }
                        break;
                    case '*'://Se entrada for * e topo da pilha for *, / ou ^
                        if(aux3 == '*' || aux3 == '/' ||aux3 == '^') {
                            insere_fim(&l, aux3); //Topo da pilha vai pra saida
                            remove_pilha(&p); //Remove esse elem do topo
                        }
                        break;
                    case '/'://Se entrada for / e topo da pilha for /, * ou ^
                        if(aux3 == '*' || aux3 == '/' ||aux3 == '^') {
                            insere_fim(&l, aux3); //Topo da pilha vai pra saida
                            remove_pilha(&p); //Remove esse elem do topo
                        }
                        break;
                    case '^'://Se entrada for ^ e topo da pilha for ^
                        if(aux3 == '^') {
                            insere_fim(&l, aux3); //Topo da pilha vai pra saida
                            remove_pilha(&p); //Remove esse elem do topo
                        }
                        break;
                }

                //Independente do operador, insere na pilha
                insere_pilha(&p, aux2); 
                break;
            case 3: //SE FOR (
                insere_pilha(&p, '('); //EMPILHA
                break;
            case 4: //SE FOR )
                while(elem_topo(&p) != '(') { //DESEMPILHA ATE ENCONTRAR )
                    aux2 = remove_pilha(&p);
                    if(aux2 != '(') //Vai para saida se nao for (
                        insere_fim(&l, aux2);
                }

                remove_pilha(&p); //Remove o ) que sobrou na pilha
                break;
        }

        i++;
    }

    insere_fim(&l, remove_pilha(&p)); //Remove ultimo elem da pilha antes do \0
    printf("\n\nExpressao final (POSFIXA):\n");
    exibe(&l);
}