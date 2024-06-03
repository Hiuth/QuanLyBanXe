#pragma once
#include<string>
#include<iostream>
#include"KetNoi.h"
#include "CheckDuLieu.h"
#include <vector>
using namespace std;
class NodeXe
{
private:
	string MaXe;  // VFP, VF6,VF5, ...
	string TenXe;
	string GiaTien;
	string DongCo;
	string HopSo;
	string DanDong;
	string NamSanXuat;
	string TuiKhi;
	string HangXe; // hạng a b c d E 
	string TocDoToiDa;
	string KichThuoc;
	string KhoangSangGam;
	string PhanCapXe; // suv ,sedan, hatback, mpv,minicar
	string TonKho;
	string CongSuatToiDa;
	NodeXe* pointer;
public:
	NodeXe(string, string, string, string, string, string, string, string, string, string, string, string, string, string, string);
	virtual ~NodeXe();

	string LayTenXe() { return TenXe; }
	void DatTenXe(string val) { TenXe = val; }

	string LayMaXe() { return MaXe; }
	void DatMaXe(string val) { MaXe = val; }

	string LayGiaTien() { return GiaTien; }
	void DatGiaTien(string val) { GiaTien = val; }

	string LayLoaiDongCo() { return DongCo; }
	void CaiDatLoaiDongCo(string val) { DongCo = val; }

	string LayLoaiHopSo() { return HopSo; }
	void CaiDatLoaiHopSo(string val) { HopSo = val; }

	string LayLoaiDanDong() { return DanDong; }
	void CaiDatLoaiDanDong(string val) { DanDong = val; }

	string LayNamSanXuat() { return NamSanXuat; }
	void CaiDatNamSanXuat(string val) { NamSanXuat = val; }

	string LaySoTuiKhi() { return TuiKhi; }
	void CaiDatSoTuiKhi(string val) { TuiKhi = val; }

	string LayHangXe() { return HangXe; }
	void CaiDatHangXe(string val) { HangXe = val; }

	string LayTocDoToiDa() { return TocDoToiDa; }
	void CaiDatTocDoToiDa(string val) {TocDoToiDa =val; }

	string LayKichThuocXe() { return KichThuoc; }
	void CaiDatKichThuocXe(string val) { KichThuoc = val; }

	string LayKhoangSangGam() { return KhoangSangGam; }
	void CaiDatKhoangSangGam(string val) {KhoangSangGam = val; }

	string LayPhanCapXe() { return PhanCapXe; }
	void CaiDatPhanCapXe(string val) { PhanCapXe = val; }
	
	string LayCongSuatToiDaCuaDongCo() { return CongSuatToiDa; }
	void CaiDatCongSuatToiDaCuaDongCo(string val) { CongSuatToiDa = val; }

	string LaySoLuongTonKho() { return TonKho; }
	void CaiDatSoLuongTonKho(string val) { TonKho = val; }

	NodeXe* GetPointer() { return pointer; }
	void SetPointer(NodeXe* val) { pointer = val; }
};

