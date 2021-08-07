#include<stdio.h>

typedef struct{
	int A[100][500];
	int n, m;
}Graph;

void init_graph(Graph* G, int n){
	int i, j;
	G->n = n;
	for(i = 1; i <= G->n; i++)
		for(j = 1; j <= G->n; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph* G, int x, int y, int w){
	G->A[x][y] = w;
}

int pi[500][500];

void floyd_warshall(Graph G){
	int i, j, k;
	for(i = 1; i <= G.n; i++)
		for(j = 1; j <= G.n; j++)
			pi[i][j] = 9999;
			
	for(i = 1; i <= G.n; i++)
		pi[i][i] = 0;

	for(i = 1; i <= G.n; i++)
		for(j = 1; j <= G.n; j++)
			if(G.A[i][j] != 0)
				pi[i][j] = G.A[i][j];
	
	for(k = 1; k <= G.n; k++)
		for(i = 1; i <= G.n; i++)
			for(j = 1; j <= G.n; j++)
				if(pi[i][j] > pi[i][k] + pi[k][j])
					pi[i][j] = pi[i][k] + pi[k][j];
}

int main(){
	int n, m, u, v, w, i, j;
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for(i = 1; i <= m; i++)
	
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	floyd_warshall(G);
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(pi[i][j] >= 9995)	printf("%d -> %d: oo\n", i, j);
			else	printf("%d -> %d: %d\n", i, j, pi[i][j]);
		}
	}
	return 0;
}
