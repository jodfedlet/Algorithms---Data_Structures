#include <stdio.h>

int main(void){
  int nprimo = 2, div, i, num;
  scanf("%d", &num);
  while(num > 1){
    for(div = 0, i = 1; i <= nprimo; i++)
      if(nprimo % i == 0)
	div++;
    if(div == 2){
      while(num % nprimo == 0 && num > 1){
	num = num / nprimo;
	if(num != 1){
	  printf("%d*", nprimo);
	}else{
	  printf("%d", nprimo);
	}
      }
    }
    nprimo++;
  }
  printf("\n");

  return 0;
}
