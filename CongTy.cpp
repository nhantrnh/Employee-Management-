#include "Header.h"
CongTy::CongTy() {
	size = 0;
	NV = new NhanVien * [10000000];
	return;
}
CongTy::CongTy(int a, NhanVien** b) {
	size = a;
	NV = new NhanVien * [10000000];
	NV = b;
}
CongTy::CongTy(const CongTy& c) {
	size = c.size;
	NV = new NhanVien * [10000000];
	NV = c.NV;
}
CongTy::~CongTy() {
	for (int i = size - 1; i >= 0; --i) {
		delete NV[i];
		NV[i] = nullptr;
	}
}
void CongTy::NhapDSNV() {
	int sl;
	do {
		cout << "Nhap so luong Nhan vien: ";
		cin >> sl;
	} while (sl < 1);
	for (int i = 0; i < sl; ++i) {
		cout << "Chon loai Nhan vien (NV San Xuat: 1 - NV Cong Nhat: 2): ";
		int type;
		cin >> type;
		while (type != 1 && type != 2) {
			cout << "Nhap lai: ";
			cin >> type;
		}
		cin.ignore();
		if (type == 1) {
			NV[size] = new NVSanXuat;
		}
		if (type == 2) {
			NV[size] = new NVSanXuat;
		}
		NV[size++]->Nhap();
	}
}
void CongTy::XuatDSNV() {
	cout << "Cong ty gom " << size << " nhan vien, gom:\n";
	for (int i = 0; i < size; ++i) {
		if (NV[i]->getSoSanPham() > 0) {
			cout << "Nhan vien thu " << i + 1 << " (nhan vien san xuat)\n";
		}
		else {
			cout << "Nhan vien thu " << i + 1 << " (nhan vien cong nhat)\n";
		}
		NV[i]->Xuat();
		cout << "\nLuong: " << NV[i]->tinhLuong();
		cout << endl << endl;
	}
}

int CongTy::tongLuong() {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += NV[i]->tinhLuong();
	}
	return sum;
}

void CongTy::timTenNhanVien(char* hoTen) {
	cout << "Ket qua tim kiem nhan vien " << hoTen << " la:\n";
	bool exist = false;
	for (int i = 0; i < size; ++i) {
		if (strcmp(NV[i]->getTen(), hoTen) == 0) {
			NV[i]->Xuat();
			exist = true;
		}
	}
	if (!exist) {
		cout << "Khong co nhan vien nao thoa man.\n";
	}
}

void CongTy::timMaNhanVien(char* maNV) {
	cout << "Ket qua tim kiem nhan vien " << maNV << " la:\n";
	bool exist = false;
	for (int i = 0; i < size; ++i) {
		if (strcmp(NV[i]->getMa(), maNV) == 0) {
			NV[i]->Xuat();
			exist = true;
		}
	}
	if (!exist) {
		cout << "Khong co nhan vien nao thoa man.\n";
	}
}

