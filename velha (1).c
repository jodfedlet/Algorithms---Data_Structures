#include <stdio.h>

int ganhou(char m[][3], char marca){
	int i, j, cont;	
	for(i = 0, cont; i < 3; i++){
		cont = 0;		
		for(j = 0; j < 3; j++){
			if(m[i][j] == marca)
				cont++;
		}
		if(cont == 3)
			return 1;
	}

	for(i = 0, cont; i < 3; i++){
		cont = 0;		
		for(j = 0; j < 3; j++){
			if(m[j][i] == marca)
				cont++;
		}
		if(cont == 3)
			return 1;
	}

	for(i = 0, j = 0, cont = 0; i < 3; i++, j++){
		if(m[i][j] == marca)
			cont++;
	}
	if(cont == 3)
		return 1;
	for(i = 3, j = 0; j < 3; j++, i--)
		if(m[i][j] == marca)
			cont++;
	if(cont == 3)
		return 1;

	return 0;
}

int main(void){
	char m[3][3], j[2] = {'X', 'O'};
	int l, c, i, jg;	
	for(i = 0, jg = 1; i < 9; i++){
		printf("Jogador %d, digite linha e coluna para o jogo: ", jg);
		scanf("%d %d", &l, &c);
		m[l][c] = j[jg];
		if(ganhou(m, j[jg]) == 1) break;
		if(jg == 1)
			jg = 0;
		else
			jg = 1;
	}
	printf("O jogador %d Ganhou!\n", jg);
	return 0;
}
