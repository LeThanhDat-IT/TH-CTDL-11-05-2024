#include"Header.h"

int main()
{
    AL n;
  /* nhapDinh(n);
    khoiTao(n);


   cout << "Nhap cac canh cua do thi (nhap 0 0 0 de ket thuc):\n";
    nhapCanh(n);

    cout << "Danh sach ke:\n";
    xuat(n);
    ofstream f("dothi.txt");
    ghi(n, f);*/

    ifstream f("dothi.txt");
    doc(n, f);
    xuat(n);

}