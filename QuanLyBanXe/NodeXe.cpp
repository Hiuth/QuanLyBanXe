#include "NodeXe.h"

NodeXe::NodeXe(string MaXe, string TenXe, string GiaTien, string DongCo, string HopSo, string DanDong, string NamSanXuat, string TuiKhi, string HangXe, string TocDoToiDa, string KichThuoc, string KhoangSangGam,string ChieuDaiCoSo, string TonKho, string PhanCapXe, string CongSuatToiDa)
{
	this->MaXe = MaXe;
	this->TenXe = TenXe;
	this->GiaTien = GiaTien;
	this->DongCo = DongCo;
	this->HopSo = HopSo;
	this->DanDong = DanDong;
	this->NamSanXuat = NamSanXuat;
	this->TuiKhi = TuiKhi;
	this->HangXe = HangXe;
	this->TocDoToiDa = TocDoToiDa;
	this->KichThuoc = KichThuoc;
	this->KhoangSangGam = KhoangSangGam;
	this->ChieuDaiCoSo = ChieuDaiCoSo;
	this->PhanCapXe = PhanCapXe;
	this->TonKho = TonKho;
	this->CongSuatToiDa = CongSuatToiDa;
	this->pointer = NULL;
}

NodeXe::~NodeXe()
{

}
