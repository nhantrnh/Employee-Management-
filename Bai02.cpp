#include "Header.h"

int main() {
	CongTy ct;
	NhanVien* nv;
	char Continue = 'y', Continue1 = 'y';
	while (Continue == 'y' || Continue == 'Y') {
		cout << "1. Nhap, xuat thong tin va luong 1 Nhan vien\n";
		cout << "2. Ghi danh sach nhan vien.\n";
		cout << "3. Doc danh sach nhan vien.\n";
		cout << "4. Xuat danh dach sinh vien.\n";
		cout << "5. Tinh tong luong cua tat ca nhan vien.\n";
		cout << "6. Tim nhan vien co luong cao nhat.\n";
		cout << "7. Tinh luong trung binh cua cong ty.\n";
		cout << "8. Nhap vao ma, tim nhan vien tuong ung.\n";
		cout << "9. Nhap vao ten, tim nhan vien tuong ung.\n";;
		cout << "10. Co bao nhieu nhan vien sinh thang 5.\n";
		cout << "11. Them mot nhan vien vao danh sach.\n";
		cout << "12. Xoa mot nhan vien khoi danh sach.\n";
		cout << "13. Ghi cac nhan vien co luong thap hon luong trung binh len tap tin.\n";
		cout << "14. Thoat khoi chuong trinh.\n";
		int Choice = 0;
		cout << "Xin moi chon 1 tinh nang: ";
		cin >> Choice;
		while (Choice < 1 && Choice > 14) {
			cout << "Xin moi nhap lai: ";
			cin >> Choice;
		}
		ofstream f;
		cout << "\nBan da chon: \n\t";
		switch (Choice) {
		case 1: {
			cout << "1. Nhap, xuat thong tin va luong 1 Nhan vien\n";
			cout << "Chon loai Nhan vien (NV San Xuat: 1 - NV Cong Nhat: 2): ";
			int type;
			cin >> type;
			while (type != 1 && type != 2) {
				cout << "Nhap lai: ";
				cin >> type;
			}
			NhanVien* NV = new NhanVien;
			if (type == 1) {
				NV = new NVSanXuat;
			}
			if (type == 2) {
				NV = new NVCongNhat;
			}
			NV->Nhap();
			cout << endl;
			NV->Xuat();
			cout << "\nLuong nhan vien la: " << NV->tinhLuong();
		}
			  break;
		case 2: {
			cout << "2. Ghi danh sach nhan vien.\n";
			f.open("ds_NhanVien.dat", ios_base::out);
			ct.GhiDSNV(f);
			f.close();
			break;
		}
		case 3: {
			cout << "3. Doc danh sach nhan vien.\n";
			ct.DocDSNV();
			cout << "Da doc xong danh sach nhan vien.";
			break;
		}
		case 4: {
			cout << "4. Xuat danh dach sinh vien.\n";
			ct.XuatDSNV();
			break;
		}
		case 5: {
			cout << "5. Tinh tong luong cua tat ca nhan vien.\n";
			cout << "Tong luong cua cong ty la: " << ct.tongLuong();
			break;
		}
		case 6: {
			cout << "6. Tim nhan vien co luong cao nhat.\n";

			NhanVien* nv = ct.luongCaoNhat();
			cout << "Nhan vien co luong cao nhat la:\n";
			nv->Xuat();
			cout << "\nLuong cao nhat la: " << nv->tinhLuong();
		}
			  break;
		case 7: {
			cout << "7. Tinh luong trung binh cua cong ty.\n";
			cout << "Luong trung binh cua cong ty la: " << ct.luongTrungBinh();
			break;
		}
		case 8: {
			cout << "8. Nhap vao ma, tim nhan vien tuong ung.\n";
			cin.ignore();
			char* ma = new char[15];
			cout << "Nhap vao ma nhan vien: ";
			cin.getline(ma, 15);
			ct.timMaNhanVien(ma);
		}
			  break;
		case 9: {
			cout << "9. Nhap vao ten, tim nhan vien tuong ung.\n";
			cin.ignore();
			char* ten = new char[100];
			cout << "Nhap vao ten nhan vien: ";
			cin.getline(ten, 100);
			ct.timTenNhanVien(ten);
		}
			  break;
		case 10: {
			cout << "10. Co bao nhieu nhan vien sinh thang 5.\n";
			cout << "Co " << ct.nhanVienThang5() << " nhan vien sinh thang nam";
			break;
		}
		case 11: {
			cout << "11. Them mot nhan vien vao danh sach.\n";
			f.open("ds_NhanVien.dat", ios_base::app);
			ct.themNhanVien(f);
			f.close();
			cout << "\nDa them nhan vien.\nDanh sach sau khi them.\n";
			ct.DocDSNV();
			ct.XuatDSNV();
			break;
		}
		case 12: {
			cout << "12. Xoa mot nhan vien khoi danh sach.\n";
			f.open("ds_NhanVien.dat", ios_base::out);
			ct.xoaNhanVien(f);
			f.close();
			cout << "\nDa xoa nhan vien.\nDanh sach sau khi xoa\n";
			ct.DocDSNV();
			ct.XuatDSNV();
			break;
		}
		case 13: {
			cout << "13. Ghi cac nhan vien co luong thap hon luong trung binh len tap tin.\n";
			f.open("emp_LowerAvgSalary.dat", ios_base::out);
			ct.thapHonTrungBinh(f);
			f.close();
			cout << "Danh sach duoc ghi vao tap tin emp_LowerAvgSalary.dat.";
			break;
		}
		case 14: {
			cout << "Thoat khoi chuong trinh. Bam phim bat ky de thoat.\n";
			return 0;
			break;
		}
		}
		cout << "\nBan co muon tiep tuc khong (Y: Co, N: Khong): ";
		cin >> Continue;
		while (Continue != 'y' && Continue != 'n' && Continue != 'N' && Continue != 'Y') {
			cout << "Thao tac khong dung, xin hay nhap lai: ";
			cin >> Continue;
		}
		if (Continue == 'n' || Continue == 'N') {
			cout << "Ket thuc chuong trinh!";
		}
		system("cls");
	}
	cout << endl;
	return 0;
}
