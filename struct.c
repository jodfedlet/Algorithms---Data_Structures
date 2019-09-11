#include<stdio.h>
typedef struct{
	char rua[30];
	char bairro[20];
	int cep;
	int num;
}ENDERECO;

typedef struct{
	int cod;
	char nome[30];
	char cargo[30];
	unsigned int salario;
	ENDERECO endereco;
}Empregado;
int main(){
	
	Empregado e1;
	e1.cod=5;
	printf("%d\n",e1.cod);
	scanf("%s",e1.cargo);
	printf("A rua e:");
	scanf("%s",e1.endereco.rua);
	printf("O bairro e:");
	scanf("%s",e1.endereco.bairro);
	printf("O CEP e:");
	scanf("%d",&e1.endereco.cep);
	printf("O numero e:");
	scanf("%d",&e1.endereco.num);
	
	
	
	}
