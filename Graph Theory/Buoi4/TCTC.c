#include<stdio.h>

typedef struct{
	int data[100];
	int front, rear;
}Queue;

void make_null(Queue* Q){
	Q->front = 0;
	Q->rear = -1;
}

void push(Queue *Q, int x){
	Q->rear++;
	Q->data[Q->rear] = x;
}

int top(Queue Q){
	return Q.data[Q.front];
}

int pop(Queue* Q){
	return Q->front++;
}

int empty(Queue Q){
	return Q.front > Q.rear;
}

typedef struct{
	int data[100];
	int size;
}List;

typedef struct{
	int A[500][100];
	int n;
}Graph;

List neighbors(Graph G, int x){
	int y;
	List L;
	L.size = 0;
	for(y = 1; y <= G.n; y++)
		if(G.A[x][y] > 0)
		{
			L.data[L.size] = y;
			L.size++;
		}
	return L;
}

int max(int a, int b){
	if(a > b)	return a;
	else return b;
}

int min(int a, int b){
	if(a < b)	return a;
	else return b;
}

List L;

void topo_sort(Graph G){
	Queue Q;
	make_null(&Q);
	L.size = 0;
	int i, j, d[100];
	for(i = 1; i <= G.n; i++)
		d[i] = 0;
	for(i = 1; i <= G.n; i++)
		for(j = 1; j <= G.n; j++)
			if(G.A[i][j] > 0)
				d[j]++;
	for(i = 1; i <= G.n; i++)
		if(d[i] == 0)
			push(&Q, i);
	while(!empty(Q))
	{
		int x = top(Q); pop(&Q);
		printf("%d ", x);
		L.data[L.size] = x;
		L.size++;
		List lst = neighbors(G, x);
		for(i = 1; i <= lst.size; i++)
		{
			int y = lst.data[i - 1];
			d[y]--;
			if(d[y] == 0)
				push(&Q, y);
		}
	}
}

int main(){
	int i, j, n, x, d[100];
	Graph G;
	freopen("DuAnXayNha.txt", "r", stdin);
	scanf("%d", &n);
	G.n = n + 2;
	d[n + 1] = 0;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
		do{
			scanf("%d", &x);
			if(x > 0)
				G.A[x][i] = 1;
		}while(x > 0);
	}
	
	for(i = 1; i <= n; i++)
	{
		int deg_alpha = 0;
		for(j = 1; j <= n; j++)
			if(G.A[j][i] == 1)
				deg_alpha = 1;
		if(deg_alpha == 0)
			G.A[n+1][i] = 1;
	}
	
	for(i = 1; i <= n; i++)
	{
		int deg_beta = 0;
		for(j = 1; j <= n; j++)
			if(G.A[i][j] == 1)
				deg_beta = 1;
		if(deg_beta == 0)
			G.A[i][n+2] = 1;
	}
	
	topo_sort(G);
	
	int t[100];
	t[n + 1] = 0;
	for(i = 1; i <= L.size; i++)
	{
		int x = L.data[i - 1];
		t[x] = 0;
		for(j = 1; j <= G.n; j++)
			if(G.A[j][x] == 1)
				t[x] = max(t[x], t[j] + d[j]);
	}
	
	int T[100];
	T[n + 2] = t[n + 2];
	for(i = L.size - 1; i >= 1; i--)
	{
		int y = L.data[i - 1];
		T[y] = 99999;
		for(j = 1; j <= G.n; j++)
			if(G.A[y][j] == 1)
				T[y] = min(T[y], T[j] - d[y]);
	}
	printf("%d\n", t[n+2]);
	for(i = 1; i <= G.n; i++)
		printf("%d-%d\n", t[i], T[i]);
	return 0;
}
