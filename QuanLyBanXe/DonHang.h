#include <string>
#include"NodeDonHang.h"
#include"NodeXe.h"
#include"NodeCauHinhXe.h"
#include"NodeDaiLy.h"
#include"QuanLyXe.h"
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
    vector<NodeDonHang> XemTatCaThongTinDonHang();
    void PrintTTDH( vector<NodeDonHang>);
};

