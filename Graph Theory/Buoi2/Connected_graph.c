#include<stdio.h>

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

void DFS(Graph G, int u, int p){
	if(mark[u] == 1)
		return;
	mark[u] = 1;
	parent[u] = p;
	List lst = neighbors(G, u);
	int i;
	for(i = 0; i < lst.size; i++)
	{
		int y = lst.data[i];
		if(mark[y] == 0)
			DFS(G, y, u);
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
		mark[i] = 0;
	DFS(G, 1, 0);
	int check = 0;
	for(i = 1; i <= n; i++)
		if(mark[i] == 0)
		{
			check = 1;
			break;
		}
	if(check == 1)	printf("NO");
	else	printf("YES");
	return 0;
}
