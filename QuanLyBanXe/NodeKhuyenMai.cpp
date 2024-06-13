#include "NodeKhuyenMai.h"

NodeKhuyenMai::NodeKhuyenMai(string NoiDung)
{
	this->NoiDung = NoiDung;
	this->pointer = NULL;
}

NodeKhuyenMai::NodeKhuyenMai(string MaKM, string NoiDung)
{
	this->MaKM = MaKM;
	this->NoiDung = NoiDung;
	this->pointer = NULL;
}

NodeKhuyenMai::~NodeKhuyenMai()
{

}
