#include<stdio.h>

typedef struct{
	int n, m;
	int A[100][500];
}Graph;

typedef struct{
	int x, y, w;
}Edge;

void init_graph(Graph* G, int n){
	G->n = n;
}

void add_edge(Graph *G, int x, int y, int w){
	G->A[x][y] = w;
	G->A[y][x] = w;
}

typedef struct{
	int data[100];
	int size; 
}List;

void push(List *L, int x){
	L->data[L->size] = x;
	L->size++;	
}

int distanceFrom(int u, List L, Graph G){
	int i, min_dist = 99999, min = -1;
	for(i = 0; i < L.size; i++)
	{
		int v = L.data[i];
		if(G.A[u][v] != 0 && G.A[u][v] < min_dist)
		{
			min_dist = G.A[u][v];
			min = v;
		}		
	}
	return min;
}

int mark[100], s = 0;
Edge E[100];

int prim(Graph G, Graph *T){
	int i, u, k = 0;
	init_graph(T, G.n);
	List L;
	L.size = 0;
	for(i = 1; i < G.n; i++)
		mark[i] = 0;
	push(&L, 1);
	mark[1] = 1;
	for(i = 1; i < G.n; i++)
	{
		int min_dist = 99999, min_u, min_v;
		for(u = 1; u <= G.n; u++)
			if(mark[u] == 0)
			{		
				int v = distanceFrom(u, L, G);
				if(v != -1 && G.A[u][v] < min_dist)
				{
					min_dist = G.A[u][v];
					min_u = u;
					min_v = v;
					E[s].x = v;
					E[s].y = u;
					E[s].w = min_dist;
					s++;		
				}
			}
		push(&L, min_u);
		mark[min_u] = 1;
		add_edge(T, min_u, min_v, min_dist);
		k += min_dist;
	}
	return k;
}

int main(){
	Graph G;
	int n, m, u, v, w, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	Graph T;
	int k = prim(G, &T);
	printf("%d\n", k);
	for(i = 0; i < s; i++)
		printf("%d %d %d\n", E[i].x, E[i].y, E[i].w);
	return 0;
}
