#include<stdio.h>

typedef struct{
	int data[100];
	int size;
}Stack;

void make_null(Stack* S){
	S->size = 0;
}

void push(Stack* S, int x){
	S->data[S->size] = x;
	S->size++;
}

int top(Stack* S){
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

int min(int a, int b){
	if(a < b)	return a;
	else return b;
}

int mark[100], parent[100], idx = 1, connect = 0, num[100], min_num[100];
Stack S;

void DFS(Graph G, int x){
	num[x] = min_num[x] = idx; idx++;
	push(&S, x);
	mark[x] = 1;
	List lst = neighbors(G, x);
	int i;
	for(i = 0; i < lst.size; i++)
	{
		int y = lst.data[i];
		if(num[y] < 0)
		{
			DFS(G, y);
			min_num[x] = min(min_num[x], min_num[y]);			
		}
		else if(mark[y])
			min_num[x] = min(min_num[x], num[y]);
	}
	if(num[x] == min_num[x])
	{
		connect++;
		int w;
		do
		{
			w = top(&S);
			mark[w] = 0;
		}
		while(w != x);
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
	}
	for(i = 1; i <= n; i++)
	{
		mark[i] = 0;
		num[i] = -1;		
	}
	idx = 1;
	make_null(&S);
	for(i = 1; i <= n; i++)
		if(num[i] == -1)
			DFS(G, i);
	if(connect == 1)	printf("strong connected");
	else printf("unconnected");
	return 0;
}
