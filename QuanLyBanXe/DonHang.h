#pragma once
#include <string>
#include"NodeDonHang.h"
#include"NodeCauHinhXe.h"
#include"NodeDaiLy.h"
#include"QuanLyXe.h"
#include"QuanLyKhachHang.h"
using namespace std;

class DonHang {
private:
    NodeDonHang* head;
    NodeDonHang* tail;

public:
    DonHang();
    virtual ~DonHang();
    void NhapDuLieuThongTinDonHang();
    void ThemThongTinDonHang(NodeDonHang*);
    void check_TGT();
    long long TongGiaTriDonHang(string,string,string);
    void Xoa();
    void XoaThongTinDonHang(string);
    void InputEditOrderInfo();
    void InputSearchOrder();
    void SuaThongTinDonHang(string, string, string);
    vector<NodeDonHang> TimKiemThongTinDonHang(string);
    vector<NodeDonHang> TimKiemThongTinDonHangTheoDaiLy(string);
    vector<NodeDonHang> XemTatCaThongTinDonHang();


    vector<NodeDonHang> GioHang(string);

    long long TinhTongGiaTriGioHang(vector<NodeDonHang>);
    void PrintTTDH( vector<NodeDonHang>);
    void PrintGioHang();

    void CapNhatTonKho(string);
    bool KiemTraTonKho(string);
};

