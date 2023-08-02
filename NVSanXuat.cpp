#include "Header.h"
ostream& operator<<(ostream& out, NVSanXuat nv) {
	out << nv.maNV << "\n" << nv.hoTen << "\n" << nv.gioiTinh << "\n" << nv.ngaySinh.ngay << "/" << nv.ngaySinh.thang << "/" << nv.ngaySinh.nam << "\n" << nv.diaChi << "\n" << nv.SoSanPham;
	return out;
}
int NVSanXuat::getSoSanPham() {
	return SoSanPham;
}
istream& operator>>(istream& in, NVSanXuat& nv) {
	nv.maNV = new char[15];
	nv.hoTen = new char[100];
	nv.gioiTinh = new char[10];
	nv.diaChi = new char[200];
	in >> nv.maNV;
	in >> nv.hoTen;
	in >> nv.gioiTinh;
	string s = "";
	string temp = "";
	int i = 0;
	in >> s;
	while (i < s.size()) {
		if (s[i] == '/') {
			break;
		}
		temp.push_back(s[i]);
		i++;
	}
	nv.ngaySinh.ngay = stoi(temp);
	temp.clear();
	i++;

	while (i < s.size()) {
		if (s[i] == '/') {
			break;
		}
		temp.push_back(s[i]);
		i++;
	}
	nv.ngaySinh.thang = stoi(temp);
	temp.clear();
	i++;
	for (int j = i; j < s.size(); j++) {
		temp.push_back(s[j]);
	}
	nv.ngaySinh.nam = stoi(temp);

	in >> nv.diaChi;
	in >> nv.SoSanPham;
	return in;
}
NVSanXuat::NVSanXuat() : NhanVien() {
	SoSanPham = 0;
}
void NVSanXuat::setSanPham(int a) {
	SoSanPham = a;
}
NVSanXuat::NVSanXuat(char* a, char* b, char* c, NgaySinh d, char* e, int f) : NhanVien(a, b, c, d, e), SoSanPham(f) {
	maNV = new char[15];
	hoTen = new char[100];
	gioiTinh = new char[10];
	diaChi = new char[200];
	SoSanPham = f;
}
NVSanXuat::NVSanXuat(const NVSanXuat& s) : NhanVien(s) {
	maNV = new char[15];
	hoTen = new char[100];
	gioiTinh = new char[10];
	diaChi = new char[200];
	SoSanPham = s.SoSanPham;
}
NVSanXuat& NVSanXuat::operator=(const NVSanXuat& nv) {
	if (this == &nv) {
		return *this;
	}
	maNV = new char[15];
	hoTen = new char[100];
	gioiTinh = new char[10];
	diaChi = new char[200];
	strcpy(maNV, nv.maNV);
	strcpy(hoTen, nv.hoTen);
	strcpy(gioiTinh, nv.gioiTinh);
	strcpy(diaChi, nv.diaChi);
	ngaySinh.ngay = nv.ngaySinh.ngay;
	ngaySinh.thang = nv.ngaySinh.thang;
	ngaySinh.nam = nv.ngaySinh.nam;
	SoSanPham = nv.SoSanPham;
	return *this;
}
NVSanXuat::~NVSanXuat() {
	delete[] maNV;
	delete[] hoTen;
	delete[] diaChi;
	delete[] gioiTinh;
	maNV = hoTen = diaChi = nullptr;
}
void NVSanXuat::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so san pham (10 - 15 san pham): ";
	cin >> SoSanPham;
	while (SoSanPham < 10 || SoSanPham>15) {
		cout << "Nhap lai so san pham: ";
		cin >> SoSanPham;
	}
	cin.ignore();
}
void NVSanXuat::Xuat() {
	NhanVien::Xuat();
	cout << "\nSo san pham: " << SoSanPham;
}
int NVSanXuat::tinhLuong() {
	return SoSanPham * 50000;
}
int NVSanXuat::getThangSinh() {
	return NhanVien::getThangSinh();
}
char* NVSanXuat::getMa() {
	return NhanVien::getMa();
}
char* NVSanXuat::getTen() {
	return NhanVien::getTen();
}
char* NVSanXuat::getGioiTinh() {
	return NhanVien::getGioiTinh();
}
char* NVSanXuat::getDiaChi() {
	return NhanVien::getDiaChi();
}
NgaySinh NVSanXuat::getNgaySinh()
{
	return NhanVien::getNgaySinh();
}