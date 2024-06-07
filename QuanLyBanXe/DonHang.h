#include <string>
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
    long long TongGiaTriDonHang();
    void Xoa();
    void XoaThongTinDonHang(string);
    void InputEditOrderInfo();
    void SuaThongTinDonHang(int, const string&, const string&);
    vector<NodeDonHang> TimKiemThongTinDonHang(int);
    vector<NodeDonHang> XemTatCaThongTinDonHang();
    void PrintTTDH(const vector<NodeDonHang>&);
};

