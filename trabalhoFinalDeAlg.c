/*Trabalho Final AlgoritmosProfessores: Guilherme Dal Bianco e Priscila Delabetha Apresentação:Portal do ProfessorVocê foi contratado para desenvolver um sistema para os professores da UFFS controlarem as notas de seus alunos, e gerenciarem seus diários.O sistema deve deve possuir as seguintes funções:Funções principais:● Cadastro de Turma● Cadastros de Alunos● Inserção de notas (NP1 e NP2)● Calcular Médias Finais● Encerrar DiárioFunções de exibição:● Listar alunos da turma● Exibir dados da turma● Exibir notas parciais● Exibir notas finaisDetalhes das funções principais: Cadastros de Turma:Permite o usuário cadastrar turmas com as informações:● Código da turma (aleatório ou gerado sequencialmente)● Componente curricular ministrado● Fase● Horário das aulasCadastrar Alunos:Deve possibilitar ao usuário cadastrar as informações básicas de um aluno:● Nome completo do aluno● Número de matrícula● CPF (deve ser validado)● Turma a qual ele pertenceInserção de notas (NP1 e NP2):
 Essa função permite ao professor informar as notas parciais de NP1 ou NP2 de uma turma.Calcular médias finais:Essa função irá utilizar o peso informado pelo professor para calcular a média final de cada aluno da turma.Encerrar diário:A função encerrar diário deve verificar os alunos aprovados e reprovados, e exibir na tela as médias finais da turma toda, juntamente com a informação de aprovação ou reprovação dos alunos.Utilização do programaO sistema deve exibir um menu com as opções para que o usuário possa selecionar o que deseja fazer.Recursos da Linguagem C obrigatórios no projeto:Funções - as operações detalhadas neste trabalho devem ser feitas com funções da Linguagem C.Vetores - estruturas de vetores precisam estar presentes no trabalho.Structs – Utilize Structs para pelo menos uma das informações que precisam ser armazenadas.Ponteiro - Pelo menos uma função no projeto precisa utilizar ponteiros.Avaliação:1. Compilação: 10%2. Execução correta: 60%Serão feitos vários testes.Cada teste com um nível de dificuldade maior, onde o arquivo de saída do programa será comparado com um "gabarito". O aluno receberá nota máxima se ambos forem idênticos.3. Estilo de programação: 10%Código bem identado, legível, comentado (sem excesso), bem estruturado, nomes de variáveis significativos, etc.4. Documentação: 10%
5. Apresentação do andamento com a estrutura do código pronta e a lógica para resolver o problema ( função já implementada): 10% */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//1.  Estrutura com informações do aluno
typedef struct aluno{
	 char nome[35];
	 int matricula;
	 float np1, np2, media;
	 char cpf[15];
	 int nTurma;
}Aluno;
//2. Estrutura com informações da turma	 
typedef struct turma{
	int	codDaTurma;
	char compCurricular[35];
	int fase;
	char hrDasAulas[35];
	int qtdAlunos;
	float np1, np2;
	Aluno alunos[40];
}Turma;
 //3. Função para cadastrar turma
void cadastroTurma(Turma t[], int *nt){
	t[*nt].codDaTurma = *nt;
	t[*nt].qtdAlunos = 0;
	puts("___________________________________________");

	puts("       ***INFORMACOES DA TURMA***         ");
	printf("-> Codigo : %d\n",t[*nt].codDaTurma);
	puts("-> Digite o componente curricular: ");
	getchar();
	fgets(t[*nt].compCurricular,35,stdin);
	puts("-> Digite a fase: ");
	scanf("%d", &t[*nt].fase);
	puts("-> Digite o horario: ");
	getchar();
	fgets(t[*nt].hrDasAulas,35,stdin);
	puts("___________________________________________");
						(*nt)++;
}
//4. Função para validar o CPF do aluno
int validacaoDeCpf(char cpf[]){
	int novCPF[11],totDigit1 = 0,totDigit2 = 0, resultado, i = 0,num = 0, tam, digitoUsuar;
	tam = strlen(cpf);
		while(i <= tam){
			if(cpf[i]!='.' && cpf[i]!='-'){
				novCPF[num]=cpf[i] - 48;
				num = num + 1;
			}
		i++;
		}

	i=0;
	while(i < 9){
		totDigit1 = totDigit1+((novCPF[i] ) * (10 -i));
		totDigit2 = totDigit2+((novCPF[i] ) * (11 -i));

	i++;
	}
	totDigit1=(totDigit1 * 10) % 11;
	if (totDigit1 > 9)
	{
		totDigit1 = 0;
	}
		totDigit2 = (totDigit2 + (totDigit1 * 2)) * 10 % 11;
	if (totDigit2 > 9)
	{
		totDigit2 = 0;	
	}
	resultado = (totDigit1 * 10) + totDigit2;
	i=novCPF[9];
	num=novCPF[10];
	digitoUsuar=((i) * 10) + (num);
	if(resultado == digitoUsuar){
		/*puts("O CPF valido!");
		printf("%s\n",cpf);*/
		return 1;
	}
	else{
		puts("CPF invalido!");
		return 0;	
	}	
}
//5. Função para cadastrar aluno
void cadastroDeAluno(Turma t[], int nt){
	char cpf[15];
	puts("        ***CADASTRO DE ALUNO***         ");
	puts("-> Informe o numero do CPF: ");
	getchar();
	fgets(cpf,15,stdin);
	if(validacaoDeCpf(cpf) == 0){
		return;
	}
	strcpy(t[nt].alunos[t[nt].qtdAlunos].cpf,cpf);
	puts("-> Digite o nome do aluno: ");
	getchar();
	fgets(t[nt].alunos[t[nt].qtdAlunos].nome, 35, stdin);
	//Retira o \n do final do nome	
	t[nt].alunos[t[nt].qtdAlunos].nome[strlen(t[nt].alunos[t[nt].qtdAlunos].nome)-1] = '\0';
	puts("-> Digite o numero da matricula: ");
	scanf("%d",&t[nt].alunos[t[nt].qtdAlunos].matricula);
	getchar();
	puts("___________________________________________");
	t[nt].alunos[t[nt].qtdAlunos].nTurma = nt;
			       t[nt].qtdAlunos++;
}

