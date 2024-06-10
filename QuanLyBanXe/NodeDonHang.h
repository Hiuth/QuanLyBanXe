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
    virtual ~NodeDonHang();

    string GetMaDonHang() const { return MaDonHang; }
    void SetMaDonHang(int val) { MaDonHang = val; }

    string GetSDT() const { return sdt; }
    void SetSDT(string val) { sdt = val; }

    string GetNgayDatHang() const { return NgayDatHang; }
    void SetNgayDatHang(string val) { NgayDatHang = val; }

    string GetNgayGiaoHangDuKien() const { return NgayGiaoHangDuKien; }
    void SetNgayGiaoHangDuKien(string val) { NgayGiaoHangDuKien = val; }

    long long GetTongGiaTriDonHang() const { return TongGiaTriDonHang; }
    void SetTongGiaTriDonHang(long long val) { TongGiaTriDonHang = val; }

    string GetTrangThaiDonHang() const { return TrangThaiDonHang; }
    void SetTrangThaiDonHang(string val) { TrangThaiDonHang = val; }

    int GetMaXe() const { return MaXe; }
    void SetMaXe(int val) { MaXe = val; }

    int GetMaCauHinh() const { return MaCauHinh; }
    void SetMaCauHinh(int val) { MaCauHinh = val; }

    string GetPhuongThucThanhToan() const { return PhuongThucThanhToan; }
    void SetPhuongThucThanhToan(string val) { PhuongThucThanhToan = val; }

    NodeDonHang* GetPointer() const { return pointer; }
    void SetPointer(NodeDonHang* val) { pointer = val; }

};

