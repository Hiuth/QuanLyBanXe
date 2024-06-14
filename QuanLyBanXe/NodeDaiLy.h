#pragma once
#include"QuanLyXe.h"
class NodeDaiLy
{
private:
	string TenDaiLy;
	string DiaChi;
	string SDTDaiLy;
	string Quan;
	string ThanhPho;
	string MaDaiLy;
	string TrangThai;
	long long TongDoanhThu;
	NodeDaiLy* pointer;
public:
	NodeDaiLy(string, string, string,string,string,string);
	NodeDaiLy(string, string, string, string, string,string,string);
	NodeDaiLy(string, string, string, string, string,string,string,long long);
	virtual ~NodeDaiLy();

	string LayTenDaiLy() { return TenDaiLy; }
	void CaiDatTenDaiLy(string val) { TenDaiLy = val; }

	string LayDiaChi() { return DiaChi; }
	void CaiDatDiaChi(string val) { DiaChi = val; }

	string LaySDTDaiLy() { return SDTDaiLy; }
	void CaiDatSDT(string val) { SDTDaiLy = val; }

	string LayThanhPho() { return ThanhPho; }
	void CaiDatThanhPho(string val) { ThanhPho = val; }

	string LayQuan() { return Quan; }
	void CaiDatQuan(string val) { Quan = val; }

	string LayMaDaiLy() { return MaDaiLy; }
	void CaiDatMaDaiLY(string val) { MaDaiLy = val; }

	string LayTrangThaiHoatDong() { return TrangThai; }
	void CaiDatTrangThaiHoatDong(string val) { TrangThai = val; }

	long long LayTongDoanhthu() { return TongDoanhThu; }
	void CaiDatTongDoanhThu(long long val) { TongDoanhThu = val; }

	NodeDaiLy* GetPointer() { return pointer; }
	void SetPointer(NodeDaiLy* val) { pointer = val; }

};

