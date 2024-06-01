#pragma once
#include<string>
#include "CheckDuLieu.h"
using namespace std;
class NodeQuanLyXe
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
public:
	NodeQuanLyXe(string, string, string, string, string, string, string, string, string, string, string, string, string, string,string);
	virtual ~NodeQuanLyXe();
	string LayTenXe() { return TenXe; }
	void CaiTenXe(string val) { TenXe = val; }
};

