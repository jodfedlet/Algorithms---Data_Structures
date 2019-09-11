#include<stdio.h>

	int main(){
	int a,b,cont,i,p=0;
	scanf("%d %d",&a,&b);
	for( ;a<=b;a++){

	  for(i=1;i<=a;i++){
	    if(a%i==0)
		cont++;
	   }
	  if(cont==2){
	    if(a==(p+2)){
	      printf("%d %d\n",p,a);
	    }
	   p=a;
	  }
        cont=0;
       }





	return 0;
}
