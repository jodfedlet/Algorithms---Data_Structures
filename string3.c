#include<stdio.h>
#include<string.h>
int main(){


 char palavra[30],novpalavra[30];
 printf("Informe a palavra:");
	scanf("%s", palavra);
	for(int i=0, j=strlen(palavra)-1;j>=0;j--,i++){
		novpalavra[j]=palavra[i];

	}

	palavra = novpalavra;
	
	novpalavra[strlen(palavra)] = '\0';
	printf("%s %s\n",palavra, novpalavra);

	return 0;

	
}
