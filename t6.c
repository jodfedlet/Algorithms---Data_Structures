#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct _produto{
	int codigo;
	char nome[20];
	float preco;

}TpProduto;



typedef struct _nodo{
	TpProduto info;
	struct _nodo *next;
	struct _nodo *prev;
}TpNodo;

typedef struct _lista{
	int nItens;
	TpNodo *first;
	TpNodo *last;
}TpLista;

void push(TpLista *list){

	TpNodo *novo = (TpNodo*)malloc(sizeof(TpNodo));
 	
	printf("Codigo : ");
	scanf("%d",&novo->info.codigo);

	printf("Nome : ");
	getchar();
	fgets(novo->info.nome,20,stdin);


	printf("Preco : ");
	scanf("%f",&novo->info.preco);
	
	novo->next = NULL;
	novo->prev = NULL;
	if(list->first == NULL){
   			list->first = novo;
	 		list->last = novo;
	
	}else{

	 	novo->next = list->first;
	 	list->first->prev = novo;
	 	list->first = novo;

	 
    }
}
void pop(TpLista *list){
	int cod;
	TpNodo *d;

	if(list->first == NULL){
		printf("Lista vazia\n");
	}
	else{
		d = list->first;
		printf("Digite o codigo a ser removido: ");
		scanf("%d",&cod);
		for( ;d != NULL; d = d->next){
		  if(d->info.codigo == cod){
		  		if(list->first == list->last){
		  		   list->first = NULL;
		  			list->last = NULL;
		  			list->nItens--;
		  
		  		}else if(d->prev == NULL){ //primeiro da lista
						list->first = list->first->next;
						list->first->prev = NULL;
		  		}else if(d->next == NULL){
		  				list->last = list->last->prev;
		  				list->last->next = NULL;
				}else{ 
						d->next->prev = d->prev;
						d->prev->next = d->next;
		  		}
			}
		}
	}
	
}

void display(TpLista *list){

	 TpNodo *p;

	if(list->first == NULL){ 
		printf("Lista vazia\n");
	}
	else{

		for(p = list->first  ; p != NULL;p = p->next){
			
			printf("CODIGO------: %d\n",p->info.codigo);
			printf("NOME--------: %s",p->info.nome);
			printf("PRECO-------: %.2f\n",p->info.preco);
			printf("\n\n");
		}
		
		printf("\n\n");
	}

}
void insertionSort(TpLista *list){
	TpNodo *i,*j,*aux,*first,*last,*aux2;


	if(list->first == NULL){
		printf("Lista vazia\n");
	}
	else{
		first = list->first;
		last = list->last;
	
		for(i = first->next ; i != NULL; i = i->next){
				for(j = i->prev; j!= NULL;j = j->prev){
					
					if(i->info.codigo < j->info.codigo){
	 					aux = i;
						aux2 = j;
					}
				}
				if(aux2 == first && aux == last){
			
						aux2->next = aux->next;
						aux->prev = aux2->prev;
						aux->next = aux2;
						aux2->prev = aux;
						first = aux;
						last = aux2;
						first->next = NULL;
						last->prev = NULL;
				
				}else if(aux2 == first && aux != last){
				
						aux2->next = aux->next;
						aux->prev = aux2->prev;
						aux->next = aux2;
						aux2->prev = aux;
						first = aux;		
						first->prev = NULL;
				
				}else if(aux2 != first && aux == last){
				
						aux2->next = aux->next;
						aux->prev = aux2->prev;
						aux->next = aux2;
						aux2->prev = aux;
						last = aux2;
						last->next = NULL;
					
				}else{
						if(aux2->prev != NULL) aux2->prev->next = aux;
						if(aux->next != NULL)aux->next->prev = aux2;
						aux2->next = aux->next;
						aux->prev = aux2->prev;
						aux2->prev = aux;
						aux->next = aux2;			
			
				}
				
			  }    
			
		}
	

	} 
}

int main(){
	int op;
	
	TpLista *list =(TpLista*) malloc(sizeof(TpLista));
	 list->first = NULL;
	 list->last = NULL;
	 list->nItens = 0;
	
	do{
		// menu contendo as opçoes
		
		printf("          >== MENU ==<			\n\n");
		
		puts("1- INSERIR UM PRODUTO NA LISTA");
		puts("2- EXCLUIR UM PRODUTO NA LISTA");
		puts("3- LISTA OS CAMPOS DOS ELEMENTOS DA LISTA");
		puts("4- ORDENAR VIA INSERTION SORT");
		puts("5- ORDENAR VIA SELECTION SORT");
		puts("6- ORDENAR VIA QUICK SORT OU MERGE SORT");
		puts("0- SAIR DO PROGRAMA");
		printf("\n");
		printf("OPCAO: ");
		scanf("%d",&op);
		printf("\n");
		if(op == 1){
					push(list);
					printf("\n");
		}else if(op == 2){
					pop(list);	
					printf("\n");
					
		}else if(op == 3){
					display(list);
					printf("\n");
		
		}else if(op == 4){
					insertionSort(list);
					printf("\n");
		}else{
					printf("Opcao invalida!\n");
			  		printf("\n");
		}
	}while(op != 0);
	
	return 0;

}
