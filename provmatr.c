#include <stdio.h>
 int main(){
	int matr[12][4];
	int i,j,totmes[12],totAno=0;
	for(i = 0;i < 12; i++){
		totmes[i] = 0;
		for(j = 0;j < 4; j++){
			
			printf("A matriz na %d a linha e na %d a coluna: ",i+1,j+1);
			scanf("%d",&matr[i][j]);
			totmes[i] = totmes[i] + matr[i][j];
			totAno=totAno + matr[i][j];
			
			}
		}	
		for(i = 0;i < 12; i++){
			printf("Mes: %d\n",i);
			for(j = 0;j < 4; j++){
				printf("Total vendido em cada semana: %d\n",matr[i][j]);
				
			}
			printf("Total do mes: %d\n", totmes[i]);
		}
	printf("Total vendido em cada ano: %d\n", totAno);	
		
		
		
		
		
		
		
		
		
	
	}
