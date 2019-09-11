#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void parteInteira(int numero){
	
	int quociente, resto;
	while(numero > 0){
		
	
			resto = numero % 2;
			
			quociente = numero / 2;
			
			printf("%d ",resto);

			numero = quociente;
		
		
	}

	printf("\n");
}

void Mantissa(float mantissa){
	 
	float resul;
	int cont = 0;


	while(1){

		resul = mantissa * 2;
			cont++;
		if(mantissa == 0.00 || mantissa == resul || cont > 10)break; 
		printf(" %d", (int)resul);
		mantissa = resul-((int)resul);
	}
	printf("\n");
}
int main(){
	float num;

	printf("Informe o numero: ");
	
	scanf("%f",&num);
		
		 parteInteira((int)num);
		 Mantissa(num-((int)num));
	
	return 0;	
}
