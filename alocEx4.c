#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1,int n1,int *v2,int n2){
	int i,j, *pont;
	
	pont = (int*) malloc((n1 + n2) * sizeof(int));
	
	for(i = 0; i < n1; i++){
		pont[i] = v1[i]; 


	}
	for(j = 0; j < n2; j++){
		pont[i] = v2[j]; 
						i++;
	}

	return pont;
}

int main(){
	int v1[] = {11,13,45,7};
	int v2[] = {24,4,16,81,10,12};
	int x = 4, y = 6;
	int *v3,k;


	v3 = uniao(&v1,4,&v2,6);

	for(k = 0; k < (x + y); k++){
		printf("%d ",*(v3 + k));

	}
	printf("\n");

	free(v3);
	return 0;
}
