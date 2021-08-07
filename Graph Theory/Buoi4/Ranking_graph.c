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

void add_edge(Graph* G, int x, int y){
	G->A[x][y] = 1;
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

int degree(Graph G, int x){
	int y, deg = 0;
	for(y = 1; y <= G.n; y++)
		deg += G.A[y][x];
	return deg;
}

void copy_list(List *S1, List *S2){
	int i, x;
	S1->size = 0;
	for(i = 1; i <= S2->size; i++)
	{
		x = S2->data[i - 1];
		S1->data[S1->size] = x;
		S1->size++;
	}
}


int d[100], k = 0, rank[100];
List S1, S2;

void rank_edge(Graph G){
	int i;
	S1.size = 0;
	for(i = 1; i <= G.n; i++)
		d[i] = degree(G, i);
	
	for(i = 1; i <= G.n; i++)
		if(d[i] == 0)
		{
			S1.data[S1.size] = i;
			S1.size++;
		}

	while(S1.size > 0)
	{
		S2.size = 0;
		for(i = 1; i <= S1.size; i++)
		{
			int x = S1.data[i - 1];
			rank[x] = k;
			List lst = neighbors(G, x);
			int j;
			for(j = 1; j <= lst.size; j++)
			{
				int y = lst.data[j - 1];
				d[y]--;
				if(d[y] == 0)
				{
					S2.data[S2.size] = y;
					S2.size++;
				}
			}
		}
		copy_list(&S1, &S2);
		k++;
	}
}

int main(){
	Graph G;
	int n, m, u, v, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	rank_edge(G);
	for(i = 1; i <= n; i++)
		printf("%d ", rank[i]);
	return 0;
}
