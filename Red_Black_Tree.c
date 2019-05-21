
#include <stdio.h>
#include <stdlib.h>
#include "colors.h"  // https://github.com/kirotawa/Scripts/blob/master/C/colors/image/colors_h.png

#define RED 1
#define BLACK 0


struct NO{
	int chave;
	int nivel;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
	int cor;
};


void mostraArvoreInOrdem(struct NO *raiz);

typedef struct NO *RubroNegro;

RubroNegro *cria_RubroNegro(){
	RubroNegro *raiz = (RubroNegro*) malloc (sizeof(RubroNegro));
	
	if(raiz != NULL)
		*raiz = NULL;
	else
	{
		printf("ERRO A0 INICIALIZAR\n");
		exit(0);
	}
	return raiz;
}

void caso1Esq(struct NO  *aux){
	if(aux->esq)
 		aux->esq->cor = BLACK;
 	
 	if(aux->dir)
 		aux->dir->cor = BLACK;
 	
 	aux->cor = RED;
	
}
//------------------------------------------------------------------------------------------------------------
struct NO* caso3Esq(struct NO  *aux){
	struct NO* pp = aux->esq;

	aux->esq = pp->dir;

	if(aux->esq !=NULL )
		aux->esq->pai = aux;
		
	pp->dir = aux;
	pp->pai = aux->pai;

  	aux->nivel = pp->nivel;
    aux = pp;
   

	aux->cor = BLACK;

	if(aux->dir){
		aux->dir->cor= RED;
		aux->dir->pai = aux;
 
	}

	return aux;
}
//------------------------------------------------------------------------------------------------------------
struct NO* caso2Esq(struct NO  *aux){
	struct NO* pp = aux->esq;
   

	aux->esq = pp->dir;
	pp->dir = pp->dir->esq;
	
	if(pp->dir !=NULL ){
		pp->dir->pai = pp;

	}

	aux->esq->esq = pp; 
	aux->esq->pai = aux;
	aux->esq->esq->pai = aux->esq;


	
	aux = caso3Esq(aux);
	
	
	
	return aux;
}
//------------------------------------------------------------------------------------------------------------
void caso1Dir(struct NO *aux){
	if(aux->dir)
 	aux->dir->cor = BLACK;
 	
 	if(aux->esq)
 	aux->esq->cor = BLACK;
 	
 	aux->cor = RED;

}
//------------------------------------------------------------------------------------------------------------
struct NO* caso3Dir(struct NO  *aux){
	struct NO* pp = aux->dir;


	aux->dir = pp->esq;
	if(aux->dir !=NULL ){
		aux->dir->pai = aux;	
	}


	pp->esq = aux;
	pp->pai = aux->pai;
	

	aux = pp;
	aux->cor = BLACK;

	if(aux->esq){
		aux->esq->cor= RED;
		aux->esq->pai = aux;

	}
	
	

	return aux;
}
//------------------------------------------------------------------------------------------------------------

struct NO* caso2Dir(struct NO  *aux){
	struct NO* pp = aux->dir;
 

	aux->dir = pp->esq;
	pp->esq = pp->esq->dir;


	if(pp->esq !=NULL ){
		pp->esq->pai = pp;

	}
	aux->dir->dir = pp;
	aux->dir->pai = aux;
	aux->dir->dir->pai = aux->dir;
 	
    aux = caso3Dir(aux);


	
	

	return aux;
}

//------------------------------------------------------------------------------------------------------------

void mostraArvoreInOrdem(struct NO *raiz){
	if(raiz == NULL)
		return ;

    else {
		mostraArvoreInOrdem(raiz->esq);


		printf("chave: %d ",raiz->chave);
		
		printf("  ||  nivel: %d ",raiz->nivel);
		if(raiz->cor == RED){
			printf("  ||  cor: vermelho ");
		}
		else
			printf("  ||  cor: preto ");

		if(raiz->pai !=NULL){
	    	printf("  ||  pai: %d ",raiz->pai->chave );
		}
		else
			printf("  || pai: %p ",raiz->pai);
		
		printf("\n");



		mostraArvoreInOrdem(raiz->dir);
		
	}

}


void Nivel(struct NO *raiz,int nivel){
	if(raiz == NULL)
		return ;

    else {
		Nivel(raiz->esq,++nivel);
		
		raiz->nivel = nivel;
	

		Nivel(raiz->dir,nivel++);
		
	}

}

