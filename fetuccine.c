#include <stdio.h>

int main(void){
	int i, n, imenos1, imenos2;
	scanf("%d %d", &imenos2, &imenos1);
	scanf("%d", &n);

	printf("%d, %d, ", imenos1, imenos2);
	for(i = 3; i <= n; i++){
		if(i % 2 == 0){
			printf("%d, ", imenos1 - imenos2);
			int aux = imenos2;
			imenos2 = imenos1;
			imenos1 = imenos1 - aux;		
		}else{
			printf("%d, ", imenos1 + imenos2);
			int aux = imenos2;
			imenos2 = imenos1;
			imenos1 = imenos1 + aux;
		}
	}
	printf("\n");

	return 0;
}
