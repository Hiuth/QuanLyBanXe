#pragma once
#include "NodeDaiLy.h"
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
    void XoaThongTinDaiLy(std::string);
    void InputEditDaiLyInfo();
    void SuaThongTinDaiLy(std::string, std::string, std::string, std::string, std::string, std::string);
    void NhapThongTinDaiLyCanTim();
    std::vector<NodeDaiLy> TimKiemThongTinDaiLy( std::string ThanhPho, std::string Quan);
    std::vector<NodeDaiLy> XemTatCaThongTinDaiLy();
    void InTTDL(std::vector<NodeDaiLy>);
    void TestAnh();
};
