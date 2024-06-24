#include "NodeHoTro.h"

NodeHoTro::NodeHoTro(string useremail, string sdt,string loaihotro, string mota, string trangthai)
{
	this->UserEmail = useremail;
	this->sdt = sdt;
	this->loaihotro = loaihotro;
	this->mota = mota;
	this->trangthai = trangthai;
	this->pointer = NULL;
}

NodeHoTro::~NodeHoTro()
{

}
