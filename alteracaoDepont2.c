#include <stdio.h>
#include <stdio_ext.h> 
#include <stdlib.h>
#define TAM 3

typedef struct{
	char nome[50];
	int idade;
	double salario;
	int tempoEmpresa;
}funcionario;

void cadastrar(funcionario func[]){
	int i;
	for(i=0;i<3;i++){	
		__fpurge(stdin);
		puts("Nome: ");
		fgets(func[i].nome, 50, stdin);
		puts("Idade: ");
		scanf("%d", &func[i].idade);
		puts("Salario: ");
		scanf("%lf", &func[i].salario);
		puts("Tempo de Empresa: ");
		scanf("%d", &func[i].tempoEmpresa);
		system("clear");
	}
}

void exibir(funcionario f[]){
	int i;
	for(i=0;i<3;i++){	
		system("clear");
		printf("Nome: %s", f[i].nome);
		printf("Idade: %d anos\n", f[i].idade);
		printf("Salário: %.2lf\n", f[i].salario);
		printf("Tempo de empresa: %d anos\n", f[i].tempoEmpresa);
	}
}

int main(){
	int op;
	funcionario fu[3];
	//funcionario funcionarios[3];
	do{
		puts("\n\tMENU DOS FUNCIONÁRIOS\n");
		puts("1-Cadastrar Funcionario");
		puts("2-Exibir Funcionario");
		puts("6-Sair");
		printf("Opção: ");
		scanf("%d", &op);
		system("clear");
		switch(op){
			case 1:
				cadastrar(fu);
				break;
			case 2:
				exibir(fu);
				break;
			case 6:
				break;
			default: 
				puts("Opção inválida!");
				break;
		}
	}while(op!=6);
	
}