//6. Função para inserir notas de cada aluno cadastrado
void insercaoDeNotas(Turma t[],int nt){
	int i;
	puts("       ***INSERCAO DE NOTAS***         ");
	for(i = 0 ; i < t[nt].qtdAlunos ; i++){
		printf("-> Np1 de %s: ",t[nt].alunos[i].nome);
		scanf("%f",&t[nt].alunos[i].np1);
		printf("-> Np2 de %s: ",t[nt].alunos[i].nome);
		scanf("%f",&t[nt].alunos[i].np2);
		puts("___________________________________________");
	}
}
//7. Função para calcular média de cada aluno cadastrado
void calculDemediasFinais(Turma t[], int nt){
	int i;
	double peso1,peso2;
	puts("       ***CALCUL DE MEDIA***         ");
	puts("Informe os pesos: ");
	printf("-> NP1: ");
	scanf("%lf",&peso1);
	printf("-> NP2: ");
	scanf("%lf",&peso2);
	puts("___________________________________________");
	for(i = 0 ; i < t[nt].qtdAlunos ; i++){
		t[nt].alunos[i].media = t[nt].alunos[i].np1*peso1  + t[nt].alunos[i].np2*peso2;
	}
	
}
//8. Função para encerrar diario de cada aluno cadastrado
void encerraDiario(Turma t[], int nt){
	int i;
	puts("       ***ENCERRAR DIARIO***         ");
	for(i = 0 ; i < t[nt].qtdAlunos ; i++){
		printf("<> Nome: %s\n",t[nt].alunos[i].nome);
		if(t[nt].alunos[i].media >= 6.00){
			printf("<> Media: %.2lf\n", t[nt].alunos[i].media);
			puts("Aluno aprovado :)!");
			puts("___________________________________________");
		}
		else{
			printf("<> Media: %.2lf\n", t[nt].alunos[i].media);
			puts("Aluno reprovado (:!");
			puts("___________________________________________");
		}
	}
}
//9. Função para listar alunos
void listaAlunosDaTurma(Turma t[], int nt){
	int i;
	puts("       ***LISTA ALUNO***         ");
	for(i = 0 ; i < t[nt].qtdAlunos;i++){
		printf("<> Nome: %s\n<> Matricula: %d\n",t[nt].alunos[i].nome,t[nt].alunos[i].matricula);
		printf("___________________________________________\n");
	}
}
//10. Função para exibir dados da turma
void exibedadosDaTurma(Turma t[], int nt){
	puts("      ***EXIBIR DADOS DA TURMA***         ");
	printf("<> Codigo: %d\n",t[nt].codDaTurma);
	printf("<> Componente: %s",t[nt].compCurricular);
	printf("<> Fase: %d\n",t[nt].fase);
	printf("<> Horario: %s",t[nt].hrDasAulas);
	printf("<> Quantidade de aluno: %d\n",t[nt].qtdAlunos);
	puts("___________________________________________");

	
}
//11. Função para exibir notas parcias
void exibicaoDeNotasParciais(Turma t[], int nt){
	int i;
	puts("      ***EXIBIR NOTAS PARCIAIS***         ");
	for(i = 0; i < t[nt].qtdAlunos; i++){
		printf("<> Nome: %s\n",t[nt].alunos[i].nome);
		printf("<> NP1: %.2f\n<> NP2: %.2f\n",t[nt].alunos[i].np1,t[nt].alunos[i].np2);
		puts("___________________________________________");
	}
}
//12. Função para exibir notas finais
void exibicaodeNotasfinais(Turma t[], int nt){
	int i;
	puts("       ***EXIBIR NOTAS FINAIS***         ");
	for(i = 0; i < t[nt].qtdAlunos; i++){
		printf("<> Nome: %s\n",t[nt].alunos[i].nome);
		printf("<> Nota: %.2f\n",t[nt].alunos[i].media);
		puts("___________________________________________");
	}

}

