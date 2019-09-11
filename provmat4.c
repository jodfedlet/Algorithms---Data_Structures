#include <stdio.h>

int funcaoimp(int mat[][5]){
	  int i,j,cont;
	  for(i = 0;i <5;i++){
		  for(j=0;j<5;j++){
			  if(mat[i-1][j] % 2 !=0 && mat[i][j+1] % 2 !=0 && mat[i][j-1] % 2 !=0 && mat[i+1][j] % 2 !=0){
				  cont++;
			   }
		   }
		  
		}
	  
	  
	  return cont;
	  }
	  
int main(){
	int m[5][5] = {{3,5,10,25},
					{1,6,13,11},
					{14,15,32,44},
					{7,17,31,26}};
		  
		m=funcaoimp(m[][5]);  
		  
		  
		  
return 0;		  
}
