#pragma once
#include<iostream>
#include<fstream>
using namespace std;

struct node {
	int dinhke;
	int trongSo;
	node* next;
};
struct AL {
	int n;
	node* list[100];
};
void nhapDinh(AL& l);
void khoiTao(AL& l);
node* taoNode(int dinhke,int trongSo);
void nhapCanh(AL& l);
void xuat(AL l);
void ghi(AL l, ofstream& f);
int demNode(node* l);
void doc(AL& l, ifstream &f);