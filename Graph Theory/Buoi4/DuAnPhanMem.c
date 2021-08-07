#include<stdio.h>

typedef struct{
	int A[100][500];
	int n;
}Graph;

void add_edge(Graph* G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] = -1;
}

typedef struct{
	int data[100];
	int size;
}List;

List L1;
List L2;

void neighbors(Graph G, int x){
	int y;
	L1.size = 0;
	L2.size = 0;
	for(y = 1; y <= G.n; y++)
	{
		if(G.A[x][y] == 1)
		{
			L1.data[L1.size] = y;
			L1.size++;
	 	}
		else if(G.A[x][y] == -1)
		{
			L2.data[L2.size] = y;
			L2.size++;
		}
	}
}

int min(int a, int b){
	if(a < b)	return a;
	else return b;
}

int max(int a, int b){
	if(a > b)	return a;
	else return b;
}

int d[100], t[100], T[100];

void cal(Graph G){
	int i, j;
	for(i = 1; i <= G.n; i++)
	{
		neighbors(G, i);
		for(j = 1; j <= L1.size; j++)
		{
			int y = L1.data[j - 1];
			t[y] = max(t[y], t[i] + d[i]);
		}
	}
	for(i = G.n; i >= 1; i--)
	{
		T[G.n] = t[G.n]; 
		neighbors(G, i);
		for(j = 1; j <= L2.size; j++)
		{
			int y = L2.data[j - 1];
			T[y] = min(T[y], T[i] - d[y]);
		}
	}
}

int main(){
	Graph G;
	int n, u, v, b, a;
	scanf("%d", &n);
	G.n = n+2;
	for(u = 1; u <= n; u++)
	{
		scanf("%d", &d[u]);
		do{
			scanf("%d", &v);
			if(v > 0)	add_edge(&G, v, u);
		}
		while(v > 0);
	}
	add_edge(&G, n+1, 1);
	add_edge(&G, n, n+2);
//	scanf("%d%d", &a, &b);
	for(u = 1; u <= n; u++)
		T[u] = 9999;
	cal(G);
	printf("%d\n", t[n+2]);
	int i;
	for(i = 1; i <= G.n; i++)
	{
		printf("%d-%d\n", t[i], T[i]);
	}
	return 0;
}
