#include<stdio.h>
#include"bag.h"

int main()
{
	Bag carrinho;
	int op, item;

	init(&carrinho);

	// mostre os produtos para o cliente

	do {
		printf("\n\nStatus do carrinho");
		printall(&carrinho);
		printf("\n");

		printf("1. Adicionar produto \n2. Remover produto \n3. Checar se um produto esta no carrinho \n4. Checar o numero de produtos no carrinho \n5. Zerar produtos no carrinho \n6. Finalizar a compra \nEscolha uma opcao: ");

		scanf("%d", &op);

		switch (op){
		case 1:
			printf("Produto a comprar: ");
			scanf("%d", &item);
			insert(&carrinho, item);
			break;
		case 2:
			printf("Produto a remover do carrinho: ");
			scanf("%d", &item);
			delete(&carrinho, item);
			break;
		case 3:
			printf("Produto a verificar: ");
			scanf("%d", &item);
			if (check(&carrinho, item))
				printf ("Produto %d esta no carrinho %d vezes\n", item, check(&carrinho, item));
			else
				printf("Nao encontrei o produto no carrinho\n");
			break;
		case 4:
			printf("Num de produtos no carrinho:");
			printf("%d\n", size(&carrinho));
			break;
		case 5:
			init(&carrinho);
			break;
		
		}
	}while(op != 6);

	return 0;
}