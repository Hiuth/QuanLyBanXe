#include "NodeCauHinhXe.h"

NodeCauHinhXe::NodeCauHinhXe(string MaCauHinh, string LoaiPin, string MauSac, string MaXe, string GiaPin)
{
	this->MaCauHinh = MaCauHinh;
	this->LoaiPin = LoaiPin;
	this->MauSac = MauSac;
	this->GiaPin = GiaPin;
	this->MaXe = MaXe;
	this->pointer = NULL;
}

NodeCauHinhXe::~NodeCauHinhXe()
{
	
}
