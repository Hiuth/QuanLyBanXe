#include "NodeKhachHang.h"

NodeKhachHang::NodeKhachHang(string TenKhachHang, string SinhNhat, string GioiTinh, string SoDienThoai, string CCCD, string DiaChi, string MaKhachHang) {
    this->TenKhachHang = TenKhachHang;
    this->SinhNhat = SinhNhat;
    this->CCCD = CCCD;
    this->SoDienThoai = SoDienThoai;
    this->DiaChi = DiaChi;
    this->GioiTinh = GioiTinh;
    this->MaKhachHang = MaKhachHang;
    this->pointer = NULL;
}

NodeKhachHang::~NodeKhachHang() {

}