int insere_RubroNegro(RubroNegro *raiz, int valor,int nivell){
	int res;


   
	
	if(*raiz == NULL){
		struct NO *new = (struct NO*)malloc(sizeof(struct NO));
   	if(new == NULL){
   		printf("ERRO AO CRIAR NODO\n");
   		return 0;
  	}
  		new-> chave = valor;
		new-> nivel = 0;
		new-> esq = NULL;
		new-> dir = NULL;
		new-> pai = NULL;
		new-> cor = RED;
   	 	*raiz = new; 
   	 		 
    	return 1; 	
   }
   struct NO  *aux  = *raiz;  

	if(valor == aux->chave){
		printf("\n");
		printf(">>>>>>>>> VALOR JÁ INSERIDO >>>>>>>>>>>>>>>>>>>\n");
		printf("\n");
		return 0;	
 	}
    
 	else {

 		if(valor < aux->chave){
 		
			res = insere_RubroNegro(&(aux->esq),valor,nivell);
			
	
			if(aux->esq){
				aux->esq->pai = aux;

			}
		    //-------------------------------- esquerda esq

			if(aux->esq){
				if(aux->esq->esq != NULL && aux->dir == NULL){	    	
					if(aux->esq->esq->cor == RED && aux->esq->cor == RED){
						aux = caso3Esq(aux);
						*raiz = aux;		
					}
				}
			}

		   if(aux->esq && aux->dir !=NULL){
				if(aux->esq->esq != NULL && aux->dir->cor == BLACK){
					if(aux->esq->esq->cor == RED && aux->esq->cor == RED){
						aux = caso3Esq(aux);
						*raiz = aux;		
					}
				}
			}
		   

			if(aux->esq && aux->dir !=NULL){    
				if(aux->esq->esq !=NULL && aux->dir->cor == RED){	
					if(aux->esq->esq->cor == RED && aux->esq->cor == RED){
						caso1Esq(aux);
					}	
				}
			}	
			 
			//--------------------------------esquerda dir

		    if(aux->esq != NULL){
				if(aux->esq->dir !=NULL && aux->dir == NULL){
					if(aux->esq->dir->cor == RED && aux->esq->cor == RED){	
						aux = caso2Esq(aux);
						*raiz = aux;
					}
				}
			}

			if(aux->esq != NULL && aux->dir != NULL){
				if(aux->esq->dir != NULL && aux->dir->cor == BLACK){
					if(aux->esq->dir->cor == RED && aux->esq->cor == RED){
						aux = caso2Esq(aux);
						*raiz = aux;
					}
				}
			}
			if(aux->esq != NULL && aux->dir != NULL){	
				if(aux->esq->dir !=NULL && aux->dir->cor == RED){
					if(aux->esq->dir->cor == RED && aux->esq->cor == RED){
						caso1Esq(aux);	
					}
				}
			}




		}
		else if(valor > aux->chave){
			res = insere_RubroNegro(&(aux->dir),valor,nivell);
	
			if(aux->dir)
				aux->dir->pai = aux;
			 

			//------------------------------direita dir

			if(aux->dir != NULL){	  
				if(aux->dir->dir !=NULL && aux->esq == NULL){
					if(aux->dir->dir->cor == RED && aux->dir->cor == RED){
			    	   	aux = caso3Dir(aux);
			    	   	*raiz = aux;				
					}						
				}
			}
			
			if(aux->dir != NULL && aux->esq != NULL){
				if(aux->dir->dir !=NULL && aux->esq->cor == RED){
					if(aux->dir->dir->cor == RED && aux->dir->cor == RED){
						caso1Dir(aux);
					}
				}	
			}

			if(aux->dir !=NULL && aux->esq !=NULL){ 
				if(aux->dir->dir !=NULL && aux->esq->cor == BLACK){
					if(aux->dir->dir->cor == RED && aux->dir->cor == RED){
						aux = caso3Dir(aux);
							*raiz = aux;
					}	
				}
			}

			
			//------------------------------direita esq

			if(aux->dir != NULL){
				if(aux->dir->esq !=NULL && aux->esq == NULL){
					if(aux->dir->esq->cor == RED && aux->dir->cor == RED){
						aux = caso2Dir(aux);				
						*raiz = aux;
					}
				}
			}

			
			if(aux->dir != NULL && aux->esq != NULL){	
				if(aux->dir->esq !=NULL && aux->esq->cor == RED){
					if(aux->dir->esq->cor == RED && aux->dir->cor == RED){
						caso1Dir(aux);
					}
				}
			}

			if(aux->dir != NULL && aux->esq != NULL){
				if(aux->dir->esq != NULL && aux->esq->cor == BLACK){
					if(aux->dir->esq->cor == RED && aux->dir->cor == RED){
						aux = caso2Dir(aux);
						*raiz = aux;
					}
				}
			}
		}	
	}
	
     Nivel(*raiz,nivell);

   	return res;
}


int main(){
	RubroNegro *raiz = cria_RubroNegro();
	int valor, opc,x,nivell = -1;

   do{

   		foreground(CYAN);
   		printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");

		printf("1 - Inserir\n");
		printf("2 - Mostrar\n");
		printf("0 - Sair\n");
		printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");

		foreground(YELLOW);
		printf("Opção:  ");
		scanf("%d", &opc);
		foreground(CYAN);
		printf("------------------------------\n");
		switch(opc){
		
			case 1:
			
				foreground(YELLOW);
				printf("Informe o valor a ser inserido:   ");
				scanf("%d", &valor);

				if ((x = insere_RubroNegro(raiz, valor,nivell)) == 1){
					printf("\n----> Elemento inserido\n");
				}
				break;
			case 2:
				if(*raiz == NULL){
				foreground(YELLOW);
					printf("###### ARVORE VAZIA ######");

				}
				else{
					if( *raiz != NULL){
   	 					(*raiz)->cor = BLACK;
   	 				}
   	 				
					background(WHITE);
					style(ITALIC);
					foreground(BLACK);
					printf("Listagem dos valores:\n\n");
					foreground(BLACK);
					
					mostraArvoreInOrdem(*raiz);

				background(NORMAL);
				}
 					
				break;
			case 0:
				foreground(YELLOW);
				printf("Encerrando programa ...\n");
				break;
			default:
				foreground(YELLOW);
				printf("Opção Inválida!\n");
				break;
		}
	}while(opc != 0);
	
	return 0;
}
