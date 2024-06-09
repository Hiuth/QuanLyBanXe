#include "NodeLHBaoDuong.h"

NodeLHBaoDuong::NodeLHBaoDuong(string NgayHen, string ThoiGianHen, string LoaiDichVu, string BienSo, string MaXe, string SoDienThoai, string MaCuaHang, string UserEmail)
{
	this->NgayHen = NgayHen;
	this->ThoiGianHen = ThoiGianHen;
	this->LoaiDichVu = LoaiDichVu;
	this->BienSo = BienSo;
	this->MaXe = MaXe;
	this->SoDienThoai = SoDienThoai;
	this->MaCuaHang = MaCuaHang;
	this->UserEmail = UserEmail;
	this->pointer = NULL;
}

NodeLHBaoDuong::~NodeLHBaoDuong()
{

}
