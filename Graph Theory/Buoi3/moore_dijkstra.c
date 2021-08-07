#include<stdio.h>

typedef struct {
	int data[100];
	int size;
}List;

typedef struct {
	int A[100][500];
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

int mark[100], pi[100];

int choose(Graph G){
	int i, max = -1, index = 0;
	for(i = 1; i <= G.n; i++)
		if(mark[i] == 0 && pi[i] > max)
		{
			max = pi[i];
			index = i;
		}
	return index;
}

void sp(Graph G, int u){
	int i, j;
	for(i = 1; i <= G.n; i++)
	{
		mark[i] = 0;
		pi[i] = -1;
	}
	pi[u] = 0;
	for(i = 1; i <= G.n; i++)
	{
		List lst = neighbors(G, i);
		int e = choose(G);
		mark[e] = 1;
		for(j = 1; j <= lst.size; j++)
		{
			int y = lst.data[j - 1];
			if(G.A[i][y] != 0 && mark[y] == 0)
				if(pi[i] + G.A[i][y] > pi[y])
				{
					pi[y] = pi[i] + G.A[i][y];	
				}
		}
	}
}

int main(){
	Graph G;
	int n, m, a, b, c, i;
	scanf("%d%d", &n, &m);
	G.n = n;
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		G.A[a][b] = c;
		G.A[b][a] = c;
	}
	sp(G, 1);
	for(i = 1; i <= G.n; i++)
	printf("%d\n", pi[i]);
	return 0;
}
