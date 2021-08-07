#include<stdio.h>

typedef struct{
	int data[500];
	int size;
}List;

void makeNull(List* L){
	L->size = 0;
}

void pushBack(List* L, int x){
	L->data[L->size] = x;
	L->size++;
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

void add_edge(Graph* G, int x, int y, int w){
	G->A[x][y] = w;
	G->A[y][x] = w;
}

List neighbors(Graph* G, int x){
	int y;
	List L;
	makeNull(&L);
	for(y = 1; y <= G->n; y++)
		if(G->A[x][y] > 0)
			pushBack(&L, y);
	return L;
}

int mark[100], pi[100];

int choose(Graph* G){
	int i, index, min = 9999;
	for(i = 1; i <= G->n; i++)
		if(mark[i] == 0 && pi[i] < min)
		{
			min = pi[i];
			index = i;
		}
	return index;
}

void dijkstra(Graph* G, int s) {
	int i, j;
	for (i = 1; i <= G->n; i++)
	{
		pi[i] = 9999;
		mark[i] = 0;
	}
	pi[s] = 0;
	for (i = 1; i < G->n; i++) 
	{
		int e = choose(G);
		mark[e] = 1;
		List lst = neighbors(G, e);
		for (j = 1; j <= lst.size; j++)
		{
			int y = lst.data[j - 1];
			if (G->A[i][y] != 0 &&  mark[y] == 0)
				if (pi[i] + G->A[i][y] < pi[y])
					pi[y] = pi[i] + G->A[i][y];
		}
	}
}

int main(){
//	freopen("dt.txt", "r", stdin);
	Graph G;
	int n, m, u, v, w, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	dijkstra(&G,1);
	if(pi[n] == 9999)	pi[n] = -1;
	printf("%d", pi[n]);
	return 0;
}
