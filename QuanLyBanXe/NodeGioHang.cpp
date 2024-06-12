#include "NodeGioHang.h"

NodeGioHang::NodeGioHang(string maGH, string maDonHang, int soLuong, long long tongGia, string userEmail) {
    this->MaGH = maGH;
    this->MaDonHang = maDonHang;
    this->SoLuong = soLuong;
    this->TongGia = tongGia;
    this->UserEmail = userEmail;
    this->pointer = nullptr;
}

NodeGioHang::~NodeGioHang() {
    
}

