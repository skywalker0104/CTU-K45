#include<stdio.h>

typedef struct{
	int x, y, w;
}Edge;

typedef struct{
	Edge A[100];
	int n, m;
}Graph;

void init_graph(Graph* G, int n){
	G->m = 0;
	G->n = n;
}

void add_edge(Graph *G, int x, int y, int w){
	G->A[G->m].x = x;
	G->A[G->m].y = y;
	G->A[G->m].w = w;
	G->m++;
}

void sort(Graph *G){
	int i, j;
	Edge t;
	for(i = 0; i < G->m; i++)
	{
		for(j = i+1; j < G->m; j++)
			if(G->A[i].w > G->A[j].w)
			{ 
				t = G->A[i];
				G->A[i] = G->A[j];
				G->A[j] = t;
			}
	}
}

int parent[100];
int find_root(int u){
	if (parent[u] == u)
		return u;
	return find_root(parent[u]);
}

int yes;

int kruskal(Graph *G, Graph *T){
	int i;
	sort(G);
	init_graph(T, G->n);	
	for(i = 1; i <= G->n; i++)
		parent[i] = i;
	int sum = 0;	
	for(i = 0; i < G->m; i++)
	{
		int u = G->A[i].x;
		int v = G->A[i].y;
		int w = G->A[i].w;
		int u1 = find_root(u);
		int v1 = find_root(v);
		if(u1 != v1)
		{
			yes = 1;
			if(u < v)	add_edge(T, u, v, w);
			else	add_edge(T, v, u, w);
			parent[v1] = u1;
			sum += w;
		}
		else yes = 0;
	}
	return sum;
}

int main(){
	Graph G;
	int n, m, u, v, w, r, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d%d", &u, &v, &w, &r);
		add_edge(&G, u, v, w*r);
	}
	Graph T;
	yes = 0;
	int sum = kruskal(&G, &T);
	if(yes != 1)
	printf("%d\n", sum);
	else printf("KHONG CO LOI GIAI");
	return 0;
}
