#include<stdio.h>
int main(){
 	int vet[10],maior;
 	for(int i=0;i<10;i++){
		scanf("%d",&vet[i]);
	}
	maior=vet[0];
	for(int i=1;i<10;i++){
		if(vet[i]>maior){
			maior=vet[i];
		}
	}
 printf("%d E o maior\n",maior);
	for(int i=9;i>=0;i--){
		printf("%d\n",vet[i]);

	}






 return 0;
}
