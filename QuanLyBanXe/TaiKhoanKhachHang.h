#pragma once
#include "NodeTaiKhoanKhachHang.h"
#include "NodeKhachHang.h"
#include<vector>
class TaiKhoanKhachHang
{
private:
    NodeTaiKhoanKhachHang* head;
    NodeTaiKhoanKhachHang* tail;

public:
    TaiKhoanKhachHang();
    virtual ~TaiKhoanKhachHang();
    void DangNhap();
    void NhapDuLieuTaiKhoanKhachHang();
    void TaoTaiKhoanKhachHang(NodeTaiKhoanKhachHang*);
    void InputDelete();
    void XoaTaiKhoanKhachHang(string);
    void InputEditUser();
    void InputEditUserinfo();
    void SuaTaiKhoanKhachHang(string, string, string);
};
