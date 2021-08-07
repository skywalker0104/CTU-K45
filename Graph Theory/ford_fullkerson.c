#include<stdio.h>

typedef struct{
    int data[100];
    int rear, front;
}Queue;

void make_null(Queue *Q){
    Q->rear = -1;
    Q->front = 0;
}

void push(Queue *Q, int x){
    Q->rear++;
    Q->data[Q->rear] = x;
}

int top(Queue *Q){
    Q->front++;
    return Q->data[Q->front-1];
}

int empty(Queue Q){
    return Q.front > Q.rear;
}

typedef struct{
    int C[100][100];
    int F[100][100];
    int n;
}Graph;

typedef struct{
    int dir;
    int sigma;
    int pre;
}Label;

void init_flow(Graph *G){
    int u, v;
    for(u = 1; u <= G->n; u++)
        for(v = 1; v <= G->n; v++)
            G->F[u][v] = 0;
}

int min(int a, int b){
    return a < b ? a:b;
}

Label labels[100];

int ford_fullkerson(Graph G, int s, int t){
    int u, v, sumflow = 0;
    init_flow(&G);
    Queue Q;
    do
    {
        for(u = 1; u <= G.n; u++)
           labels[u].dir = 0;
        labels[s].dir = 1;
        labels[s].pre = s;
        labels[s].sigma = 99999;
        make_null(&Q);
        push(&Q, s);
        int found = 0;
        while(!empty(Q))
        {
            int u = top(&Q);
            for(v = 1; v <= G.n; v++)
            {
                if(labels[v].dir == 0 && G.C[u][v] != 0 && G.F[u][v] < G.C[u][v])
                {
                    labels[v].dir = 1;
                    labels[v].pre = u;
                    labels[v].sigma = min(labels[u].sigma, G.C[u][v] - G.F[u][v]);
                    push(&Q, v);
                }
            }
            if(labels[t].dir != 0)
            {
                found = 1;
                break;
            }
        }
        if(found == 1)
        {
            int x = t;
            int sigma = labels[t].sigma;
            sumflow += sigma;
            while(x != s)
            {
                int u = labels[x].pre;
                if(labels[x].dir > 0)   G.F[u][x] += sigma;
                x = u;
            }
        }
        else break;
    }while(1);
    return sumflow;
}


int main(){
    int n, m, u, v, w, i;
    scanf("%d%d", &n, &m);
    Graph G;
    G.n = n;
    for(i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        G.C[u][v] = w;
    }
    int flow = ford_fullkerson(G, 1, n);
    printf("Max flow: %d\n", flow);
    printf("X0:");
    for(i = 1; i <= n; i++)
        if(labels[i].dir != 0)
            printf(" %d", i);
    printf("\nY0:");
    for(i = 1; i <= n; i++)
        if(labels[i].dir == 0)
            printf(" %d", i);
    return 0;
}
