#include <stdio.h>

int main(){
	char calculadora;
	int num1,num2;
	scanf("%c",&calculadora);
	scanf("%d %d",&num1,&num2);
	switch(calculadora){
		case '+':
			printf("Soma = %d\n",num1+num2);
					break;
		case '-':
			printf("Diferenca = %d\n",num1-num2);
					break;
		case '*':
			printf("Produto = %d\n",num1*num2);
					break;

		case '/':
			printf("Divisao = %d\n",num1/num2);
					break;
		default:
			printf("Operacao invalida\n");
		
	}



	return 0;
}
