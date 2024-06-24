#pragma once
#include<iostream>
#include"QuanLyXe.h"
class NodeHoTro
{
private:
	string UserEmail;
	string sdt;
	string mota;
	string trangthai;
	string loaihotro;
	NodeHoTro* pointer;
public:
	NodeHoTro(string, string, string, string,string);
	virtual ~NodeHoTro();

	string LayTaiKhoanKhachHang() { return UserEmail; }
	void CaiDatTaiKhoanKhachHang(string val) { UserEmail = val; }

	string  LaySoDienThoai() { return sdt; }
	void CaiDatSoDienThoai(string val) { sdt = val; }

	string LayMoTa() { return mota; }
	void CaiDatMoTa(string val) { mota = val; }

	string LayTrangThai() { return trangthai; }
	void CaiDatTrangThai(string val) { trangthai = val; }

	string LayLoaiHoTro() { return loaihotro; }
	void CaiDatLoaiHoTro(string val) { loaihotro = val; }

	NodeHoTro* GetPointer() { return pointer; }
	void SetPointer(NodeHoTro* val) { pointer = val; }
};

