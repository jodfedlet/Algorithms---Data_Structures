#include <stdio.h>
#include <stdlib.h>


typedef struct Elemento{
	
	int num;
	struct Elemento *prox;

}TElemento;

typedef struct Lista{

	TElemento *inicio;
	TElemento *fim;

}TLista;

void inicilizar_lista(TLista *Lista){

	Lista->inicio = NULL;
	Lista->fim = NULL;

}

void inserir_elemento(TLista *Lista){

	TElemento *novo;

	novo =(TElemento*) malloc(sizeof(TElemento));

	printf("DIGITE UM VALOR\n");
	scanf("%d", &novo->num);

	novo->prox = NULL;

	if(Lista->inicio == NULL){

		Lista->inicio = novo;
		Lista->fim = novo;

	}
	else{
		Lista->fim->prox = novo;
		Lista->fim = novo;
	}

}

void remover_elemento(TLista *Lista){

	int valor;
	TElemento *anterior,*atual;

	printf("INFORME O ELEMENTO A SER EXCLUIDO:  "); // excluir os elemetos
	scanf("%d",&valor);

	if (Lista->inicio == NULL){
		printf("**LISTA VAZIA**\n");

	}
	else{

		anterior = Lista->inicio;
		atual = Lista->inicio;

		while(atual !=NULL){

			if(atual->num == valor){

				if(atual == Lista->inicio){

					Lista->inicio = Lista->inicio->prox;
					free(atual);
					break;
				}

				else{

					if(atual == Lista->fim){

						Lista->fim = anterior;
					}

					anterior->prox = atual->prox;
					free(atual);
					break;
				} 

			}

			else{
				anterior = atual;
				atual = atual->prox;
			}

		}
	}



}



void apresentar_elemento(TLista *Lista){

	TElemento *aux;

	printf("\n--RELATORIO DE TODOS OS ELEMENTOS----\n");

	if(Lista->inicio == NULL){
		printf("**LISTA VAZIA**\n");	

	}
	else{

		aux = Lista->inicio;

		while(aux  != NULL){
			printf("  %d", aux->num);
			aux = aux->prox;

		}
		printf("\n--FIM DE LISTA--\n\n");
	}



}


int main(){

	TLista 	L1;

	inicilizar_lista(&L1);

	int op,num =1;


		while(num == 1){

		printf("\n\tOPCOES \n");
		printf("1 - INSERIR UM NOVO ELEMENTO\n");
		printf("2 - REMOVER UM ELEMENTO\n");
		printf("3 - LISTA TODOS OS ELEMENTOS\n");
		printf("0 - PARA SAIR\n\n");


		scanf("%d",&op);

		switch(op){

			case 1:
					inserir_elemento(&L1);
				break;

			case 2:
					remover_elemento(&L1);

				break;
		    case 3:
		    		apresentar_elemento(&L1);
		   
	    	   break;

	    	case 0:
	    			printf("TCHAU\n");
	    			num = 0;
	    		break;

	    	default: 
	    		printf("OPCAO INVALIDA\n");

		}

	}




	return 0;
}
