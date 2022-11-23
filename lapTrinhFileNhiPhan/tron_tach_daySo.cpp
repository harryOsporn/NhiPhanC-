#include <iostream>
using namespace std;
struct daySo {
	int n;
	int ds[100];
};

void nhapDaySo(daySo& x) {
	do
	{
		cout << "Nhap so luong daySo: ";
		cin >> x.n;
	} while (x.n < 0);
	for (int i = 0; i < x.n; i++)
	{
		cout << "a[" << i << "]";
		cin >> x.ds[i];
	}
}
void xuatDaySo(daySo x) {
	for (int i = 0; i < x.n; i++)
	{
		cout << x.ds[i] << "\t";
	}
}
//Tron daySo theo tu tang dan
void tronDaySo(daySo a, daySo b, daySo& x) {
	/*int i = 0, j = 0;
	x.n = 0;
	while (i < a.n and j < b.n) {
		if (a.ds[i] <= b.ds[j])
		{
			x.ds[x.n] = a.ds[i];
			i++;
		}
		else
		{
			x.ds[x.n] = b.ds[j];
			j++;
		}
		x.n++;
	}
	while (i < a.n)
		x.ds[x.n++] = a.ds[i++];
	while (j < b.n)
		x.ds[x.n++] = b.ds[j++];*/
	x.n = 0;
	int i = 0, j = 0;
	while (i < a.n and j < b.n)
	{
		if (a.ds[i] <= b.ds[j])
		{
			x.ds[x.n] = a.ds[i];
			i++;
		}
		else
		{
			x.ds[x.n] = b.ds[j];
			j++;
		}
		x.n++;
	}
	while (i < a.n) {
		x.ds[x.n] = a.ds[i];
		x.n++;
		i++;
	}
	while (j < b.n)
	{
		x.ds[x.n] = b.ds[j];
		x.n++;
		j++;
	}
}
//tach day so a: chan, b: le
void tachDaySo(daySo c, daySo& a, daySo& b) {
	//int i = 0, j = 0, k;
	//for ( k = 0; k < c.n; ++k)
	//{
	//	if (c.ds[k] % 2 == 0)
	//	{
	//		a.ds[i] = c.ds[k];
	//		i++;
	//	}
	//	else
	//	{
	//		b.ds[j] = c.ds[k];
	//		j++;
	//	}
	//}
	a.n = 0, b.n = 0;
	for (int i = 0; i < c.n; i++)
	{
		if (c.ds[i] % 2 == 0) {
			a.ds[a.n] = c.ds[i];
			a.n++;
		}
		else
		{
			b.ds[b.n] = c.ds[i];
			b.n++;
		}
	}
}

void main() {
	daySo a;
	daySo b;
	nhapDaySo(a);
	xuatDaySo(a);
	cout << endl;
	nhapDaySo(b);
	xuatDaySo(b);

	daySo c;
	tronDaySo(a, b, c);
	cout << "\nDay so sau khi ket hop tang dan: ";
	xuatDaySo(c);

	tachDaySo(c, a, b);
	cout << "\nDay so sau khi tach: \n";
	cout << "Day so chan:\t";
	xuatDaySo(a);
	cout << "\nDay so le:\t";
	xuatDaySo(b);
}