//13. A função padrão
int main(){
	 int opcao, nt = 0, x;
	 Turma turmas[25];
	 do{
		printf("\n");
		// Aqui tem o menu das opções
		printf("-------------------------------------------\n");
		printf("   	Ola! Seja bem-vindo na UFFS!       \n");
		printf("********************************************\n");
		printf("*                  MENU                    *\n");
		printf("********************************************\n");
		printf("   | 1.- Cadastro da turma              |\n");
		printf("   | 2.- Cadastro de aluno              |\n");
		printf("   | 3.- Insercao das notas             |\n");
		printf("   | 4.- Calcular as medias finais      |\n");
		printf("   | 5.- Encerrar diario                |\n");
		printf("   | 6.- Listar alunos da turma         |\n");
		printf("   | 7.- Exibir dados                   |\n");
		printf("   | 8.- Exibir notas parciais          |\n");
		printf("   | 9.- Exibir notas finais            |\n");
		printf("   | 0.- Sair                           |\n");
		printf("============================================\n");
		printf("|     Digite uma das opcoes em baixo:      |\n");
		printf("============================================\n");
		printf("------> Opcao: ");
		scanf("%d",&opcao);
		printf("\n");
		//Aqui tem um interruptor(SWITCH) para chamar cada função escolhida
		switch(opcao){
			case 1:
				cadastroTurma(turmas, &nt);
						break;
			case 2:
				puts("___________________________________________");

				printf("-> Informe o codigo da turma: ");
				scanf("%d",&x);
				if(nt > x){
					cadastroDeAluno(turmas, x);
					
				}
				else{
					puts("Nao tem essa turma!");
				}
				puts("___________________________________________");
				printf("\n");
									break;
			case 3:
				puts("___________________________________________");

				printf("-> Informe o codigo da turma: ");
				scanf("%d",&x);
				if(nt > x){
					insercaoDeNotas(turmas, x);
				}
				else{
					puts("Nao tem essa turma!");
				}
				puts("___________________________________________");
				printf("\n");
			   						 break;
			case 4:
				puts("___________________________________________");

				printf("-> Informe o codigo da turma: ");
				scanf("%d",&x);
				if(nt > x){
					calculDemediasFinais(turmas, x);
				}
				else{
					puts("Nao tem essa turma!");
				}
				puts("___________________________________________");
				printf("\n");
									break;
			case 5:
				puts("___________________________________________");

				printf("-> Informe o codigo da turma: ");
				scanf("%d",&x);
				if(nt > x){
					encerraDiario(turmas, x);
				}
				else{
					puts("Nao tem essa turma!");
				}
				puts("___________________________________________");
				printf("\n");
			    						break;
			case 6:
				puts("___________________________________________");

				printf("-> Informe o codigo da turma: ");
				scanf("%d",&x);
				if(nt > x){
					listaAlunosDaTurma(turmas, x);
				}
				else{
					puts("Nao tem essa turma!");
				}
				puts("___________________________________________");
				printf("\n");
			    break;
			case 7:
				puts("___________________________________________");

				printf("-> Informe o codigo da turma: ");
				scanf("%d",&x);
				if(nt > x){
					exibedadosDaTurma(turmas, x);
				}
				else{
					puts("Nao tem essa turma!");
				}
				puts("___________________________________________");
				printf("\n");
			    break;
			case 8:
				puts("___________________________________________");

				printf("-> Informe o codigo da turma: ");
				scanf("%d",&x);
				if(nt > x){
					exibicaoDeNotasParciais(turmas, x);
				}
				else{
					puts("Nao tem essa turma!");
				}
				puts("___________________________________________");
				printf("\n");
			    							break;
			case 9:
				puts("__________________________________________");

				printf("-> Informe o codigo da turma: ");
				scanf("%d",&x);
				if(nt > x){
					exibicaodeNotasfinais(turmas, x);
				}
				else{
					puts("Nao tem essa turma!");
				}
				puts("___________________________________________");
				printf("\n");
			    							break;
			case 0:
			    							break;
		default:
			puts("Opcao invalida!");
		}
	 }while(opcao != 0);
	 return 0;
 }
