#include<stdio.h>

void inversao(int *x,int*y){
	int aux;
	aux=*x;
	*x=*y;
	*y=aux;
	

}

int main(){
	int x, y;
	puts("Informe o valor da variavel x:");	
	scanf("%d",&x);
	puts("Informe o valor da variavel y:");	
	scanf("%d",&y);
	
	inversao(&x,&y);
	printf("X: %d\nY: %d\n",x,y);
	
	return 0;
	}
