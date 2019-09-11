#include<stdio.h>
#include<string.h>
int main(){
 char algo[15];
 int i,tam,c,cont=0;
 scanf("%s",algo);
 tam=strlen(algo);
 c='a';
 for(i=0;i<=tam;i++){
  if(algo[i]==c){
     cont++;
  }
 }
 printf("%d\n",cont);



 return 0;
}
