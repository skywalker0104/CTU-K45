#include<stdio.h>

typedef struct{
	int A[500][100];
	int n, m;
}Graph;

void init_graph(Graph* G, int n, int m){
	int i, j;
	G->m = m;
	G->n = n;
	for(i = 1; i <= G->n; i++)
		for(j = 1; j <= G->m; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph* G, int e, int x, int y){
	G->A[x][e] = 1;
	G->A[y][e] = -1;
}

void most_received(Graph* G, int n){
	int i, j, A[100];
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			A[i] = A[i] + G->A[i][j];
	int max = A[1], max_index = 1;
	for(i = 2; i <= n; i++)
		if(A[i] > max)
		{
			max = A[i];
			max_index = i;
		}
	printf("%d has received %d email(s).", max_index, max);
}

int degree(Graph* G, int x){
	int i, deg = 0;
	for(i = 1; i <= G->m; i++)
		if(G->A[x][i] == 1)
			deg++;
	return deg;
}

void most_sented(Graph G, int n){
	int i, max = 0, max_index;
	for(i = 1; i <= n; i++)
		if(degree(&G, i) > max)
		{
			max = degree(&G, i);
			max_index = i;
		}
	printf("%d has sent %d email(s).", max_index, max);
}

int main(){
	Graph G;
	int n, m, i, x, y;
	scanf("%d%d", &n, &m);
	init_graph(&G, n, m);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		add_edge(&G, i, x, y);		
	}
	most_sented(G, n);
	return 0;
}
