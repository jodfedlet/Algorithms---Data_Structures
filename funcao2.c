#include<stdio.h>

	//a)
	void verificaContrato(int idade){
		if(idade>=18){
			printf("Pode ser funcionário efetivo");
		}
		else{
			printf(" Precisa ser jovem aprendiz");
		}
	}
	//b)
	void aumentaSalario(int sal) {
		int percent;
		percent=sal/100;
		
	}
	// c)
	void exibeDados(int sal){
		printf("%d\n",sal);
		}
	
	
	
	
	}
int main(){
	char nome[25];
	int idade, sal,temp;
	printf("Informe o seu nome:");
	scanf("%s", nome);
	printf("Digite a sua idade:");
	scanf("%d",&idade);
	printf("Digite o seu salario:");
	scanf("%d",&sal);
	printf("Digite o tempo:");
	scanf("%d",&temp);
}
