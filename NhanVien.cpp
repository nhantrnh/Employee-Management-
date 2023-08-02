#include "Header.h"
bool checkNgaySinh(int a, int b, int c) {
	if (b > 12 || b < 1) {
		return false;
	}
	if (a < 1) {
		return false;
	}
	if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && a > 31) {
		return false;
	}
	if ((b == 4 || b == 6 || b == 9|| b == 11) && a > 30) {
		return false;
	}
	if (b == 2) {
		if (c % 4 == 0 && c % 100 != 0) {
			if (a > 29) {
				return false;
			}
		}
		else if (a > 28) {
			return false;
		}
	}
	return true;
}
int NhanVien::getThangSinh() {
	return ngaySinh.thang;
}
char* NhanVien::getMa() {
	return maNV;
}
char* NhanVien::getTen() {
	return hoTen;
}
char* NhanVien::getGioiTinh() {
	return gioiTinh;
}
char* NhanVien::getDiaChi() {
	return diaChi;
}
NgaySinh NhanVien::getNgaySinh() {
	return ngaySinh;
}
NhanVien::NhanVien() {
	maNV = new char[15];
	hoTen = new char[100];
	gioiTinh = new char[10];
	diaChi = new char[200];
	ngaySinh.ngay = 0;
	ngaySinh.thang = 0;
	ngaySinh.nam = 0;
}
int NhanVien::getSoSanPham() {
	return 0;
}
int NhanVien::getNgayCong() {
	return 0;
}
NhanVien::NhanVien(char* a, char* b, char* e, NgaySinh d, char* c) {
	maNV = new char[15];
	hoTen = new char[100];
	gioiTinh = new char[10];
	diaChi = new char[200];
	strcpy(maNV, a);
	strcpy(hoTen, b);
	strcpy(gioiTinh, e);
	strcpy(diaChi, c);
	ngaySinh.ngay = d.ngay;
	ngaySinh.thang = d.thang;
	ngaySinh.nam = d.nam;
}
NhanVien::NhanVien(const NhanVien& nv) {
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
}
NhanVien& NhanVien::operator=(const NhanVien& nv) {
	if (this == &nv) {
		return *this;
	}
	strcpy(maNV, nv.maNV);
	strcpy(hoTen, nv.hoTen);
	strcpy(gioiTinh, nv.gioiTinh);
	strcpy(diaChi, nv.diaChi);
	ngaySinh.ngay = nv.ngaySinh.ngay;
	ngaySinh.thang = nv.ngaySinh.thang;
	ngaySinh.nam = nv.ngaySinh.nam;
	return *this;
}
NhanVien::~NhanVien() {
	delete[] maNV;
	delete[] hoTen;
	delete[] diaChi;
	delete[] gioiTinh;
	maNV = hoTen = diaChi = nullptr;
}
int NhanVien::tinhTuoi() {
	if (ngaySinh.thang < 5) {
		return 2023 - ngaySinh.nam;
	}
	if (ngaySinh.thang > 5) {
		return 2022 - ngaySinh.nam;
	}
	if (ngaySinh.thang == 5) {
		if (ngaySinh.ngay < 5) {
			return 2022 - ngaySinh.nam;
		}
		else return 2023 - ngaySinh.nam;
	}
	return -1;
}
void NhanVien::Nhap() {
	cin.ignore();
	cout << "Ma nhan vien: ";
	cin.getline(maNV, 15);
	while (strlen(maNV) != 5) {
		strcpy(maNV, "");
		cout << "Vui long nhap lai ma nhan vien: ";
		cin.getline(maNV, 15);
	}
	cout << "Nhap ho ten: ";
	cin.getline(hoTen, 100);
	cout << "Gioi tinh: ";
	cin.getline(gioiTinh, 10);
	;	while (!(strcmp(gioiTinh, "nam") == 0 || strcmp(gioiTinh, "Nu") == 0 || strcmp(gioiTinh, "nu") == 0 || strcmp(gioiTinh, "Nam") == 0)) {
		strcpy(gioiTinh, "");
		cout << "Vui long nhap lai: ";
		cin.getline(gioiTinh, 10);
	}

	cout << "Nhap ngay sinh (Nam 18 - 60. Nu 18 - 55) \n";
	cout << "\tNhap ngay: ";
	cin >> ngaySinh.ngay;
	cout << "\tNhap thang: ";
	cin >> ngaySinh.thang;
	cout << "\tNhap nam: ";
	cin >> ngaySinh.nam;
	while (!checkNgaySinh(ngaySinh.ngay, ngaySinh.thang, ngaySinh.nam)) {
		cout << "Nhap lai ngay sinh.\n";
		cout << "\tNhap ngay: ";
		cin >> ngaySinh.ngay;
		cout << "\tNhap thang: ";
		cin >> ngaySinh.thang;
		cout << "\tNhap nam: ";
		cin >> ngaySinh.nam;
	}
	if (strcmp(gioiTinh, "nam") == 0 || strcmp(gioiTinh, "Nam") == 0) {
		while (tinhTuoi() < 18 || tinhTuoi() > 60) {
			cout << "Nhap lai ngay sinh.\n";
			cout << "\tNhap ngay: ";
			cin >> ngaySinh.ngay;
			cout << "\tNhap thang: ";
			cin >> ngaySinh.thang;
			cout << "\tNhap nam: ";
			cin >> ngaySinh.nam;
		}
	}
	else if (strcmp(gioiTinh, "Nu") == 0 || strcmp(gioiTinh, "nu") == 0) {
		while (tinhTuoi() < 18 || tinhTuoi() > 55) {
			cout << "Nhap lai ngay sinh.\n";
			cout << "\tNhap ngay: ";
			cin >> ngaySinh.ngay;
			cout << "\tNhap thang: ";
			cin >> ngaySinh.thang;
			cout << "\tNhap nam: ";
			cin >> ngaySinh.nam;
		}
	}

	cin.ignore();
	cout << "Nhap dia chi: ";
	cin.getline(diaChi, 200);
}
void NhanVien::Xuat() {
	cout << "Ma nhan vien: " << maNV << "\nHo ten: " << hoTen << "\nGioi tinh: " << gioiTinh << "\nNgay sinh: " << ngaySinh.ngay << "/" << ngaySinh.thang << "/" << ngaySinh.nam << "\nDia chi: " << diaChi;
}
int NhanVien::tinhLuong() {
	return 0;
}
void NhanVien::setNgayCong(int a) {

}
void NhanVien::setSanPham(int a) {

}
istream& operator >> (istream& in, NhanVien& nv) {
	nv.maNV = new char[15];
	nv.hoTen = new char[100];
	nv.gioiTinh = new char[10];
	nv.diaChi = new char[200];
	in.getline(nv.maNV, 15);
	in.getline(nv.hoTen, 100);
	in.getline(nv.gioiTinh, 10);
	string s = "";
	string temp = "";
	int i = 0;
	getline(in, s);
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
	in.getline(nv.diaChi, 200);
	return in;
}
ostream& operator<<(ostream& out, NhanVien nv) {
	out << nv.maNV << "\n" << nv.hoTen << "\n" << nv.gioiTinh << "\n" << nv.ngaySinh.ngay << "/" << nv.ngaySinh.thang << "/" << nv.ngaySinh.nam << "\n" << nv.diaChi << "\n";
	return out;
}