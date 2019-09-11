#include<sdio.h>
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
	
	Empregado eepragdoes[5];
	int i;
	for(i=0;i<5;i++){
		scanf("%d",&empregadoes[i].cod);
		scanf("%s",empregadoes[i].nome);
		scanf("%s",empregadoes[i].endereco.rua);
		//ou fgets(empregadoes[i].endereco.rua,20,stdin)
	}
for(i=0;i<5;i++){
	printf("Nome do funcionarios %d: %s\n",i+1,empregadoes[i].nome);
	}
	imprime(empregadoes)
}
