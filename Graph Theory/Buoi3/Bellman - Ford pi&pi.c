#include<stdio.h>

typedef struct{
	int data[100];
	int size;
}List;

typedef struct{
	int A[500][100];
	int n, m;
}Graph;

void init_graph(Graph* G, int n, int m){
	int i, j;
	G->n = n;
	G->m = m;
	for(i = 1; i <= G->n; i++)
		for(j = 1; j <= G->m; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph* G, int x, int y, int w){
	G->A[x][y] = w;
}

List neighbors(Graph G, int x){
	List L;
	L.size = 0;
	int i;
	for(i = 1; i <= G.n; i++)
		if(G.A[x][i] != 0)
		{
			L.data[L.size] = i;
			L.size++;
		}
	return L;
}

int pi[100], p[100];

void bellman_ford(Graph G, int u){
	int i, j, e;
	for(e = 1; e <= G.n; e++)
		pi[e] = 9999;
	pi[u] = 0;
	p[u] = -1;
	for(e = 1; e <= G.m; e++)
		for(i = 1; i <= G.n; i++)
		{
			List lst = neighbors(G, i);
			for(j = 1; j <= lst.size; j++)
			{
				int y = lst.data[j - 1];
				if(pi[i] + G.A[i][y] < pi[y])
				{
					pi[y] = pi[i] + G.A[i][y];
					p[y] = i;
				}
			}
		}
}

int main(){
	int n, m, u, v, w, i;
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n, m);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	bellman_ford(G, 1);
	for(i = 1; i <= n; i++)
	{
		printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
	}
	return 0;
}
