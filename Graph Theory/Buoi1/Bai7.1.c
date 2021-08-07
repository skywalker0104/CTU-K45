#include<stdio.h>

typedef struct{
	int A[500][100];
	int n;
}Graph;

#define MAX_ELEMENTS 100

typedef int ElementType;
typedef struct {
ElementType data[MAX_ELEMENTS];
int size;
} List;

void make_null(List* L) {
	L->size = 0;
}

void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}

ElementType element_at(List* L, int i) {
	return L->data[i-1];
}

int count_list(List* L) {
	return L->size;
}

void init_graph(Graph* G, int n){
	int i, j;
	G->n = n;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			G->A[i][j];
}

void add_edge(Graph* G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

List same_enemies(Graph G, int x, int y){
	int i;
	List L;
	make_null(&L);
	for(i = 1; i <= G.n; i++)
		if(G.A[x][i] == 1 && G.A[y][i] == 1)
			push_back(&L, i);			
	return L;
}

int main(){
	Graph G;
	int n, m, u, v, e, x, y;
	freopen("HeSinhThaiRung.txt", "r", stdin); //Khi n?p bài nh? b? dòng này
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(e = 0; e < m; e++)
	{
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	scanf("%d%d", &x, &y);
	List L = same_enemies(G, x, y);
	int i;
	if(L.size > 0)
		for(i = 0; i < L.size; i++)
			printf("%d ",L.data[i]);
	else printf("KHONG CHUNG DOI THU");
	return 0;
}
