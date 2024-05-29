#pragma once
#include <string>
using namespace std;

class NodeKhachHang {
private:
    string TenKhachHang;
    string SinhNhat;
    string CCCD;
    string DiaChi;
    string GioiTinh;
    string MaKhachHang;
    string SoDienThoai;
    NodeKhachHang* pointer;

public:
    NodeKhachHang(string, string, string, string, string, string, string);
    virtual ~NodeKhachHang();

    string GetName() { return TenKhachHang; }
    void SetName(string val) { TenKhachHang = val; }

    string GetBirthday() { return SinhNhat; }
    void SetBirthday(string val) { SinhNhat = val; }

    string GetAddress() { return DiaChi; }
    void SetAddress(string val) { DiaChi = val; }

    string GetSex() { return GioiTinh; }
    void SetSex(string val) { GioiTinh = val; }

    string GetIDCard() { return CCCD; }
    void SetIDCard(string val) { CCCD = val; }

    string GetCustomerID() { return MaKhachHang; }
    void SetCustomerID(string val) { MaKhachHang = val; }

    string GetPhoneNumber() { return SoDienThoai; }
    void SetPhoneNumber(string val) { SoDienThoai = val; }

    NodeKhachHang* GetPointer() { return pointer; }
    void SetPointer(NodeKhachHang* val) { pointer = val; }
};

