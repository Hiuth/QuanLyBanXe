#include "NodeQuan.h"

NodeQuan::NodeQuan(string Quan, string ThanhPho)
{
	this->ThanhPho = ThanhPho;
	this->Quan = Quan;
}

NodeQuan::NodeQuan(string Quan)
{
	this->Quan = Quan;
}

NodeQuan::~NodeQuan()
{

}
