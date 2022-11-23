#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int MAX = 50;
struct sinhVien {
	char maSV[30];
	char tenSV[10];
	float diem;
	float diem2;
	float diem3;
};
struct danhSach {
	sinhVien data[30];
	int n;
};
void nhapSinhVien(sinhVien& sv) {
	cout << "Nhap maSV: ";
	cin.ignore();
	cin.getline(sv.maSV, 50);
	cout << "Nhap tenSV: ";
	cin.getline(sv.tenSV, 6);
	cout << "Nhap diem 1: ";
	cin >> sv.diem;
	cout << "Nhap diem 2: ";
	cin >> sv.diem2;
	cout << "Nhap diem 3: ";
	cin >> sv.diem3;
	cout << endl;
}
void xuatSinhVien(sinhVien sv) {
	cout << sv.maSV << "\t" << sv.tenSV << "\t" << sv.diem << "\t" << sv.diem2 << "\t" << sv.diem3 << endl;
}
void nhapDanhSachSV(danhSach& ds) {
	do
	{
		cout << "Nhap so luong sinhVien: ";
		cin >> ds.n;
	} while (ds.n < 0);
	for (int i = 0; i < ds.n; i++)
	{
		nhapSinhVien(ds.data[i]);
	}
}
void xuatDanhSachSV(danhSach ds) {
	cout << "MaSV\t" << "TenSV\t" << "Diem1\t" << "Diem2\t" << "Diem3\t" << endl;
	for (int i = 0; i < ds.n; i++)
	{
		xuatSinhVien(ds.data[i]);
	}
}
void themSinhVien(danhSach& ds) {
	nhapSinhVien(ds.data[ds.n]); //hoac nhapSinhVien(ds.data[ds.n++]);
	ds.n++;
}
bool ghiFile(const char* nameFile, danhSach ds) {
	FILE* f = fopen(nameFile, "wb");
	if (f == NULL)
		return false;
	int ok = fwrite(&ds, sizeof(sinhVien), 1, f);
	fclose(f);
	if (ok != 1)
		return false;
	return true;
}
bool docFile(const char* nameFile, danhSach ds) {
	FILE* f = fopen(nameFile, "rb");
	if (f == NULL)
		return false;
	int ok = fread(&ds, sizeof(danhSach), 1, f);
	cout << "\nTenSV: " << ds.data->tenSV << "\tMaSV: " << ds.data->maSV << endl;
	fclose(f);
	if (ok != 1)
		return false;
	return true;
}
//sap xep sinh vien giam dan
void sortDecrease(danhSach& ds) {
	sinhVien sv;
	for (int i = 0; i < ds.n; i++)
	{
		for (int j = i + 1; j < ds.n; j++)
		{
			float tong_I = ds.data[i].diem + ds.data[i].diem2 + ds.data[i].diem3;
			float tong_j = ds.data[j].diem + ds.data[j].diem2 + ds.data[j].diem3;
			if (tong_I < tong_j)
			{
				sinhVien temp = ds.data[i];
				ds.data[i] = ds.data[j];
				ds.data[j] = temp;
			}
		}
	}
}
//Tra ve thi sinh co diem  >= 5
void thiSinhDiem5(danhSach ds, danhSach& diem5) {
	diem5.n = 0;
	for (int i = 0; i < ds.n; i++)
	{
		float tongDiem = ds.data[i].diem + ds.data[i].diem2 + ds.data[i].diem3;
		if (tongDiem >= 15 or (ds.data[i].diem >= 5 or ds.data[i].diem2 >= 5 or ds.data[i].diem3 >= 5))
		{
			diem5.data[diem5.n++] = ds.data[i];
		}
	}
}
//Kiem tra so nho nho cua day so co hon so nguyen a hay kh?
bool kiemTraDaySo(danhSach ds, int a) {
	for (int i = 0; i < ds.n; i++)
	{
		if ((ds.data[i].diem or ds.data[i].diem2 or ds.data[i].diem3) < a)
		{
			return true;
		}
	}
	return false;
}
int menu() {
	cout << "0. Ket thuc";
	cout << "\n1. Nhap danh sach thi sinh";
	cout << "\n2. Xuat Danh Sach thi sinh";
	cout << "\n3. Them thi sinh";
	cout << "\n4. Ghi vao file nhi phan.";
	cout << "\n5. Doc file nhi phan.";
	cout << "\n6. Sap xep sinh vien giam dan";
	cout << "\n7. Tra ve danh sach thi sinh co diem > 5.";
	cout << "\n8. Tim so nguyen a qua day so.";

	cout << endl;
	int chon;
	cin >> chon;
	return chon;
}
void main() {
	danhSach ds; sinhVien sv;
	danhSach diem5;
	int a;
	diem5.n = 0;
	ds.n = 0;
	do
	{
		switch (menu())
		{
		case 0:
			return;
		case 1:
			nhapDanhSachSV(ds);
			break;
		case 2:
			xuatDanhSachSV(ds);
			break;
		case 3:
			themSinhVien(ds);
			break;
		case 4:
			ghiFile("DanhSachThiSinh.bin", ds);
			break;
		case 5:
			docFile("DanhSachThiSinh.bin", ds);
			break;
		case 6:
			cout << "\nDanh sach thi sinh sau khi sap xep diem giam dan\n";
			sortDecrease(ds);
			xuatDanhSachSV(ds);
			break;
		case 7:
			cout << "\nDanh sach thi sinh dau\n";
			thiSinhDiem5(ds, diem5);
			xuatDanhSachSV(diem5);
			break;
		case 8: 
			cout << "\nNhap gia tri can tim: ";
			cin >> a;
			if (kiemTraDaySo(ds, a) == true)
				cout << "\nTrong day so co gia tri nho hon " << a << endl;
			else
				cout << "\nKhong co gia tri nao trong day so nho hon "<< a << endl;
			break;
		}
		cout << "\n=========MENU=========\n";
	} while (1);

	
}
