#pragma once
#include <string>
using namespace std;

class NodeTaiKhoanKhachHang
{
private:
    string CustomerAccountID;
    string CustomerAccountEmail;
    string CustomerAccountName;
    string CustomerAccountPass;
public:
    NodeTaiKhoanKhachHang(string ID, string Email, string Name, string Pass);
    NodeTaiKhoanKhachHang( string Email, string Name, string Pass);
    virtual ~NodeTaiKhoanKhachHang();
    string GetID() { return CustomerAccountID; }
    void SetID(string val) { CustomerAccountID = val; }
    string GetEmail() { return CustomerAccountEmail; }
    void SetEmail(string val) { CustomerAccountEmail = val; }
    string GetName() { return CustomerAccountName; }
    void SetName(string val) { CustomerAccountName = val; }
    string GetPass() { return CustomerAccountPass; }
    void SetPass(string val) { CustomerAccountPass = val; }
};