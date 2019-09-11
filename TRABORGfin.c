#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//processo para calcular o sinal
int sinal(float a){
	int sin;
	if(a < 0){
		sin = 1;
	} 
	else if(a > 0){
		sin = 0;
	}
	return sin;

}
//processo para achar a mantissa
void mantissa(float mant){
	float multi;
	int mantCal =1,i = 0,vet[23],j;
	
	printf("Mantissa calculada = ");
	while(mantCal ==1 || mantCal == 0){
		
		 multi = mant * 2;
			mantCal = (int)multi;
			printf("%d ",mantCal);
			
		mant = multi-((int)multi); 
					i++;
		if(mant == 0 && mantCal == 0) break;
		
	}
	if(i < 23){
		for(j = i; j < 23; j++ ){

			printf("0 ");
			
		}
		printf("\n");
	}		
	printf("\n");
	
}
//processo de divisao do numero
int primeiroPasso(float num){
	int expo = 0;
	float quociente, resul, resultado, base;

	while(1){
		if(num <= 2)break;
		
		quociente = num / 2;
				expo++;

		printf("%f/ 2 = %f\n",num,quociente);
		num = quociente;
		
	}
	printf("Resultado 1 = %f x 2**%d\n",quociente,expo);
	
	resultado = quociente -((int)quociente);
	mantissa(resultado);
	return expo;

}
//A funcao principal
int main(){
	float num; 
	int sin, expoente,inteiro, i = 1, binarioInt;

	printf("Informe o numero: ");
	
	scanf("%f",&num);
		
		        expoente = primeiroPasso(num);
		 	sin = sinal(num);


			printf("SINAL = %d\n", sin);
			printf("EXPOENTE = %d\n", expoente);

		inteiro = expoente + 127;
		
		//processo para converter a parte inteira
		while(inteiro > 0){
		
			binarioInt = binarioInt + inteiro % 2 * i;
        		i = i * 10;
        		inteiro = inteiro / 2;
		}
		printf("INTEIRA : %d\n\n",binarioInt);
		
		//printf("NUMERO %f EM BINARIO E :%d%d\n",num,sin,binarioInt);
	return 0;	
}



