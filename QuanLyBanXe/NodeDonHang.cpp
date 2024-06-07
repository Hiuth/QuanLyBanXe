#include "NodeDonHang.h"


NodeDonHang::NodeDonHang(string MaDonHang, string sdt, string NgayDatHang, string NgayGiaoHangDuKien, long long TongGiaTriDonHang, string TrangThaiDonHang,
	int MaXe, int MaCauHinh, string PhuongThucThanhToan)
{
	this->MaDonHang = MaDonHang;
	this->sdt = sdt;
	this->NgayDatHang = NgayDatHang;
	this->NgayGiaoHangDuKien = NgayGiaoHangDuKien;
	this->TongGiaTriDonHang = TongGiaTriDonHang;
	this->TrangThaiDonHang = TrangThaiDonHang;
	this->MaXe = MaXe;
	this->MaCauHinh = MaCauHinh;
	this->PhuongThucThanhToan = PhuongThucThanhToan;
	this->pointer = NULL;
}
NodeDonHang::~NodeDonHang()
{

}