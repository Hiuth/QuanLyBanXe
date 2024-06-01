#pragma once
#include "NodeTaiKhoanKhachHang.h"
#include <vector>
using namespace std;

class TaiKhoanKhachHang
{
private:
    NodeTaiKhoanKhachHang* head;
    NodeTaiKhoanKhachHang* tail;

public:
    TaiKhoanKhachHang();
    virtual ~TaiKhoanKhachHang();
};