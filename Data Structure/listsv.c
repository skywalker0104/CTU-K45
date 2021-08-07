#include<stdio.h>
#include<string.h>

struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};

typedef struct{
	struct SinhVien A[40];
	int n;
}DanhSach;

DanhSach dsRong(){
	DanhSach L;
	L.n = 0;
	return L;
}

void chenCuoi(struct SinhVien sv, DanhSach *pL){
	pL->A[pL->n] = sv;
	pL->n++;
}

void xoaTai(int p, DanhSach *pL){
	int i;
	if(p <= pL->n)
	{
		for(i = p-1; i <= pL->n; i++)
			pL->A[i] = pL->A[i+1];
		pL->n -= 1;
	}
}

int tim(char x[], DanhSach L){
	int i;
	for(i = 0; i < L.n; i++)
		if(strcmp(x, L.A[i].MSSV) == 0)
			return i+1;
	return L.n+1;
}

DanhSach chepDat(DanhSach L){
	DanhSach L1 = dsRong();
	int i;
	for(i = 0; i < L.n; i++)
		if((L.A[i].DiemLT+L.A[i].DiemTH1+L.A[i].DiemTH2) >= 4.0)
			chenCuoi(L.A[i], &L1);			
	return L1;
}

int ktRong(DanhSach L){
	if(L.n == 0)	return 1;
	return 0;
}

void xoaSinhVien(char x[10], DanhSach *pL){
	int p = tim(x, *pL);
	if(p <= pL->n)	xoaTai(p, pL);
}

int main(){
	DanhSach L = dsRong();
	int n, i;
	char ht[50];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%s", L.A[i].MSSV);
		getchar();
		fgets(ht, 50, stdin);
		if(ht[strlen(ht)-1] == '\n')
			ht[strlen(ht)-1] = '\0';
		strcpy(L.A[i].HoTen, ht);
		scanf("%f%f%f", &L.A[i].DiemLT, &L.A[i].DiemTH1, &L.A[i].DiemTH2);
		L.n++;
	}
	char s[10];
	scanf("%s", s);
	int p = tim(s, L);
	for(i = 0; i < L.n; i++)
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
	if(p < L.n+1)
	{
		printf("Tim thay sinh vien %s. Thong tin sinh vien:\n", s);
		printf("%s - %s - %.2f - %.2f - %.2f", L.A[p-1].MSSV, L.A[p-1].HoTen, L.A[p-1].DiemLT, L.A[p-1].DiemTH1, L.A[p-1].DiemTH2);
	}
	else printf("Khong tim thay sinh vien %s", s);
	return 0;
}
