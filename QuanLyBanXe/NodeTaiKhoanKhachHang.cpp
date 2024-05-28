#include "NodeTaiKhoanKhachHang.h"

NodeTaiKhoanKhachHang::NodeTaiKhoanKhachHang(string ID, string Email, string Name, string Pass)
{
    this->CustomerAccountID = ID;
    this->CustomerAccountEmail = Email;
    this->CustomerAccountName = Name;
    this->CustomerAccountPass = Pass;
}

NodeTaiKhoanKhachHang::~NodeTaiKhoanKhachHang() {

}

