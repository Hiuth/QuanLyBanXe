#pragma once
#include "NodeGioHang.h"
#include "DonHang.h"
#include <vector>
#include <string>

using namespace std;

class GioHang {
private:
    NodeGioHang* head;
    NodeGioHang* tail;
    DonHang* orderManager;  

public:
    GioHang();
    virtual ~GioHang();
    void ThemVaoGioHang(NodeGioHang* p);
    long long TinhTongGiaTriGioHang(const vector<NodeGioHang>& danhSachGioHang);
    vector<NodeGioHang> XemTatCaGioHang();
    void XoaGioHang(string maGH);
    vector<NodeGioHang> TimKiemGioHang(string maGH);
    void SuaGioHang(string maGH, int soLuong, long long tongGia, string userEmail);
};

