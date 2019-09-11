#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(){
	char cpf[15];
	int novCPF[11],totDigit1=0,totDigit2=0, resultado, i=0,num=0, tam, digitoUsuar;
	puts("Informe o numero do seu CPF:");
	fgets(cpf,15,stdin);
	tam=strlen(cpf);
		while(i <= tam){
			if(cpf[i]!='.' && cpf[i]!='-'){
				novCPF[num]=cpf[i] - 48;
				num = num + 1;

			}

		i++;
		}

	i=0;
	while(i < 9){
		totDigit1 = totDigit1+((novCPF[i] )* (10 -i));
		totDigit2 = totDigit2+((novCPF[i] )* (11 -i));

	i++;
	}
	totDigit1=(totDigit1 * 10) % 11;
	if (totDigit1 > 9)
	{
		totDigit1=0;
	}
		totDigit2 = (totDigit2 + (totDigit1 *2)) * 10 % 11;
	if (totDigit2 > 9)
	{
		totDigit2 = 0;	
	}
	resultado = (totDigit1 * 10) + totDigit2;
	i=novCPF[9];
	num=novCPF[10];
	digitoUsuar=((i) * 10) + (num);
	if(resultado == digitoUsuar){
		puts("O CPF valido!");

	}
	else{
		puts("CPF invalido!");
	}


return 0;

}