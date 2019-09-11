#include<stdio.h>
int main(){
 int matr[5][5];
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
 					scanf("%d",&matr[j][i]);
		}
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ", matr[i][j]);
		}
	printf("\n");
	}
 return 0;
}
