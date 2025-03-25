/*Titulo: Altera Valores de Venda (Vetor Alocado Dinamicamente)
  Autores: Gabriel Ferreira RA: 236085
  Ultima modificacao: 18/02/2025 - 20:27
  Descricao: O código recebe os dados do arquivo Produtos-10.csv em vetor alocado dinamicamente (ponteiro), exibe o ponteiro e depois utilizando a funcao alteraCusto, altera o valor de venda dos produtos para 1.5 x valor de custo (apenas no ponteiro, sem reescrever no arquivo), porem, se o valor de custo for 0, o usuario escolhe o valor de venda*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

// criar a estrutura de acordo com as informacoes do arquivo
typedef struct{
    int ID;
    char DescricaoDoProd[100];
    float prVenda, prCusto;
 }Produto;

 // altera o valor de venda para 1.5 valor de custo. Cuidado com produtos que tem custo 0 (nesse caso, perguntar o valor de venda)
void alteraCusto (Produto *p, int tam){
    for(int i=0; i<tam; i++) {
        if((p+i)->prCusto==0) {
            printf("\nProduto %d com valor de custo 0\n", i+1);
            printf("Qual valor de venda dele? R: ");
            scanf("%f", &(p+i)->prVenda);
        }
        else {
            (p+i)->prVenda = (p+i)->prCusto * 1.5;
        }
    }
}

int main() {

    // criar um vetor estatico e um vetor alocado dinamicamente do tipo Produto
    Produto *p = (Produto *)malloc(TAM * sizeof(Produto));
    if (p == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    int numLinhas, i;

    FILE *file = fopen("Produtos-10.csv", "r");
    if (!file) {
        fprintf(stderr, "Nao foi possivel ler o arquivo Produtos-teste.csv\n");
        return 1;
    }

    numLinhas = 0;
    while (!feof(file)) {
        // preencher com a leitura no vetor
        fscanf(file, "%d;%63[^;];%f;%f\n", &(p+numLinhas)->ID, (p+numLinhas)->DescricaoDoProd, &(p+numLinhas)->prVenda, &(p+numLinhas)->prCusto);
        
        numLinhas++;
    }


    //checando a leitura do arquivo
    for (i = 0; i < numLinhas; i++)
        // preencher para imprimir o arquivo lido
        printf("%d %s  %.2f  %.2f \n", (p+i)->ID, (p+i)->DescricaoDoProd, (p+i)->prVenda, (p+i)->prCusto);

    alteraCusto(p, numLinhas);

    printf("\nVALORES ALTERADOS...\n");
    for (i = 0; i < numLinhas; i++)
        printf("%d %s  %.2f  %.2f \n", (p+i)->ID, (p+i)->DescricaoDoProd, (p+i)->prVenda, (p+i)->prCusto);

    fclose(file);
    return 0;
}