#pragma once
#include "NodeKhachHang.h"
#include <vector>
#include <string>

class KhachHang
{
private:
    NodeKhachHang* head;
    NodeKhachHang* tail;

public:
    KhachHang();
    virtual ~KhachHang();
    void NhapDuLieuThongTinKhachHang();
    void ThemThongTinKhachHang(NodeKhachHang*);
    void XoaThongTinKhachHang(std::string);
    void InputEditUserInfo();
    void SuaThongTinKhachHang(std::string, std::string, std::string);
    std::vector<NodeKhachHang> TimKiemThongTinKhachHang(std::string);
    std::vector<NodeKhachHang> XemTatCaThongTinKhachHang();
    void PrintTTKH(std::vector<NodeKhachHang>);
    void testanh();
};
