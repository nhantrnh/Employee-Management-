#include "Header.h"
ostream& operator<<(ostream& out, NVCongNhat nv) {
	out << nv.maNV << "\n" << nv.hoTen << "\n" << nv.gioiTinh << "\n" << nv.ngaySinh.ngay << "/" << nv.ngaySinh.thang << "/" << nv.ngaySinh.nam << "\n" << nv.diaChi << "\n" << nv.SoNgayCong;
	return out;
}
int NVCongNhat::getNgayCong() {
	return SoNgayCong;
}
istream& operator>>(istream& in, NVCongNhat& nv) {
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
	in >> nv.SoNgayCong;
	return in;
}
NVCongNhat::NVCongNhat() : NhanVien() {
	SoNgayCong = 0;
}
void NVCongNhat::setNgayCong(int a) {
	SoNgayCong = a;
}
NVCongNhat::NVCongNhat(char* a, char* b, char* c, NgaySinh d, char* e, int f) : NhanVien(a, b, c, d, e), SoNgayCong(f) {
	maNV = new char[15];
	hoTen = new char[100];
	gioiTinh = new char[10];
	diaChi = new char[200];
	SoNgayCong = f;
}
NVCongNhat::NVCongNhat(const NVCongNhat& s) : NhanVien(s) {
	maNV = new char[15];
	hoTen = new char[100];
	gioiTinh = new char[10];
	diaChi = new char[200];
	SoNgayCong = s.SoNgayCong;
}
NVCongNhat& NVCongNhat::operator=(const NVCongNhat& nv) {
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
	SoNgayCong = nv.SoNgayCong;
	return *this;
}
NVCongNhat::~NVCongNhat() {
	delete[] maNV;
	delete[] hoTen;
	delete[] diaChi;
	delete[] gioiTinh;
	maNV = hoTen = diaChi = nullptr;
}
void NVCongNhat::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so ngay cong: (22- 26 ngày)";
	cin >> SoNgayCong;
	while (SoNgayCong < 22 || SoNgayCong>26) {
		cout << "Nhap lai so ngay cong: ";
		cin >> SoNgayCong;
	}
	cin.ignore();
}
void NVCongNhat::Xuat() {
	NhanVien::Xuat();
	cout << "\nSo ngay cong: " << SoNgayCong;
}
int NVCongNhat::tinhLuong() {
	return SoNgayCong * 500000;
}
int NVCongNhat::getThangSinh() {
	return NhanVien::getThangSinh();
}
char* NVCongNhat::getMa() {
	return NhanVien::getMa();
}
char* NVCongNhat::getTen() {
	return NhanVien::getTen();
}
char* NVCongNhat::getGioiTinh() {
	return NhanVien::getGioiTinh();
}
char* NVCongNhat::getDiaChi() {
	return NhanVien::getDiaChi();
}
NgaySinh NVCongNhat::getNgaySinh() {
	return NhanVien::getNgaySinh();
}