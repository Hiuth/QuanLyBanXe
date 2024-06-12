#pragma once
#include <string>

using namespace std;

class NodeGioHang {
private:
    string MaGH;
    string MaDonHang;
    int SoLuong;
    long long TongGia;
    string UserEmail;
    NodeGioHang* pointer;

public:
    NodeGioHang(string maGH, string maDonHang, int soLuong, long long tongGia, string userEmail);
    virtual ~NodeGioHang();

    string GetMaGH() const { return MaGH; }
    void SetMaGH(int val) { MaGH = val; }

    string GetMaDonHang() const { return MaDonHang; }
    void SetMaDonHang(int val) { MaDonHang = val; }

    int GetSoLuong() const { return SoLuong; }
    void SetSoLuong(int val) { SoLuong = val; }

    long long GetTongGia() const { return TongGia; }
    void SetTongGia(long long val) { TongGia = val; }

    string GetUserEmail() const { return UserEmail; }
    void SetUserEmail(string val) { UserEmail = val; }

    NodeGioHang* GetPointer() const { return pointer; }
    void SetPointer(NodeGioHang* val) { pointer = val; }
};
