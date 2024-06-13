#include "NodeDonHang.h"


NodeDonHang::NodeDonHang(string MaDonHang, string sdt, string MaCauHinh, string MaXe,string NgayDatHang, string NgayGiaoHangDuKien, long long TongGiaTriDonHang,string TrangThaiDonHang, string PhuongThucThanhToan,string storeID,string email)
{
	this->MaDonHang = MaDonHang;
	this->sdt = sdt;
	this->MaCauHinh = MaCauHinh;
	this->MaXe = MaXe;
	this->NgayDatHang = NgayDatHang;
	this->NgayGiaoHangDuKien = NgayGiaoHangDuKien;
	this->TongGiaTriDonHang = TongGiaTriDonHang;
	this->TrangThaiDonHang = TrangThaiDonHang;
	this->PhuongThucThanhToan = PhuongThucThanhToan;
	this->StoreID = storeID;
	this->Email = email;
	this->pointer = NULL;
}

NodeDonHang::NodeDonHang(string sdt, string MaCauHinh, string MaXe, string NgayDatHang, string NgayGiaoHangDuKien, long long TongGiaTriDonHang, string TrangThaiDonHang, string PhuongThucThanhToan, string storeID, string email)
{
	this->sdt = sdt;
	this->MaCauHinh = MaCauHinh;
	this->MaXe = MaXe;
	this->NgayDatHang = NgayDatHang;
	this->NgayGiaoHangDuKien = NgayGiaoHangDuKien;
	this->TongGiaTriDonHang = TongGiaTriDonHang;
	this->TrangThaiDonHang = TrangThaiDonHang;
	this->PhuongThucThanhToan = PhuongThucThanhToan;
	this->StoreID = storeID;
	this->Email = email;
	this->pointer = NULL;
}

NodeDonHang::~NodeDonHang()
{

}