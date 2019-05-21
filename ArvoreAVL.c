#include <stdio.h>
#include <stdlib.h>

struct NO{
	int chave;
	int alt,nivel;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
};

typedef struct NO *ArvAVL;




//------------------------------------------------------------------------------------------------------------
ArvAVL *cria_ArvAVL(){
	ArvAVL *raiz = (ArvAVL*) malloc (sizeof(ArvAVL));
	
	if(raiz != NULL)
		*raiz = NULL;
	
	return raiz;
}
//------------------------------------------------------------------------------------------------------------

int altura_NO(struct NO* no){
	if(no == NULL){
		return -1;  // manter as contas correta com o fatorbalanceamento.
	}else
		return no->alt;
}
//------------------------------------------------------------------------------------------------------------

int fatorBalanceamento_NO(struct NO* no){   // indicar qual rotação devo fazer (se for negativo inseriu no lado direito ou se for positivo inseriu no lado esquerdo)
	return labs(altura_NO(no->esq) - altura_NO(no->dir)); // a diferença é o modulo.
}

//------------------------------------------------------------------------------------------------------------
int maior(int x, int y){
	if(x > y){
		return x;
	}else{
		return y;
	}
}
//------------------------------------------------------------------------------------------------------------
/*
	QUANDO USAR CADA ROTAÇÃO?
	
	-Considerando que nó "C" foi inserido como
	filho do nó "B", e que "B" é filho do nó "A",
	se o "fator de balanceamento" for

	-"A = +2" e "B = +1": Rotação LL  -direita 
	-"A = -2" e "B = -1": Rotação RR  -esquerda
	-"A = +2" e "B = -1": Rotação LR  -esquerda,direta.
	-"A = -2" e "B = +1": Rotação RL  -direita,esquerda.

	A rotações LL e RR são simétricas entre si
	assim como LR e RL.
*/
//------------------------------------------------------------------------------------------------------------
void RotacaoLL(ArvAVL *raiz){
	struct NO *no;
	no = (*raiz)->esq;
	(*raiz)-> esq = no->dir;
	no->dir = *raiz;
	(*raiz)->alt = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
	no->alt = maior(altura_NO(no->esq),(*raiz)->alt) + 1;
    no->pai = (*raiz)->pai;
    no->nivel = (*raiz)->nivel;
	(*raiz) = no;

   
	if(no->esq){
      no->esq->pai = (no);
	}
    if(no->dir){
    	no->dir->pai = (no);
    }
  
    

}

//------------------------------------------------------------------------------------------------------------
void RotacaoRR(ArvAVL *raiz){

	struct NO *no;
	no = (*raiz)->dir;
	(*raiz)->dir = no->esq;
	no->esq = (*raiz);
	(*raiz)->alt = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
	no->alt = maior(altura_NO(no->dir),(*raiz)->alt) + 1;
	no->pai = (*raiz)-> pai;
	no->nivel =(*raiz)-> nivel;
	*raiz = no;
	
	if(no->esq){
      no->esq->pai = (no);
	}
    if(no->dir){
    	no->dir->pai = (no);
    }
    
	
}
//------------------------------------------------------------------------------------------------------------
void RotacaoLR(ArvAVL *raiz){
	RotacaoRR(&(*raiz)->esq);
	RotacaoLL(raiz);
}
//------------------------------------------------------------------------------------------------------------
void RotacaoRL(ArvAVL *raiz){
	RotacaoLL(&(*raiz)->dir);
	RotacaoRR(raiz);
}
//------------------------------------------------------------------------------------------------------------

void regularNivel_b(struct NO *aux, int atual, int cont){
    if(!aux)
        return;

    if(aux){
        regularNivel_b(aux->esq, atual, cont+1);

        if(atual == cont)
            aux->nivel = atual;
        

        regularNivel_b(aux->dir, atual, cont+1);
    }
}
void regularNivel(struct NO *aux){
    int i;
    
    for(i = 1; i <= (maior(altura_NO(aux->esq),altura_NO(aux->dir)) + 1); i++){
        regularNivel_b(aux, i, 0);
    }
}

//------------------------------------------------------------------------------------------------------------
int insere_ArvAVL(ArvAVL *raiz, int valor){
	int res;
	
	if(*raiz == NULL){ // árvore vazia ou nó folha.
		struct NO *novo;
		novo = (struct NO*)malloc (sizeof(struct NO));
		if (novo == NULL)
			return 0;
		novo->chave = valor;
		novo->alt = 0;
		novo->nivel= 0;
		novo->esq = NULL;
		novo->dir = NULL;
		novo->pai = NULL;
		*raiz = novo;
		return 1;
	}
	struct NO *atual = *raiz;
	
	if(valor < atual->chave){
		if((res = insere_ArvAVL(&(atual->esq),valor))== 1){
			if (fatorBalanceamento_NO(atual) >= 2){
				if(valor < (*raiz)->esq->chave){
					RotacaoLL(raiz);
				}else{
					RotacaoLR(raiz);
				}
			}
		}
	}else{
		if(valor > atual-> chave){
			if((res =insere_ArvAVL(&(atual->dir),valor))==1){
				if(fatorBalanceamento_NO(atual) >= 2){
					if((*raiz)->dir->chave < valor){
						RotacaoRR(raiz);
					}else{
						RotacaoRL(raiz);
					}
				}
			}
		}else{
			printf("---------------------------------------------------------\n");
			printf("\n### Valor que já foi inserido! ###\n");
			printf("---------------------------------------------------------\n");
			return 0;
		}
	}
	atual->alt = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    if(atual->esq){
    	atual->esq-> pai =atual;

    }
    if(atual->dir){
    	atual->dir->pai = atual;

    }
    regularNivel(*raiz);
	return res;
}
//
void mostraArvoreInOrdem(struct NO *raiz){
	if(raiz == NULL)
		return ;
	
	mostraArvoreInOrdem(raiz->esq);
	printf("chave: %d  ||  altura: %d  ||  nivel: %d   ||  ",raiz->chave,raiz->alt, raiz->nivel);
	if(raiz->pai !=NULL){
    	printf("pai: %d \n",raiz->pai->chave );
	}
	else
		printf("pai: %p \n",raiz->pai);
	mostraArvoreInOrdem((raiz)->dir);

}
//


//
int main(){
	ArvAVL *raiz = cria_ArvAVL();
	int valor, opc,x;

   do{


   		printf("------------------------------\n");
		printf("1 - Inserir\n");
		printf("2 - Mostrar\n");
		printf("0 - Sair\n");
		printf("------------------------------\n");

		scanf("%d", &opc);
		switch(opc){
			case 0:
				printf("Encerrando programa ...\n");
				break;
			case 1:
				printf("------------------------------\n");
				printf("Informe o valor a ser inserido:  ");
				scanf("%d", &valor);
				printf("------------------------------\n");
				if ((x = insere_ArvAVL(raiz, valor)) == 1){
					printf("\nElemento inserido\n\n");
				}
				break;
			case 2:
				printf("Listagem dos valores:\n");
 				mostraArvoreInOrdem(*raiz);
				break;
			default:
				printf("Opção Inválida!\n");
				break;
		}
	}while(opc != 0);
	
	return 0;
}
