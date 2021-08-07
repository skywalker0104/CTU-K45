#include<stdio.h>

typedef struct{
	int dada[100];
	int front, rear;
}Queue;

void make_null(Queue *Q){
	Q->front = 0;
	Q->rear = -1;
}

void push(Queue *Q, int x){
	Q->rear++;
	Q->dada[Q->rear] = x;
}

int top(Queue *Q){
	Q->front++;
	return Q->dada[Q->front-1];
}

int empty(Queue Q){
	return Q.front > Q.rear;
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

void BFS(Graph G, int u){
	Queue Q;
	make_null(&Q);
	push(&Q, u);
	while(!empty(Q))
	{
		int x = top(&Q);
		if(mark[x] == 1)
			continue;
		mark[x] = 1;
		List lst = neighbors(G, x);
		int i;
		for(i = 0; i < lst.size; i++)
		{
			int y = lst.data[i];
			if(mark[y] == 0 && parent[y] == 0)
			{
				push(&Q, y);
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
		parent[i] = 0;
		mark[i] = 0;		
	}
	for(i = 1; i <= n; i++)
		if(mark[i] == 0)
			BFS(G, i);
	for(i = 1; i <= n; i++)
		printf("%d %d\n", i, parent[i]);
	return 0;
}
