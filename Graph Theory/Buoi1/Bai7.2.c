#include<stdio.h>

typedef struct{
	int A[500][100];
	int n;
}Graph;

typedef struct{
	int Data[100];
	int size;
}List;

void make_null(List* L){
	L->size = 0;
}

void push_back(List* L, int x){
	L->Data[L->size] = x;
	L->size++;
}

int element_at(List* L, int i){
	return L->Data[i - 1];
}

int count_list(List* L){
	return L->size;
}

void add_edge(Graph* G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

int same_enemies(Graph G, int n, int x, int y){
	int i;
	int count = 0;
	for(i = 1; i <= n; i++)
		if(G.A[x][i] == 1 && G.A[y][i] == 1)
			count++;			
	return count;
}

int main(){
	Graph G;
	int n, e, x, y;
	freopen("HeSinhThaiRung.txt", "r", stdin);
	scanf("%d", &n);
	int i;
	for(e = 1; e <= n; e++)
		for(i = 1; i <= n; i++)
			scanf("%d", &G.A[e][i]);
	scanf("%d%d", &x, &y);
	printf("%d", same_enemies(G, n, x, y));
	return 0;
}
