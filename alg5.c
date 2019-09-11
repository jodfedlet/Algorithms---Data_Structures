#include<stdio.h>

int main(){
	int i,a,b,primo, x, y;
	scanf("%d %d",&a,&b);
	if(a>b){
 	int aux=a;
  a=b;
  b=aux;
	}
	x = y = 0;
	while(++a<b){
	primo=0;
	 for(i=1;i<=a;i++){
		if(a%i==0)
		primo++;		
	}
	if(primo==2){
  	if(x==0){
			x=a;
		}
		else{
			y=a;	
		}
	}
	if(x!=0 && y!=0){
	  if(y-x==2){
			printf("%d %d\n",x,y);
		}
		x = y;
	}
}


return 0;
}
