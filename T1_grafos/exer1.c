#include <stdio.h>
#include <string.h>
#define INF 100000



int adjacent_visit(int MatrizG[][10], int vis[],int line, int k){
  vis[line] = 1;
  int i, V, d = INF;
  for(i = 0; i < k; i++){
    if(!vis[i] && MatrizG[line][i] > 0 && MatrizG[line][i] < d){
      d = MatrizG[line][i];
      V = i;
    }
  }
  if(d == INF){
    printf("%d // com custo de: ", line+1);
    return 0;
  }
  printf("%d -> ", line+1);
  return d + adjacent_visit(MatrizG, vis, V, k);
}

int incident_visit(int MatrizG[][10], int vis[], int line, int n, int m){
  vis[line] = 1;
  int v, V, d = INF,j,J;
  for(j = 0; j < m; j++)
    if(MatrizG[line][j] > 0)
      for(v = 0; v < n; v++)
	if(!vis[v] && MatrizG[v][j] && MatrizG[line][j] < d){
	  d = MatrizG[line][j];
	  V = v;
	  J = j;
	}
  if(d == INF){
    printf("%d // com custo de: ", line+1);
    return 0;
  }
  printf("%d (%c)-> ", line+1, 'a'+J);
  return d + incident_visit(MatrizG, vis, V, n ,m);  
}

int main(){
  
  int MatrizG[10][10],vis[10],n,m,i,j;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      scanf("%d", &MatrizG[i][j]);
  memset(vis, 0, sizeof(vis));
  printf("\nAdjacente:\n");
  printf("%d\n", adjacent_visit(MatrizG, vis, 0, n));

  scanf("%d %d", &n, &m);
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
      scanf("%d", &MatrizG[i][j]);
  memset(vis, 0, sizeof(vis));
  printf("\nIncidência:\n");
  printf("%d", incident_visit(MatrizG, vis, 0, n, m));
  printf("\n\n");
  return 0;
}
