#pragma once
#include"QuanLyXe.h"
class NodeDaiLy
{
private:
	string TenDaiLy;
	string DiaChi;
	string SDTDaiLy;
public:
	NodeDaiLy(string, string, string);
	virtual ~NodeDaiLy();

	string LayTenDaiLy() { return TenDaiLy; }
	void CaiDatTenDaiLy(string val) { TenDaiLy = val; }

	string LayDiaChi() { return DiaChi; }
	void CaiDatDiaChi(string val) { DiaChi = val; }

	string LaySDTDaiLy() { return SDTDaiLy; }
	void CaiDatSDT(string val) { SDTDaiLy = val; }
};

