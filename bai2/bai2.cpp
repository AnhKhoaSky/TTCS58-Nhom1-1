#include<iostream>

using namespace std;

int n;
struct Node
{
	int gt;
	Node *next;
};

void KT(Node *&Dau)
{
	Dau = NULL;
}

void TN(Node *&Dau) 
{
	cout << "Nhap ma tran: ";
	cin >> n;
	int tam = n*n;
	Node *e, *f;
	int i;
	for (i = 0; i < tam; i++) 
	{
		e = new Node;
		e->gt = 0;
		e->next = NULL;
		if (Dau == NULL)
			Dau = e;
		else
			f -> next = e;
		f = e;
	}
}
void Duyet(Node *Dau) 
{
	Node *e;
	e = Dau;
	int i = 0;
	while (e != NULL)
	{
		i++;
		cout << "\t" << e->gt;
		if (i == n) 
		{
			i = 0;
			cout << endl;
		}
		e = e->next;
	}
}
void Nhap(Node *&Dau)
{
	int x;
	int Hang, Cot;
	do {
		cout << "Nhap mot so nguyen, nhap 0 de dung: ";
		cin >> x;
		if (x != 0)
		{
			Node *e, *f;
			f = Dau;
			e = new Node;
			cout << "Nhap hang va cot: ";
			cin >> Hang >> Cot;
			int ViTri = 0;
			ViTri = Hang * n + Cot;
			if (ViTri >= n*n) 
			{
				cout << "Vi tri nhap khong hop le" << endl;
				cout << "Moi nhap lai: " << endl;
			}
			else {
				int i = 0;
				while (i<ViTri)
				{
					i++;
					f = f->next;
				}
				e->next = f->next;
				f->gt = x;
			}
		}
	} while (x != 0);
}
void Nhan(Node *Dau, int j) 
{
	Node *e = Dau;
	while (e != NULL) 
	{
		e->gt = e->gt*j;
		e = e->next;
	}
}
int main() {
	Node *Dau;
	int j;
	KT(Dau);
	TN(Dau);
	Duyet(Dau);
	Nhap(Dau);
	Duyet(Dau);
	cout << "Nhap gia tri can nhan: ";
	cin >> j;
	Nhan(Dau, j);
	Duyet(Dau);
	cout << endl;
	system("pause");
}
