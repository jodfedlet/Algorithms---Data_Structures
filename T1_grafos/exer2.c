#include <stdio.h>
#include <string.h>
#define INF 100000000

int adjacent_visit(int MatrizG[][10], int vis[],int line, int n){
  vis[line] = 1;
  if(line == 6){
    printf("%d //com custo de: ", line+1);
    return 0;
  }
  int v, V, d = INF;
  for(v = 0; v < n; v++){
    if(!vis[v] && MatrizG[line][v] > 0 && MatrizG[line][v] < d){
      d = MatrizG[line][v];
      V = v;
    }
  }
  printf("%d -> ", line+1);
  return d + adjacent_visit(MatrizG, vis, V, n);
}

int visita_in(int MatrizG[][10], int vis[], int line, int n, int m){
  vis[line] = 1;
  if(line == 6){
    printf("%d //com custo de: ", line+1);
    return 0;
  }
  int v, V, d = INF,j,J;
  for(j = 0; j < m; j++)
    if(MatrizG[line][j] > 0)
      for(v = 0; v < n; v++)
	if(!vis[v] && MatrizG[v][j] && MatrizG[line][j] < d){
	  d = MatrizG[line][j];
	  V = v;
	  J = j;
	}
  printf("%d (%c)-> ", line+1, 'a'+J);
  return d + visita_in(MatrizG, vis, V, n ,m);  
}

int main(){
  int MatrizG[10][10],vis[10],n,m,i,j;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      scanf("%d", &MatrizG[i][j]);
  memset(vis, 0, sizeof(vis));
  printf("\nadjacente:\n");
  printf("%d\n", adjacent_visit(MatrizG, vis, 0, n));
  scanf("%d %d", &n, &m);
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
      scanf("%d", &MatrizG[i][j]);
  memset(vis, 0, sizeof(vis));
  printf("incidencia:\n");
  printf("%d", visita_in(MatrizG, vis, 0, n, m));
  printf("\n");
  return 0;
}
