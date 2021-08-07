#include<stdio.h>

typedef struct{
	int A[100][500];
	int n, m;
}Graph;

#define MAX_ELEMENTS 100

typedef int ElementType;

typedef struct{
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

void make_null(List* L){
	L->size = 0;
}

void push_back(List* L, ElementType x){
	L->data[L->size] = x;
	L->size++;
}

ElementType element_at(List* L, int i){
	return L->data[i-1];
}

int count_list(List* L){
	return L->size;
}

void add_edge(Graph* G, int e, int x, int y){
	G->A[x][e] = 1;
	G->A[y][e] = 1;
}

void init_graph(Graph* G, int n, int m){
	int i, j;
	G->n = n;
	G->m = m;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
			G->A[i][j] = 0;
	}
}

int adjacent(Graph* G, int x, int y){
	int i;
	for(i = 1; i <= G->m; i++)
	{
		if(G->A[x][i] == 1 && G->A[y][i] == 1)
			return 1;
	}
	return 0;
}

List neighbors(Graph* G, int x){
	int i;
	List L;
	make_null(&L);
	for(i = 1; i <= G->n; i++)
	{
		if(adjacent(G, i, x) && i != x)
		{
			push_back(&L, i);
			printf("%d ", i);			
		}

	}
	return L;
}

int main(){
	Graph G;
	int n = 4, m = 2;
	init_graph(&G, n, m);
	add_edge(&G, 1, 4, 3);
	add_edge(&G, 2, 1, 3);
	List L = neighbors(&G, 3);
	return 0;
}
