#include "NodeDaiLy.h"

NodeDaiLy::NodeDaiLy(string tendl , string thanhpho, string quan, string diachi , string sodienthoai)
{
	this->TenDaiLy = tendl;
	this->ThanhPho = thanhpho;
	this->Quan = quan;
	this->DiaChi = diachi;
	this->SDTDaiLy = sodienthoai;
	this->pointer = NULL;
}

NodeDaiLy::NodeDaiLy(string madaily, string tendl, string thanhpho, string quan, string diachi, string sodienthoai)
{
	this->MaDaiLy = madaily;
	this->TenDaiLy = tendl;
	this->ThanhPho = thanhpho;
	this->Quan = quan;
	this->DiaChi = diachi;
	this->SDTDaiLy = sodienthoai;
	this->pointer = NULL;
}

NodeDaiLy::~NodeDaiLy()
{

}
