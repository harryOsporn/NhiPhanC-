#include <iostream>
using namespace std;
void main() {
	int tong = 0;
	int n;
	do
	{
		cout << "Nhap n: ";
		cin >> n;

	} while (n <= 3 or n >= 50);

	for (int i = 1; i <= n; i++)
	{
		tong = tong + i;
	}
	cout << "Tong = " << tong;
}