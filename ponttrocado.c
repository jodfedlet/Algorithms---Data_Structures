#include <stdio.h>

void swap(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
	}

int main(){
	int  val1, val2;
	puts("Digite os valores: ");
	scanf("%d %d",&val1, &val2);
	
	swap(&val1,&val2);
	
	printf("O valores  trocados sao %d e %d\n", val1,val2);
	
	}
