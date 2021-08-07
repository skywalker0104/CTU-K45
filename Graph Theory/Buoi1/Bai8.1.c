#include<stdio.h>

typedef struct{
	int A[500][100];
	int n, m;
}Graph;

void init_graph(Graph* G, int n, int m){
	int i, j;
	G->n = n;
	G->m = m;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph* G, int e, int x, int y){
	G->A[x][e] = 1;
	G->A[y][e] = 1;
}

int degree(Graph* G, int x){
	int i, deg = 0;
	for(i = 1; i <= G->m; i++)
		if(G->A[x][i] == 1)
			deg++;
	return deg;
}

int main(){
	Graph G;
	int n, m, i, a, b;
	scanf("%d%d", &n, &m);
	init_graph(&G, n, m);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		add_edge(&G, i, a, b);
	}
	for(i = 1; i <= n; i++)
	{
		printf("%d\n", degree(&G, i));
	}
	return 0;
}