NhanVien* CongTy::luongCaoNhat() {
	NhanVien* highest = NV[0];
	for (int i = 1; i < size; ++i) {
		if (NV[i]->tinhLuong() > highest->tinhLuong()) {
			highest = NV[i];
		}
	}
	return highest;
}
int CongTy::luongTrungBinh() {
	return tongLuong() / size;
}
int CongTy::nhanVienThang5() {
	int count = 0;
	for (int i = 1; i < size; ++i) {
		if (NV[i]->getThangSinh() == 5) {
			count++;
		}
	}
	return count;
}
void CongTy::themNhanVien(ostream& fp) {
	cout << "Chon loai Nhan vien (NV San Xuat: 1 - NV Cong Nhat: 2): ";
	int type;
	cin >> type;
	while (type != 1 && type != 2) {
		cout << "Nhap lai: ";
		cin >> type;
	}
	//cin.ignore();
	NhanVien* NV = new NhanVien;
	if (type == 1) {
		NV = new NVSanXuat;
	}
	if (type == 2) {
		NV = new NVCongNhat;
	}
	NV->Nhap();
	fp << "\n" << *NV;
	if (NV->getSoSanPham() >= 10 && NV->getSoSanPham() <= 15) {
		fp << NV->getSoSanPham();
	}
	else if (NV->getNgayCong() >= 22 && NV->getNgayCong() <= 26) {
		fp << NV->getNgayCong();
	}
}
void CongTy::xoaNhanVien(ostream& fp) {
	cin.ignore();
	char* s = new char[15];
	cout << "Nhap vao ma so nhan vien muon xoa: ";
	cin.getline(s, 15);
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (strcmp(s, NV[i]->getMa()) == 0) {
				NV[i] = NV[j];
				size--;
				break;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		if (i != 0) {
			fp << "\n";
		}
		fp << *NV[i];
		if (NV[i]->getSoSanPham() >= 10 && NV[i]->getSoSanPham() <= 15) {
			fp << NV[i]->getSoSanPham();
		}
		else if (NV[i]->getNgayCong() >= 22 && NV[i]->getNgayCong() <= 26) {
			fp << NV[i]->getNgayCong();
		}
	}
}
void CongTy::thapHonTrungBinh(ostream& fp) {
	int avg = luongTrungBinh();
	int dem = 0;
	fp << "Nhung nhan vien co luong thap hon luong trung binh " << avg << " cua cong ty la: \n";;
	for (int i = 0; i < size; ++i) {
		if (NV[i]->tinhLuong() < avg) {
			fp << *NV[i];
			dem++;
		}
	}
	if (dem == 0) {
		fp << "Khong co sinh vien thap hon luong trung binh.";
	}
}
void CongTy::GhiDSNV(ostream& fp) {

	do {
		cout << "Nhap so luong Nhan vien: ";
		cin >> size;
	} while (size < 1);
	for (int i = 0; i < size; ++i) {
		cout << "Chon loai Nhan vien (NV San Xuat: 1 - NV Cong Nhat: 2): ";
		int type;
		cin >> type;
		while (type != 1 && type != 2) {
			cout << "Nhap lai: ";
			cin >> type;
		}
		//cin.ignore();
		if (type == 1) {
			NV[i] = new NVSanXuat;
		}
		if (type == 2) {
			NV[i] = new NVCongNhat;
		}
		NV[i]->Nhap();
		if (i != 0)fp << '\n';
		fp << *NV[i];
		if (NV[i]->getSoSanPham() >= 10 && NV[i]->getSoSanPham() <= 15) {
			fp << NV[i]->getSoSanPham();
		}
		else if (NV[i]->getNgayCong() >= 22 && NV[i]->getNgayCong() <= 26) {
			fp << NV[i]->getNgayCong();
		}
	}
}
void CongTy::DocDSNV() {
	ifstream f;
	f.open("ds_NhanVien.dat", ios_base::in);
	size = 0;
	while (!f.eof()) {
		int so = 0;
		NhanVien* newNV = new NhanVien;
		f >> *newNV >> so;
		f.ignore();
		if (so >= 10 && so <= 15){
			NV[size] = new NVSanXuat;
			NV[size]->setMaNV(newNV->getMa());
			NV[size]->setTen(newNV->getTen());
			NV[size]->setNgaySinh(newNV->getNgaySinh());
			NV[size]->setGioiTinh(newNV->getGioiTinh());
			NV[size]->setDiaChi(newNV->getDiaChi());
			NV[size]->setSanPham(so);
		}
		else{
			NV[size] = new NVCongNhat;
			NV[size]->setMaNV(newNV->getMa());
			NV[size]->setTen(newNV->getTen());
			NV[size]->setNgaySinh(newNV->getNgaySinh());
			NV[size]->setGioiTinh(newNV->getGioiTinh());
			NV[size]->setDiaChi(newNV->getDiaChi());
			NV[size]->setNgayCong(so);
		}
		++size;
	}
	f.close();
}