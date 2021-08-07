#include<stdio.h>

typedef struct{
	int data[100];
	int size;
}List;

typedef struct{
	int A[500][100];
	int n;
}Graph;

void init_graph(Graph* G, int n){
	int i, j;
	G->n = n;
	for(i = 1; i <= G->n; i++)
		for(j = 1; j <= G->n; j++)
			G->A[i][j] = -1;
}

void add_edge(Graph* G, int x, int y, int w){
	G->A[x][y] = w;
}

List neighbors(Graph G, int x){
	int y;
	List L;
	L.size = 0;
	for(y = 1; y <= G.n; y++)
		if(G.A[x][y] > 0)
		{
			L.data[L.size] = y;
			L.size++;
		}
	return L;
}

int mark[100], pi[100];

int choose(Graph G){
	int i, index = 0, min = 999;
	for(i = 1; i <= G.n; i++)
		if(pi[i] < min && mark[i] == 0)
		{
			min = pi[i];
			index = i;
		}
	return index;
}

void dijkstra(Graph G, int u){
	int i, j;
	for(i = 1; i <= G.n; i++)
	{
		mark[i] = 0;
		pi[i] = 999;
	}
	pi[u] = 0;
	for(i = 1; i <= G.n; i++)
	{
		int e = choose(G);
		mark[e] = 1;
		List lst = neighbors(G, e);
		for(j = 1; j <= lst.size; j++)
		{
			int y = lst.data[j - 1];
			if(mark[y] == 0)
				if(G.A[i][y] != -1 && pi[i] + G.A[i][y] < pi[y])
					pi[y] = pi[i] + G.A[i][y];
		}
	}
}

int main(){
	int n, m, u, v, w, i;
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	dijkstra(G, 1);
	if(pi[n] == 999)	pi[n] = -1;
	printf("%d", pi[n]);
	return 0;
}
