#include "NodeDaiLy.h"

NodeDaiLy::NodeDaiLy(string tendl , string thanhpho, string quan, string diachi , string sodienthoai, string trangthai)
{
	this->TenDaiLy = tendl;
	this->ThanhPho = thanhpho;
	this->Quan = quan;
	this->DiaChi = diachi;
	this->SDTDaiLy = sodienthoai;
	this->TrangThai = trangthai;
	this->pointer = NULL;
}

NodeDaiLy::NodeDaiLy(string madaily, string tendl, string thanhpho, string quan, string diachi, string sodienthoai,string trangthai)
{
	this->MaDaiLy = madaily;
	this->TenDaiLy = tendl;
	this->ThanhPho = thanhpho;
	this->Quan = quan;
	this->DiaChi = diachi;
	this->SDTDaiLy = sodienthoai;
	this->TrangThai = trangthai;
	this->pointer = NULL;
}

NodeDaiLy::NodeDaiLy(string madaily, string tendl, string thanhpho, string quan, string diachi, string sodienthoai, string trangthai, long long tongdoanhthu)
{
	this->MaDaiLy = madaily;
	this->TenDaiLy = tendl;
	this->ThanhPho = thanhpho;
	this->Quan = quan;
	this->DiaChi = diachi;
	this->SDTDaiLy = sodienthoai;
	this->TrangThai = trangthai;
	this->TongDoanhThu = tongdoanhthu;
	this->pointer = NULL;
}

NodeDaiLy::~NodeDaiLy()
{

}
