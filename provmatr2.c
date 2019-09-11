#include <stdio.h>

int somaVisinhos(int m[][5], int x, int y){
	int soma = 0;
	int i,j;
	for(i=x-1;i<=x+1;i++){
		for(j=y-1;j<= y+1;j++){
			if(i<0 || i> 4|| j < 0 || j > 4)
				continue;
			soma = soma + m[i][j];
			}
	}
	return soma - m[x][y];
}
	
int main(){
	int matr[5][5] = {{0, 6, 4, 1, 8}, {8, 11, 1, 1 ,1}, {0,3,5,1,0}, {0,1,0,1,0}, {5,9,14,7,1}};
	int l,c;
	puts("Digite os dois inteiros: ");
	scanf("%d%d",&l,&c);
	printf("Soma: %d\n", somaVisinhos(matr, l, c));
	return 0;
}
