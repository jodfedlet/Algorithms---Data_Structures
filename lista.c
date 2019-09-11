#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 100

typedef struct produto{
	int codigo;
	char nome[TAM];
	float preco;

}tp_produto;



typedef struct nodo{
	tp_produto produto;
	struct nodo *prox

}tp_nodo;

tp_nodo * push(tp_nodo *nod){

	tp_nodo *novo = (tp_nodo*)malloc(sizeof(tp_nodo));
 	int cod;
	char nom[TAM];
	float preco;
	printf("Informe o codigo : ");
	scanf("%d",&cod);

	novo->produto.codigo = cod;
	printf("Informe o nome : ");
	getchar();
	fgets(nom,TAM,stdin);

	strcpy(novo->produto.nome,nom);
	printf("Informe o preco : ");
	scanf("%f",&preco);
	novo->produto.preco = preco;
	
	novo->prox = nod;
	return novo;
}

/*void pop(tp_nodo *nod){
	
	while( nod != NULL){
	
		nod = nod->prox

	}




}*/

void dispay(tp_nodo *nod){
	int i;
	//if(nod == NULL){ printf("Lista vazia");}


	for(nod =  ; nod != NULL;nod = nod->prox)




}

int main(){
	int op;
	
	tp_nodo *nod = NULL;
	

	
	do{
		// menu contendo as opçoes
		puts("________________________________________________");
		printf("		 *** MENU ***			\n");
		puts("________________________________________________");
		puts("1- Inserir um produdo na lista");
		puts("2- Excluir um elemento da ista");
		puts("3- Listar todos os campos dos elementos da lista");
		puts("0- Finalizar o programa");
		printf("Informe a sua opcao: ");
		scanf("%d",&op);
		printf("\n");
		if(op == 1){
					nod = push(nod);
					printf("\n");
		}else if(op == 2){
					//nod = pop(nod);	
					printf("\n");
					
		}else if(op == 3){
					//display(nod);
					printf("\n");
		}else printf("Opcao invalida!\n");
					printf("\n");

	}while(op != 0);
	
	return 0;
}
