#include <stdio.h>
#include <stdlib.h>
#define  MAX 5

typedef struct _pilha{//criaçao de uma struct tipo pilha
	int info[MAX];
	int topo;

}tp_pilha;

void push(tp_pilha *pil){
	int valor;
	if(pil->topo == MAX-1){
		printf("Pilha cheia\n");
	}else{
		printf("Qual elemento?\n");
		scanf("%d",&valor);
		pil->topo++;
		*(pil->info+pil->topo) = valor;
	}
}

int pop(tp_pilha *pil){
	int val;
    if(pil->topo == -1){
		printf("Pilha vazia\n");
		return -1;
    
	}else{
		val = *(pil->info+pil->topo);
		pil->topo--;
		return val;
		}


}

void display(tp_pilha *pil){
	int i;

	if(pil->topo == -1){
		printf("Pilha vazia\n");
    
	}else{
		for(i = pil->topo; i >= 0; i--){
			printf("%d\n",*(pil->info+i));

		}
		printf("\n");
	}
}

int main()
{	int opcao, val;
	
	tp_pilha *pil = (tp_pilha*) malloc(sizeof(tp_pilha));
	pil->topo=-1;		
	

	do{
		
		puts("=========================================");
		printf("		MENU			\n");
		puts("=========================================");
		puts("1- Insercao de elemento na pilha");
		puts("2- Extracao de elemento da pilha");
		puts("3- Exibicao da pilha");
		puts("0- Sair do MENU");
		printf("Informe a sua opcao: ");
		scanf("%d",&opcao);

		if(opcao==1){
					push(pil);
		}else if(opcao==2){
					val = pop(pil);
					if(val !=-1){
						printf("Valor removido: %d\n",val);
					}
		}else if(opcao==3){
					display(pil);
		}else printf("Opcao invalida!\n");

	}while(opcao != 0);

	
	return 0;
}
