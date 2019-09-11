#include <stdio.h>

void encontraCaminho(int v[100][100], int inicio[2]){
  int x = inicio[1], y = inicio[0];
  int aux_x, aux_y;
  while(x != 0 && y != 0){
    printf("%d %d\n", x, y);
    for(int i = -1; i <= 1; i++)
      for(int j = -1; j <= 1; j++){
	if(x + i < 100 && x + i >= 0 && y + j < 100 && y + j >= 0){
	  if(m[x + i][y + j] != 0 && m[x + i][y + j] < m[x][y]){
	    aux_x = x + i;
	    aux_y = y + j;
	    break;
	  }
	}	  
      }
    x = aux_x;
    y = aux_y;
  }
  printf("%d %d\n", x, y);
}

int main(void){
  
  return 0;
}
