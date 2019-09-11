#include <stdio.h>

int main(){
	int n, p = 1, i, j,k;
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++, p++){
			int primo = 0;			
			for(k=1;k<=p;k++){
				if(p%k==0){
					primo++;
				}
			}
			if(primo==2){
				printf("#");
			}
			else{
					printf("_");
			}
		}
		printf("\n");
	}
	return 0;
}
