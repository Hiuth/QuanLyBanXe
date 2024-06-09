#pragma once
#include "QuanLyXe.h"
class NodeLHBaoDuong
{
private:
	string NgayHen;
	string ThoiGianHen;
	string LoaiDichVu;
	string BienSo;
	string MaXe;
	string SoDienThoai;
	string MaCuaHang;
	string UserEmail;
	NodeLHBaoDuong* pointer;
public:
	NodeLHBaoDuong(string, string, string, string, string, string, string, string);
	virtual ~NodeLHBaoDuong();

	string LayNgayHen() { return NgayHen; }
	void CaiDatNgayHen(string val) { NgayHen = val; }

	string LayThoiGianHen() { return ThoiGianHen; }
	void CaiDatThoiGianHen(string val) { ThoiGianHen = val; }

	string LayLoaiDichVu() { return LoaiDichVu; }
	void CaiDatLoaiDichVu(string val) { LoaiDichVu = val;}

	string LayBienSo() { return BienSo; }
	void CaiDatBienSo(string val) { BienSo = val; }

	string LayMaXe() { return MaXe; }
	void CaiDatMaXe(string val) { MaXe = val; }

	string LaySoDienThoai() { return SoDienThoai; }
	void CaiDatSoDienThoai(string val) { SoDienThoai = val; }

	string LayMaCuaHang() { return MaCuaHang; }
	void CaiDatMaCuaHang(string val) { MaCuaHang = val; }

	string LayTaiKhoanKhachHang() { return UserEmail; }
	void CaiDatTaiKhoanKhachHang(string val) { UserEmail = val; }

	NodeLHBaoDuong* GetPointer() { return pointer; }
	void SetPointer(NodeLHBaoDuong* val) { pointer = val; }
};

