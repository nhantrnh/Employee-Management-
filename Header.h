#define _CRT_SECURE_NO_WARNINGS
#define MAX 10000
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct NgaySinh {
	int ngay;
	int thang;
	int nam;
};
class NhanVien {
protected:
	char* maNV;
	char* hoTen;
	char* gioiTinh;
	NgaySinh ngaySinh;
	char* diaChi;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual int tinhLuong();
	virtual int getNgayCong();
	virtual int getSoSanPham();
	virtual void setNgayCong(int);
	virtual void setSanPham(int);
	void setMaNV(char* str)
	{
		strcpy(maNV, str);
	}
	void setTen(char* str)
	{
		strcpy(hoTen, str);
	}
	void setGioiTinh(char* str)
	{
		strcpy(gioiTinh, str);
	}
	void setDiaChi(char* str)
	{
		strcpy(diaChi, str);
	}
	void setNgaySinh(NgaySinh date)
	{
		ngaySinh.nam = date.nam;
		ngaySinh.thang = date.thang;
		ngaySinh.ngay = date.ngay;
	}
	NhanVien();
	NhanVien(char*, char*, char*, NgaySinh, char*);
	NhanVien& operator=(const NhanVien&);
	NhanVien(const NhanVien&);
	~NhanVien();
	int getThangSinh();
	char* getMa();
	char* getTen();
	char* getGioiTinh();
	NgaySinh getNgaySinh();
	char* getDiaChi();
	int tinhTuoi();
	friend ostream& operator << (ostream& out, NhanVien nv);
	friend istream& operator >> (istream& in, NhanVien& nv);
};
//-----------KHAI BAO LOP CON NVSX-----------
class NVSanXuat :public NhanVien {
private:
	int SoSanPham;
public:
	void Nhap();
	void Xuat();
	int tinhLuong();
	NVSanXuat();
	NVSanXuat(char*, char*, char*, NgaySinh, char*, int);
	NVSanXuat(const NVSanXuat&);
	NVSanXuat& operator=(const NVSanXuat&);
	~NVSanXuat();
	int getThangSinh();
	char* getMa();
	char* getTen();
	char* getGioiTinh();
	char* getDiaChi();
	int getSoSanPham();
	NgaySinh getNgaySinh();
	void setSanPham(int);
	friend istream& operator >> (istream& in, NVSanXuat& nv);
	friend ostream& operator << (ostream& out, NVSanXuat nv);
};
class NVCongNhat :public NhanVien {
private:
	int SoNgayCong;
public:
	void Nhap();
	void Xuat();
	int tinhLuong();
	NVCongNhat();
	NVCongNhat(char*, char*, char*, NgaySinh, char*, int);
	NVCongNhat(const NVCongNhat&);
	NVCongNhat& operator=(const NVCongNhat&);
	~NVCongNhat();
	int getThangSinh();
	char* getMa();
	char* getTen();
	char* getDiaChi();
	char* getGioiTinh();
	NgaySinh getNgaySinh();
	int getNgayCong();
	void setNgayCong(int);
	friend istream& operator >> (istream& in, NVCongNhat& nv);
	friend ostream& operator << (ostream& out, NVCongNhat nv);
};
class CongTy {
private:
	int size;
	NhanVien** NV;
public:
	void GhiDSNV(ostream& fp);
	void DocDSNV();
	CongTy();
	CongTy(int, NhanVien**);
	CongTy(const CongTy&);
	~CongTy();
	void NhapDSNV();
	void XuatDSNV();
	int tongLuong();
	void timTenNhanVien(char* Ten);
	void timMaNhanVien(char* Ma);
	NhanVien* luongCaoNhat();
	int luongTrungBinh();
	int nhanVienThang5();
	void themNhanVien(ostream& fp);
	void xoaNhanVien(ostream& fp);
	void thapHonTrungBinh(ostream& fp);

};
