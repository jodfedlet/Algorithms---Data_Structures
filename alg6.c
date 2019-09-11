#include<stdio.h>

int main (){
	int n,i,val,m, cont=0;
	scanf("%d",&n);
	if(n>0){
	scanf("%d",&val);
	m=val;
 	cont++;
	}
	for(i=0;i<n-1;i++){
	scanf("%d",&val);
	if(val==m){
	cont++;
	}

	if(val>m){
		m=val;
		cont = 1;
	}


	}

	printf("%d\n", cont);




}
