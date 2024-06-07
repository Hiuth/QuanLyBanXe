#pragma once
#include <iostream>
#include <string>

using namespace std;

class NodeDonHang {
private:
    string MaDonHang;
    string sdt;
    string NgayDatHang;
    string NgayGiaoHangDuKien;
    long long TongGiaTriDonHang;
    string TrangThaiDonHang;
    int MaXe;
    int MaCauHinh;
    string PhuongThucThanhToan;
    NodeDonHang* pointer;

public:

    NodeDonHang(string, string, string, string, long long, string, int, int, string);
    virtual ~NodeDonHang() {}

    string GetMaDonHang() { return MaDonHang; }
    void SetMaDonHang(int val) { MaDonHang = val; }

    string GetSDT() { return sdt; }
    void SetSDT(string val) { sdt = val; }

    string GetNgayDatHang() { return NgayDatHang; }
    void SetNgayDatHang(string val) { NgayDatHang = val; }

    string GetNgayGiaoHangDuKien() { return NgayGiaoHangDuKien; }
    void SetNgayGiaoHangDuKien(string val) { NgayGiaoHangDuKien = val; }

    long long GetTongGiaTriDonHang() { return TongGiaTriDonHang; }
    void SetTongGiaTriDonHang(long long val) { TongGiaTriDonHang = val; }

    string GetTrangThaiDonHang() { return TrangThaiDonHang; }
    void SetTrangThaiDonHang(string val) { TrangThaiDonHang = val; }

    int GetMaXe() { return MaXe; }
    void SetMaXe(int val) { MaXe = val; }

    int GetMaCauHinh() { return MaCauHinh; }
    void SetMaCauHinh(int val) { MaCauHinh = val; }

    string GetPhuongThucThanhToan() { return PhuongThucThanhToan; }
    void SetPhuongThucThanhToan(string val) { PhuongThucThanhToan = val; }

    NodeDonHang* GetPointer() { return pointer; }
    void SetPointer(NodeDonHang* val) { pointer = val; }

    long long GetTongGiaTriDonHang() const { return TongGiaTriDonHang; }
};

