#include<stdio.h>
#include<stdlib.h>
 typedef struct{
	int cod;
	char nome[30];
	double valorVend; 
	
}Produto;

void cadastrar(Produto *prod){
	
	puts("Digite o codigo");
	scanf("%d",&prod->cod);
	puts("Informe o nome");
	__fpurge(stdin);
	fgets(prod->nome,30,stdin);
	puts("Informe o valor da venda");
	scanf("%lf",&prod->valorVend);
	
	
	
	}

int main(){
	Produto prod;
	cadastrar(&prod);
	
	printf("Codigo:%d\nNome:%s\nValor:%.2lf\n",prod.cod,prod.nome,prod.valorVend);
	}
