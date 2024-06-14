#pragma once
#include "NodeDaiLy.h"
#include "NodeKhuyenMai.h"
#include"DonHang.h"
#include <vector>
#include <string>

class DaiLy {
private:
    NodeDaiLy* head;
    NodeDaiLy* tail;

public:
    DaiLy();
    virtual ~DaiLy();
    void NhapDuLieuThongTinDaiLy();
    void ThemThongTinDaiLy(NodeDaiLy*);
    void XoaThongTinDaiLy(string,string);
    void InputEditDaiLyInfo();
    void SuaThongTinDaiLy(std::string, std::string, std::string, std::string);
    void NhapThongTinDaiLyCanTim();
    std::vector<NodeDaiLy> TimKiemThongTinDaiLy( std::string ThanhPho, std::string Quan);
    std::vector<NodeDaiLy> XemTatCaThongTinDaiLy();
    std::vector<NodeDaiLy> XemTatCaThongTinDaiLyVaDoanhThu();
    void InTTDL(std::vector<NodeDaiLy>);
    void InTTDLvaDT(std::vector<NodeDaiLy>);

    long long TongdoanhThuTungDaiLy(string);
    void ThemThongTinKhuyenMai(NodeKhuyenMai*);
    void XoaThongTinKhuyenMai(string);
    void SuaThongTinKhuyenMai(string, string, string);
    vector<NodeKhuyenMai> TimKiemThongTinKhuyenMai(string);
    vector<NodeKhuyenMai> XemThongtinKhuyenMai();
    void InThongTinKhuyenMai(vector<NodeKhuyenMai>);

    void CapNhatTrangThaiDaiLy();
};
