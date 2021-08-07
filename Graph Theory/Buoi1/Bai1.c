#include<stdio.h>

typedef struct{
	int A[100][500];
	int n;
}Graph;

void add_edge(Graph* G, int e, int x, int y){
	G->A[x][e] = 1;
	G->A[y][e] = 1;
}

int deg(Graph* G, int x){
	int i, count = 0;
	for(i = 1; i <= G->n; i++)
		if(G->A[x][i] == 1)
			count++;
	return count;
}

int main(){
	
	return 0;
}
