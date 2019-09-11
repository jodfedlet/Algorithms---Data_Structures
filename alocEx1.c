#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,*p;


	puts("Indique as posicoes do vetor: ");
	scanf("%d",&n);

	
  p = (int*)malloc(n*sizeof(int)); 


	for(i = 0; i < n; i++){
		printf("Indique o conteudo de cada as posicoes do vetor %d :",i+1);
		scanf("%d",(p+i));

	}
	for(i = 0; i < n; i++){

		printf("A posicao: [%p]\nO conteudo: %d\n",p+i,*(p+i));

	}
	free(p);
 return 0;
}
