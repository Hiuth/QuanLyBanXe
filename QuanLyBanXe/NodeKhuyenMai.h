#pragma once
#include"QuanLyXe.h"
class NodeKhuyenMai
{
private:
	string MaKM;
	string NoiDung;
	NodeKhuyenMai* pointer;
public:
	NodeKhuyenMai(string);
	NodeKhuyenMai(string, string);
	virtual ~NodeKhuyenMai();
	string LayMaKM() { return MaKM; }
	void CaiDatMaKM(string val) { MaKM = val; }

	string LayNoiDung() { return NoiDung; }
	void CaiDatNoiDung(string val) { NoiDung = val; }

	NodeKhuyenMai* GetPointer() { return pointer; }
	void CaiDatNoiDung(NodeKhuyenMai* val) { pointer = val; }
};

