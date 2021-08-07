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

int check;
int player[100];

void divide(Graph* G, int x, int t){
	if(player[x] == -1)
	{
		player[x] = t;
		List lst = neighbors(G, x);
		int i;
		for(i = 1; i <= lst.size; i++)
		{
			int y = element_at(lst, i);
			divide(G, y, !t);
		}		
	}
	else if(player[x] != t)
		check = 0;
}

void bigraph(Graph* G){
	int i;
	for(i = 1; i <= G->n; i++)
		player[i] = -1;
	check = 1;
	divide(G, 1, 0);
	int a = 0, b = 0;
	if(check != 0)
	{
		for(i = 1; i <= G->n; i++)
		{
			if(!player[i])
				a++;
			if(player[i])
				b++;			
		}
	}
	printf("%d %d", a, b);
}

int main(){
	Graph G;
	int n, m, u, v, i, j;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	printf("\n");
	bigraph(&G);
	return 0;
}
