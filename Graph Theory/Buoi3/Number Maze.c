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
			G->A[i][j] = 0;
}

int w[100];

void add_edge(Graph* G, int m, int n){
	int i, j, k, u, v, col, row;
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{
			int di[] = {-1, 1, 0, 0};
			int dj[] = {0, 0, 1, -1};
			for(k = 0; k < 4; k++)
			{
				col = i + di[k];
				row = j + dj[k];
				if(col >= 0 && col < m && row >= 0 && row < n)
				{
					v = col*n + row + 1;
					u = i*n + j + 1;
					G->A[u][v] = w[v];
				}
			}
		}
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
	int i, min = 9999, index = 0;
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
		pi[i] = 9999;
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
			if(mark[y] == 0 && G.A[i][y] != 0)
				if(pi[y] > pi[i] + G.A[i][y])
					pi[y] = pi[i] + G.A[i][y];
		}
	}
}

void Dijkstra(Graph G, int s){
	int i, j;
	for(i = 1; i <= G.n; i++){
		mark[i] = 0;
		pi[i] = 9999;
	}
	pi[s] = w[s];
	for(i = 1; i <= G.n; i++)
	{
		int e = choose(G);
		mark[e] = 1;
		for(j = 1; j <= G.n; j++)
			if(G.A[e][j] != 0 && mark[j] == 0)
				if(pi[e] + G.A[e][j] < pi[j])
					pi[j] = pi[e] + G.A[e][j];
	}
}

int main(){
	int i, j, n, m, u;
	Graph G;
	scanf("%d%d", &m, &n);
	init_graph(&G, n*m);
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{
			scanf("%d", &u);
			w[i*n+j+1] = u;		
		}
	add_edge(&G, m, n);
	Dijkstra(G, 1);
	if(pi[G.n] == 9999)	pi[G.n] = -1;
	printf("%d", pi[G.n]);
	return 0;
}
