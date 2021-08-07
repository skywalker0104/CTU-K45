#include<stdio.h>
#include<malloc.h>

struct Node{
	int Element;
	struct Node* Next;
};

typedef struct Node* List;

void makenullList(List *pL){
	(*pL) = (struct Node*)malloc(sizeof(struct Node));
	(*pL)->Next = NULL;
}

void addFirst(int x, List *pL){
	struct Node* p = *pL;
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	t->Element = x;
	t->Next = p->Next;
	p->Next = t;
}

void append(int x, List *pL){
	struct Node* p = *pL;
	while(p->Next != NULL)	p = p->Next;
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	t->Element = x;
	p->Next = t;
	t->Next = NULL;
}

void sort(List *pL){
	struct Node* p = *pL;
	while(p->Next != NULL)
	{
		struct Node* q = p->Next;
		while(q->Next != NULL)
		{
			if(p->Next->Element > q->Next->Element)
			{
				int t = p->Next->Element;
				p->Next->Element = q->Next->Element;
				q->Next->Element = t;
			}
			q = q->Next;
		}
		p = p->Next;
	}
}

float getAvg(List L){
	float s = 0, n = 0;
	struct Node* p = L;
	while(p->Next != NULL)
	{
		s += p->Next->Element;
		n++;
		p = p->Next;
	}
	float avg = -10000.0f;
	if(n != 0)	avg = s/n;
	return avg;
}

int member(int x, List L){
	struct Node* p = L;
	while(p->Next != NULL)
	{
		if(x == p->Next->Element)
			return 1;
		p = p->Next;
	}
	return 0;
}

struct Node* locate(int x, List L){
	struct Node* p = L;
	while(p->Next != NULL)
	{
		if(x == p->Next->Element)
			return p;
		p = p->Next;
	}
	return NULL;
}

void deleteList(struct Node* p, List *pL){
	p->Next = p->Next->Next;
}

List readSet(){
	int n;
	scanf("%d", &n);
	int i, x;
	List L;
	makenullList(&L);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if(!member(x, L))	addFirst(x, &L);
	}
	return L;
}

void removeAll(int x, List *pL){
	struct Node* p = locate(x, *pL);
	while(p->Next != NULL)
	{
		if(p != NULL)	deleteList(p, pL);
		p = locate(x, *pL);
	}
}

List difference(List L1, List L2){
	List L;
	makenullList(&L);
	struct Node* p = L1;
	while(p->Next != NULL)
	{
		if(!member(p->Next->Element, L2))
			append(p->Next->Element, &L);
		p = p->Next;
	}
	return L;
}

int main(){
List L;
struct Node* p;
L = readSet();
p=L;
while(p->Next!=NULL)
{
		printf("%d ",p->Next->Element);
		p=p->Next;
}
	return 0;
}
