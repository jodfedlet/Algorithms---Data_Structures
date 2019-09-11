#include<stdio.h>
#include<string.h>
int main(){
	int n,tam;
	scanf("%d",&n);
	char st2[n+2],letra;
	
  scanf("%s %c", st2,&letra);
	tam=strlen(st2);
	for(int i=0;i<=tam;i++){
		if(letra==st2[i]){
			printf("%d\n",i);
			return 0;
		}
	}

	printf("Esse caracter nao esta na String\n");

	return 0;
}
