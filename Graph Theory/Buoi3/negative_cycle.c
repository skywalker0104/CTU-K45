#include<stdio.h>

typedef struct {
	int data[100];
	int size;
}List;

typedef struct {
	int A[500][100];
	int n;
}Graph;

void init_graph(Graph* G, int n){
	G->n = n;
	int i, j;
	for(i = 1; i <= G->n; i++)
		for(j = 1; j <= G->n; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph* G, int x, int y, int w){
	G->A[x][y] = w;
}

List neighbors(Graph G, int x){
	int y;
	List L;
	L.size = 0;
	for(y = 1; y <= G.n; y++)
		if(G.A[x][y] != 0)
		{
			L.data[L.size] = y;			
			L.size++;
		}
	return L;
}

int mark[100], pi[100], p[100];
int negcycle;

int choose(Graph G){
	int i, min = 9999, index = 0;
	for(i = 1; i <= G.n; i++)
		if(mark[i] == 0 && pi[i] < min)
		{
			min = pi[i];
			index = i;
		}
	return index;
}

void is_negcycle(Graph G, int u){
	int i, j;
	for(i = 1; i <= G.n; i++)
	{
		mark[i] = 0;
		pi[i] = 9999;
		p[i] = -1;
	}
	pi[u] = 0;
	p[u] = 0;
	for(i = 1; i <= G.n; i++)
	{
		int e = choose(G);
		mark[e] = 1;
		List lst = neighbors(G, e);
		for(j = 1; j <= lst.size; j++)
		{
			int y = lst.data[j - 1];
			if(G.A[i][y] != 0 && mark[y] == 0)
				if(pi[i] + G.A[i][y] < pi[y])
				{
					pi[y] = pi[i] + G.A[i][y];
					p[y] = i;		
				}				
			if(G.A[i][y] != 0 && mark[y] == 1 && p[i] != y)
				if(pi[i] + G.A[i][y] < pi[y])				
				{
					negcycle = 1;
					break;
				}
		}
	}
}

int main(){
	Graph G;
	int n, m, u, v, w, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	negcycle = 0;
	is_negcycle(G, 1);
	if(negcycle == 1)	printf("negative cycle");
	else printf("ok");
	return 0;
}
