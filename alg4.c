#include<stdio.h>
int main(){
	int i, j,num,k=1;
	scanf("%d",&num);
	for(i=1;i<=num;i++){
		for(j=1;j<=i;j++,k++){
				if(k%2==0){
					printf("P");
				}
				else{
					printf("Q");		
				}



		}
 		printf("\n");



	}
printf("\n");






return 0;
}
