#include <stdio.h>
#define MAX 10

void Ordenacao(int *v,int tam){
	int i,j,troc;
	for( i = 0; i < tam;i++){
		for(j = i+1; (j > 0) && (v[j] > v[j-1]); j--){
				troc = v[j];
				v[j] = v[j-1];
				v[j-1] = troc;
			
		}
	}

}

void listaVet(int *vet,int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%da posicao : ",i+1);
		printf("%d\n",vet[i]);

	}

}

int recursiv(int *vet, int in, int fim, int elem){
	int meio;
	meio = (in + fim)/2;
	if ( vet[meio] == elem)
		return meio;
	if(in == fim)
		return -1;
	if( vet[meio] > elem)
		return recursiv(vet,in,meio-1,elem);
	if( vet[meio] < elem)					
		return recursiv(vet,meio+1,fim,elem);
}
int leitu(int *vet,int fim){
	int elem, in = 0;
	printf("Digite o elemento: ");
	scanf("%d",&elem);
	return recursiv(vet,in,fim,elem);

}

int main(){
	int i,Xop, vet[10];
		
	for(i = 0; i < 10; i++){
		printf("Vetor na %da posicao : ",i+1);
		scanf("%d",&vet[i]);

	}
	printf("\n");
	while(1){
		printf("\n");
		printf("___________MENU___________\n\n");
		printf("1- ORDENAR VETOR\n");
		printf("2- LISTAR VETOR\n");
		printf("3- BUSCA ELEMENTO NO VETOR\n");
		printf("0- SAIR\n");
		printf("\n");
		printf("Entre a opcao : ");
		scanf("%d",&Xop);	
		printf("\n");
		
		if(Xop == 0)break;
		else if(Xop ==1){
			Ordenacao(vet,10);
			printf("\n");
		}
		else if(Xop == 2){
			listaVet(vet,10);
			printf("\n");
		}
		else if(Xop == 3){
			int size = 10;
			size = leitu(vet, size);
				if(size != -1){
					printf("Elemento encontrado na %da posicao\n",size + 1);
				}else{
					printf("Elemento nao foi encontrado\n");			
				}
			printf("\n");
		}
		else printf("____Nao tem essa opcao\n");

		
	}




	return 0;
}
