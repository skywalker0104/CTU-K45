#include<stdio.h>

typedef struct{
	int data[100];
	int size;
}List;

void make_null(List* L){
	L->size = 0;
}

void push_back(List* L, int x){
	L->data[L->size] = x;
	L->size++;
}

int element_at(List L, int i){
	return L.data[i - 1];
}


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

void add_edge(Graph* G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

List neighbors(Graph* G, int x){
	List L;
	make_null(&L);
	int i;
	for(i = 1; i <= G->n; i++)
		if(G->A[i][x] == 1)
			push_back(&L, i);
	return L;
}

int cycle;
int mark[100];
int parent[100];

void dfs(Graph* G, int x, int p){
	int i;
	parent[x] = p;
	mark[x] = 1;
	List lst = neighbors(G, x);
	for(i = 1; i <= lst.size; i++)
	{
		int y = element_at(lst, i);
		if(mark[y] == 1 && y != parent[x])
		{
			cycle = 1;
			return;
		}
		if(mark[y] == 0)
			dfs(G, y, x);		
	}
}

int contain_cycle(Graph* G){
	int i;
	for(i = 1; i <= G->n; i++)
	{
		mark[i] = 0;
		parent[i] = -1;	
	}
	cycle = 0;
	for(i = 1; i <= G->n; i++)
		if(mark[i] == 0)
			dfs(G, i, 0);
	return cycle;	
}

int main(){	
	Graph G;
	int n, m, i, u, v;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}	
	if(contain_cycle(&G))
		printf("YES");
	else
		printf("NO");
	return 0;
}
