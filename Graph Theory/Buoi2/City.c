#include<stdio.h>

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

typedef struct{
	int A[500][100];
	int n, m;
}Graph;

void init_graph(Graph* G, int n, int m){
	int i, j;
	G->n = n;
	G->m = m;
	for(i = 1; i <= G->n; i++)
		for(j = 1; j <= G->m; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph* G, int e, int x, int y){
	G->A[x][e] = 1;
	G->A[y][e] = -1;
}

int adjacent(Graph* G, int x, int y){
	int i, j;
	for(i = 1; i <= G->m; i++)
		for(j = 1; j <= G->m; j++)
		if((G->A[x][i] == 1 && G->A[y][i] == -1)||(G->A[x][j] == 1 && G->A[y][j] == -1))
			return 1;
	return 0;
}

List neighbors(Graph* G, int x){
	int i;
	List L;
	make_null(&L);
	for(i = 1; i <= G->n; i++)
	{
		if(adjacent(G, x, i) && i != x)
			push_back(&L, i);
	}
	return L;
}

typedef struct{
	int data[100];
	int size;
}Stack;

void make_null_stack(Stack* S){
	S->size = 0;
}

void push(Stack* S, int x){
	S->data[S->size] = x;
	S->size++;
}

int top(Stack* S){
	return S->data[S->size - 1];
}

void pop(Stack* S){
	S->size--;
}

int empty(Stack* S){
	return S->size == 0;
}

int get_min(int a, int b){
	if(a < b)
		return a;
	else return b;
}

int connect = 0, idx = 1;
int num[100], min_num[100], on_stack[100];
Stack S;

void strong_connect(Graph* G, int x){
	int i;	
	num[x] = min_num[x] = idx; idx++;
	push(&S, x);
	on_stack[x] = 1;
	List lst = neighbors(G, x);
	for(i = 1; i <= lst.size; i++)
	{
		int y = element_at(&lst, i);
		if(num[y] < 0)
		{
			strong_connect(G, y);
			min_num[x] = get_min(min_num[x], min_num[y]);	
		}
		else if(on_stack[y])
			min_num[x] = get_min(min_num[x], num[y]);		
	}
	if(num[x] == min_num[x])
	{
			connect++;	
			int w;
			do
			{
				w = top(&S); pop(&S);
				on_stack[w] = 0;				
			}
			while(w != x);
	}	
}


int main(){
	Graph G;
	int n, m, u, v, i, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n, m);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &e, &u, &v);
		add_edge(&G, e, u, v);
	}
	for(i = 1; i <= n; i++)
	{
		num[i] = -1;
		on_stack[i] = 0;		
	}
	idx = 1;
	make_null_stack(&S);
	for(i = 1; i <= n; i++)
		if(num[i] == -1)
			strong_connect(&G, i);
	if(connect == 1)
		printf("OKIE");
	else printf("NO");
	return 0;
}
