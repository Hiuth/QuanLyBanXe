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
    void SuaThongTinDaiLy(string, string, string, string, string);
    std::vector<NodeDaiLy> TimKiemThongTinDaiLy( string);
    std::vector<NodeDaiLy> XemTatCaThongTinDaiLy();
    void InTTDL( vector<NodeDaiLy>);
    void TestAnh();
};


