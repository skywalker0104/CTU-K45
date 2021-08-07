#include<stdio.h>

typedef struct{
	int data[100];
	int size;
}Stack;

void make_null(Stack *S){
	S->size = 0;
}

void push(Stack *S, int x){
	S->data[S->size] = x;
	S->size++;
}

int top(Stack *S){
	S->size--;
	return S->data[S->size];
}

int empty(Stack S){
	return S.size == 0;
}

typedef struct{
	int A[100][500];
	int n, m;
}Graph;

typedef struct{
	int data[100];
	int size;
}List;

List neighbors(Graph G, int x){
	int y;
	List L;
	L.size = 0;
	for(y = 1; y <= G.n; y++)
		if(G.A[x][y] == 1)
		{
			L.data[L.size] = y;
			L.size++;
		}
	return L;
}

int mark[100], parent[100];

void DFS(Graph G, int u){
	Stack S;
	make_null(&S);
	push(&S, u);
	while(!empty(S))
	{
		int x = top(&S);
		if(mark[x] == 1)
			continue;
		mark[x] = 1;
		List lst = neighbors(G, x);
		int i;
		for(i = 0; i < lst.size; i++)
		{
			int y = lst.data[i];
			if(mark[y] == 0)
			{
				push(&S, y);
				parent[y] = x;				
			}
		}
	}
}

int main(){
	int n, m, u, v, i;
	scanf("%d%d", &n, &m);
	Graph G;
	G.n = n;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		G.A[u][v] = 1;
		G.A[v][u] = 1;
	}
	for(i = 1; i <= n; i++)
	{
		mark[i] = 0;
		parent[i] = 0;		
	}
	for(i = 1; i <= n; i++)
		if(mark[i] == 0)
			DFS(G, i);
	for(i = 1; i <= n; i++)
		printf("%d %d\n", i, parent[i]);
	return 0;
}
