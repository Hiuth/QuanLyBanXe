#include "NodeTaiKhoanQuanTri.h"

NodeTaiKhoanQuanTri::NodeTaiKhoanQuanTri(string ID, string Email, string Name,string Pass)
{
	this->ManagerAccountID = ID;
	this->ManagerAccountEmail = Email;
	this->ManagerAccountName = Name;
	this->ManagerAccountPass = Pass;
}

NodeTaiKhoanQuanTri::~NodeTaiKhoanQuanTri() {

}
