#pragma once
#include"NodeXe.h"
class NodeCauHinhXe
{
private:
	string MaCauHinh;
	string LoaiPin;
	string MauSac;
	string GiaPin;
	string MaXe;
	NodeCauHinhXe* pointer;
public:
	NodeCauHinhXe(string,string,string,string,string);
	virtual ~NodeCauHinhXe();

	string LayMaCauhinhXe() { return MaCauHinh; }
	void CaiDatMaCauhinh(string val) { MaCauHinh = val; }

	string LayLoaiPin() { return LoaiPin; }
	void CaiDatLoaiPin(string val) { LoaiPin = val; }

	string LayMauSac() { return MauSac; }
	void CaiDatMauSac(string val) { MauSac = val; }

	string LayMaXe() { return MaXe; }
	void CaiDatMaXe(string val) { MaXe = val; }

	NodeCauHinhXe* GetPointer() { return pointer; }
	void SetPointer(NodeCauHinhXe* val) { pointer = val; }

	string LayGiaPin() { return GiaPin; }
	void CaiDatGiaPin(string val) { GiaPin = val; }
};

