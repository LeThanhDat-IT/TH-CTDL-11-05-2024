#include "Header.h"

void nhapDinh(AL& l)
{
	cout << "Nhap dinh: ";
	cin >> l.n;
}

void khoiTao(AL& l)
{
	for (int i = 0; i < l.n; i++)
		l.list[i] = nullptr;
}

node* taoNode(int dinhke,int trongSo)
{
	node* p = new node;
	if (!p)
		return nullptr;
	p->dinhke = dinhke;
	p->trongSo = trongSo;
	p->next = nullptr;
	return p;
}

void nhapCanh(AL& l)
{
	int dinhGoc, dinhke, trongSo;
	do {
		cout << "Dinh goc - Dinh ke - Trong so: ";
		cin >> dinhGoc >> dinhke >> trongSo;
		if (dinhGoc == 0 && dinhke == 0 && trongSo == 0)
			break;
		node* p = taoNode(dinhke,trongSo);
		p->trongSo = trongSo; 
		if (!l.list[dinhGoc])
		{
			l.list[dinhGoc] = p;
		}
		else {
			node* t = l.list[dinhGoc];
			while (t->next)
			{
				t = t->next;
			}
			t->next = p;
		}
	} while (true);
}


void xuat(AL l)
{
	for (int i = 0; i < l.n; i++)
	{
		cout << i;
		while (l.list[i])
		{
			cout << "->" << l.list[i]->dinhke<< "|" << l.list[i]->trongSo << "\t";
			l.list[i] = l.list[i]->next;
		}
		cout << endl;
	}
}
int demNode(node* l)
{
	int dem = 0;
	while (l)
	{
		dem++;
		l = l->next;
	}
	return dem;
}
void ghi(AL l, ofstream& f)
{
	f << l.n;
	for (int i = 0; i < l.n; i++)
	{
		f << endl;
		f << demNode(l.list[i]) << "\t";
		while (l.list[i])
		{
			f << l.list[i]->dinhke << " " << l.list[i]->trongSo << "\t";
			l.list[i] = l.list[i]->next;
			
		}
	}
	f.close();
}

void doc(AL& l, ifstream &f)
{
	int dem, dinhke, trongSo;
	f >> l.n;
	khoiTao(l);
	for (int i = 0; i < l.n; i++)
	{
		f >> dem;
		while (dem)
		{
			f >> dinhke >> trongSo;
			node* p = taoNode(dinhke, trongSo);
			if (!l.list[i])
				l.list[i] = p;
			else {
				node* t = l.list[i];
				while (t->next)
					t = t->next;
				t->next = p;
			}
			dem--;
		}
	}
	f.close();
}