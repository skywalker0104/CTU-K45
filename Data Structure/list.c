#include<stdio.h>

typedef struct{
	int Elements[100];
	int Last;
}List;

void makenullList(List *pL){
	pL->Last = 0;
}

int member(int x, List L){
	int i;
	for(i = 0; i < L.Last; i++)
		if(L.Elements[i] == x)
			return 1;
	return 0;
}

void insertSet(int x, List *pL){
	pL->Elements[pL->Last] = x;
	pL->Last++;
}

void readSet(List *pL){
	int i, x, n;
	scanf("%d", &n);
	makenullList(pL);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if(!member(x, *pL))
			insertSet(x, pL);		
	}
}

void printList(List L){
	int i;
	for(i = 0; i < L.Last; i++)
		printf("%d ", L.Elements[i]);
}

float getAvg(List L){
	float s = 0;
	int i;
	for(i = 0; i < L.Last; i++)
		s += L.Elements[i];
	if(s != 0)	return s/L.Last;
	else return -10000.0000;
}

int locate(int x, List L){
	int i;
	for(i = 0; i < L.Last; i++)
		if(x == L.Elements[i])
			return i+1;			
	return L.Last+1;
}

void del(List *pL, int x){
	int i;
	if(locate(x, *pL) != pL->Last+1)
	{
		for(i = locate(x, *pL)-1; i < pL->Last; i++)
			pL->Elements[i] = pL->Elements[i+1];
		pL->Last--;
	}
}

void intersection(List L1, List L2, List *pL){
	int i;
	makenullList(pL);
	for(i = 0; i < L1.Last; i++)
			if(member(L1.Elements[i], L2))
				insertSet(L1.Elements[i], pL);
}

void complement(List L1, List L2, List *pL){
	int i;
	makenullList(pL);
	for(i = 0; i < L1.Last; i++)
			if(!member(L1.Elements[i], L2))
				insertSet(L1.Elements[i], pL);
}

void unionSet(List L1, List L2, List *pL){
	int i;
	makenullList(pL);
	for(i = 0; i < L1.Last; i++)
		insertSet(L1.Elements[i], pL);
	for(i = 0; i < L2.Last; i++)
		if(!member(L2.Elements[i], *pL))
			insertSet(L2.Elements[i], pL);
}

int main(){
	List L, L1, L2;
	makenullList(&L);
	makenullList(&L1);
	makenullList(&L2);
	readSet(&L1);
	readSet(&L2);
	printList(L1);
	printf("\n");
	printList(L2);
	printf("\n");
	unionSet(L1, L2, &L);
	printList(L);
	return 0;
}
