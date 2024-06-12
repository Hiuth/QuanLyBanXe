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
    string  MaXe;
    string MaCauHinh;
    string PhuongThucThanhToan;
    string StoreID;
    NodeDonHang* pointer;

public:

    NodeDonHang(string, string, string, string, string, string, long long, string, string, string);
    NodeDonHang(string, string, string, string, string, long long, string, string, string);
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

    string GetMaXe() const { return MaXe; }
    void SetMaXe(string val) { MaXe = val; }

    string GetMaCauHinh() const { return MaCauHinh; }
    void SetMaCauHinh(string val) { MaCauHinh = val; }

    string GetPhuongThucThanhToan() const { return PhuongThucThanhToan; }
    void SetPhuongThucThanhToan(string val) { PhuongThucThanhToan = val; }

    string LayMaCuaHang() { return StoreID; }
    void CaiDatMaCuaHang(string val) { StoreID = val; }

    NodeDonHang* GetPointer() const { return pointer; }
    void SetPointer(NodeDonHang* val) { pointer = val; }

};

