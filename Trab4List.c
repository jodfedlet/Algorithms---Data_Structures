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
	struct nodo *prox;

}tp_nodo;

tp_nodo * push(tp_nodo *nod){

	tp_nodo *novo = (tp_nodo*)malloc(sizeof(tp_nodo));
 	
	printf("Informe o codigo : ");
	scanf("%d",&novo->produto.codigo);

	printf("Informe o nome : ");
	getchar();
	fgets(novo->produto.nome,TAM,stdin);


	printf("Informe o preco : ");
	scanf("%f",&novo->produto.preco);
	
	novo->prox = nod;
	return novo;
}

tp_nodo *pop(tp_nodo *nod){
	int cod;
	tp_nodo *atual, *anterior;

	if( nod == NULL){
		 printf("Lista vazia");
	}else{
		
		anterior = NULL;

		printf("Informe o codigo a ser removido: ");
		scanf("%d",&cod);

		for( atual = nod; atual != NULL; atual = atual->prox ){
			if(atual->produto.codigo == cod){
				if(atual == nod){
					nod = nod->prox;
					free(atual);
					return nod;
					
				}
				else{
					anterior->prox = atual->prox;
					free(atual);
					return nod;
				

				}

			}
			anterior = atual;
		}
	}
	
	


}

void display(tp_nodo *nod){

	tp_nodo *p;

	if(nod == NULL){ 
		printf("Lista vazia");
	}else{

		for(p = nod  ; p != NULL;p = p->prox){
		puts("________________________________________________");
		printf("Codigo: %d\nNome: %sPreco: %.2f\n",p->produto.codigo,p->produto.nome,p->produto.preco);
		puts("________________________________________________");
		}
		
		printf("\n\n");
	}

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
					nod = pop(nod);	
					printf("\n");
					
		}else if(op == 3){
					display(nod);
					printf("\n");
		}else printf("Opcao invalida!\n");
					printf("\n");

	}while(op != 0);
	
	return 0;
}
