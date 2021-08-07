#include<stdio.h>

typedef struct{
	int A[100][500];
	int n, m;
}Graph;

typedef struct{
	int data[100];
	int n;
}List;

List neighbors(Graph G, int x){
	int y;
	List L;
	L.n = 0;
	for(y = 0; y <= G.n; y++)
		if(G.A[x][y] != 0)
		{
			L.data[L.n] = y;
			L.n++;
		}
	return L;
}

int pi[100], mark[100], p[100];

int choose(Graph G){
	int min = 99999, index = 0, i;
	for(i = 1; i <= G.n; i++)
	{
		if(mark[i] == 0 && pi[i] < min)
		{
			min = pi[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(Graph G, int u){
	int i;
	for(i = 1; i <= G.n; i++)
	{
		mark[i] = 0;
		pi[i] = 99999;
	}
	pi[u] = 0;
	p[u] = -1;
	for(i = 1; i <= G.n; i++)
	{
		int x = choose(G);
		mark[x] = 1;
		List lst = neighbors(G, x);
		int j;
		for(j = 0; j < lst.n; j++)
		{
			int y = lst.data[j];
			if(G.A[x][y] != 0 && mark[y] == 0)
			{
				if(pi[y] > G.A[x][y] + pi[x])
					pi[y] = G.A[x][y] + pi[x];
			}
		}
	}
}

int main(){
	Graph G;
	int n, m, u, v, w, i;
	scanf("%d%d", &n, &m);
	G.n = n;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		G.A[u][v] = w;
		G.A[v][u] = w;
	}
	int s, t;
	scanf("%d%d", &s, &t);
	dijkstra(G, s);
	printf("%d", pi[t]);
	return 0;
}
