#include <stdio.h>

int main(){
	int ii, is,i,j;
	scanf("%d %d", &ii, &is);
	if(ii>is){
		int a = ii;
		ii = is;
		is = a;
	}
	while(++ii < is){
		int primo = 1;
		for(i = 2; i < ii && primo == 1; i++){
			if(ii % i == 0){
				primo = 0;
			}
		}
		if(primo == 1){
			printf("%d\n", ii);
		}
	}
	return 0;
}
