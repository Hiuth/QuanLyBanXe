#include "QuanLyKhachHang.h"
#include "KetNoi.h"
#include "CheckDuLieu.h"

KetNoi* Check_KhachHang = new KetNoi();
Connection* Check_KH = Check_KhachHang->CheckDatabase();
NodeKhachHang* N_KH;
KhachHang* KHACH = new KhachHang();
CheckDuLieu* DL_KH = new CheckDuLieu();
KhachHang::KhachHang()

{
    this->head = NULL;
    this->tail = NULL;
}

KhachHang::~KhachHang()
{
    // Giải phóng bộ nhớ nếu cần thiết
}
void KhachHang::NhapDuLieuThongTinKhachHang()
{
    string TenKhachHang, SinhNhat, CCCD, DiaChi, GioiTinh, SoDienThoai, Email;
    cout << "Nhap Email tai khoan can them thong tin khach hang: "; cin >> Email;
    if (DL_KH->CheckTKKH(Email)) {
        if (DL_KH->Check_DataUSer(Email)) {
            cout << "Tai khoan da co du lieu! " << endl;
        }
        else {
            cin.ignore();
            cout << "Ho va ten: "; getline(cin, TenKhachHang);
            cout << "Ngay thang nam sinh: "; cin >> SinhNhat;
            cout << "Gioi Tinh: "; cin >> GioiTinh;
            cout << "So can cuoc cong dan: "; cin >> CCCD;
            if (DL_KH->check12number(CCCD)) {
                if (DL_KH->Check_CCCD(CCCD)) {
                    cout << "So CCCD da ton tai! Vui long kiem tra lai";
                }
                else {
                    cout << "Nhap CCCD thanh cong" << endl;
                }
            }
            else {
                cout << "SO CCCD PHAI CO 12 SO VA KHONG DUOC CO KI TU KHAC NGOAI SO!" << endl;
            }

            cout << "So dien thoai: "; cin >> SoDienThoai;

            if (DL_KH->check10number(SoDienThoai)) {
                if (DL_KH->CheckSDT(SoDienThoai)) {
                    cout << "So dien thoai da ton tai! Vui long kiem tra lai";
                }
                else {
                    cout << "Nhap so dien thoai thanh cong" << endl;
                }
            }
            else {
                cout << "SO DIEN THOAI PHAI CO 10 SO VA KHONG DUOC CO KI TU KHAC NGOAI SO!" << endl;
            }
            cin.ignore();
            cout << "Dia chi: "; getline(cin, DiaChi);
            N_KH = new NodeKhachHang(TenKhachHang, SinhNhat, GioiTinh, SoDienThoai, CCCD, DiaChi, Email);
            KHACH->ThemThongTinKhachHang(N_KH);
            cout << endl;
        }

    }
    else {
        cout << "Tai khoan khong ton tai! Vui long kiem tra lai." << endl;
    }
}
void KhachHang::ThemThongTinKhachHang(NodeKhachHang* p)
{
    try {

        Statement* stmt;
        stmt = Check_KH->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "KhachHang";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
            string TenKhachHang;
            string SinhNhat;
            string CCCD;
            string DiaChi;
            string GioiTinh;
            string SoDienThoai;
            string Email;
            TenKhachHang = p->GetName();
            SinhNhat = p->GetBirthday();
            CCCD = p->GetIDCard();
            DiaChi = p->GetAddress();
            GioiTinh = p->GetSex();
            SoDienThoai = p->GetPhoneNumber();
            Email = p->GetEmail();
            string UpdateTableAccount = "insert into KhachHang  Values ('" + TenKhachHang + "','" + CCCD + "','" + SinhNhat + "','" + SoDienThoai + "','" + DiaChi + "','" + Email + "','" + GioiTinh + "');";
            stmt->execute(UpdateTableAccount);
            cout << "Du lieu da duoc cap nhat!" << endl;
        }
        else {
            cout << "Vui long kiem tra lai du lieu. " << endl;
        }

        delete result;
        delete stmt;
        delete p;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void KhachHang::InputEditUserInfo()
{
    int chon;
    string TenKhachHang, SinhNhat, CCCD, DiaChi, GioiTinh, SoDienThoai, Email, SoDienThoaiMoi;
    cout << "Nhap SDT tai khoan muon sua thong tin ca nhan : "; cin >> SoDienThoai;
    if (DL_KH->CheckSDT(SoDienThoai)) {
        cout << "Chon che do sua " << endl;
        cout << "1.Sua Ho va ten" << endl;
        cout << "2.Sua ngay thang nam sinh" << endl;
        cout << "3.Sua so can cuoc cong dan" << endl;
        cout << "4. Sua dia chi: " << endl;
        cout << "5. Sua gioi tinh: " << endl;
        cout << "6. Sua so dien thoai: " << endl;
        cout << " Moi chon: "; cin >> chon;
        if (chon == 1) {
            cin.ignore();
            cout << "Ho va Ten moi: "; getline(cin, TenKhachHang);
            KHACH->SuaThongTinKhachHang("TenKH", TenKhachHang, SoDienThoai);
        }
        else if (chon == 2) {
            cout << "Ngay thang nam sinh moi: "; cin >> SinhNhat;
            KHACH->SuaThongTinKhachHang("NgaySinh", SinhNhat, SoDienThoai);
        }
        else if (chon == 3) {
            cout << "So can cuoc cong dan moi: "; cin >> CCCD;
            KHACH->SuaThongTinKhachHang("SoCCCD", CCCD, SoDienThoai);
        }
        else if (chon == 4) {
            cin.ignore();
            cout << "Dia chi moi: "; getline(cin, DiaChi);
            KHACH->SuaThongTinKhachHang("DiaChi", DiaChi, SoDienThoai);

        }
        else if (chon == 5) {
            cout << "Sua gioi tinh: "; cin >> GioiTinh;
            KHACH->SuaThongTinKhachHang("GioiTinh", GioiTinh, SoDienThoai);
        }
        else if (chon == 6) {
            cout << "So dien thoai moi: "; cin >> SoDienThoaiMoi;
            if (DL_KH->CheckSDT(SoDienThoaiMoi)) {
                cout << "So dien thoai nay da duoc dang ki voi mot tai khoan khac" << endl;
            }
            else {
                KHACH->SuaThongTinKhachHang("SDT", SoDienThoaiMoi, SoDienThoai);
                //hàm sửa trong Đơn hàng ** nếu dữ liệu trong bảng rỗng thì không cần cập nhật 
                //hàm sửa trong lịch hẹn ** tương tự như trên 
            }
        }
        else {
            cout << "Khong co so nao! Vui long nhap lai!" << endl;
        }
    }
    else {
        cout << "Tai Khoan khong ton tai! Vui long kiem tra lai! " << endl;
    }
}
void KhachHang::SuaThongTinKhachHang(string ChoCanSua, string MuonDoiThanh, string SDT)
{
    try {
        Statement* stmt;
        stmt = Check_KH->createStatement();
        string SelectData = "UPDATE KhachHang SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE SDT = '" + SDT + "'";
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}
void KhachHang::SuaThongTinKhachHangMatTK(string ChoCanSua, string MuonDoiThanh, string Email)
{
    try {
        Statement* stmt;
        stmt = Check_KH->createStatement();
        string SelectData = "UPDATE KhachHang SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE UserEmail = '" + Email + "'";
        string SelectData2 = "UPDATE LICHHENBAODUONG SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE UserEmail = '" + Email + "'";
        string SelectData3 = "UPDATE DonHang SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE UserEmail = '" + Email + "'";
        string SelectData4 = "UPDATE YeuCauHoTro SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE UserEmail = '" + Email + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}
vector<NodeKhachHang> KhachHang::TimKiemThongTinKhachHang(string SDT)
{
    try {
        vector<NodeKhachHang> UserInfoSearch;
        Statement* stmt;
        stmt = Check_KH->createStatement();
        string SelectData = "Select *from KhachHang where SDT = '" + SDT + "'";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeKhachHang info(res->getString("TenKH"), res->getString("SoCCCD"), res->getString("NgaySinh"), res->getString("SDT"), res->getString("DiaChi"), res->getString("UserEmail"), res->getString("GioiTinh"));
            UserInfoSearch.push_back(info);
        }
        delete stmt;
        delete res;
        return UserInfoSearch;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}
vector<NodeKhachHang> KhachHang::XemTatCaThongTinKhachHang()
{
    vector<NodeKhachHang> UserInfo;
    Statement* stmt;
    stmt = Check_KH->createStatement();
    string SelectData = "Select *from KhachHang";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        NodeKhachHang account(res->getString("TenKH"), res->getString("SoCCCD"), res->getString("NgaySinh"), res->getString("SDT"), res->getString("DiaChi"), res->getString("UserEmail"), res->getString("GioiTinh"));
        UserInfo.push_back(account);
    }
    delete stmt;
    delete res;
    return UserInfo;
}
void KhachHang::PrintTTKH(vector<NodeKhachHang>check)
{
    for (int i = 0; i < check.size(); i++) {
        cout << check[i].GetName() << "\t" << check[i].GetSex() << "\t" << check[i].GetBirthday() << "\t" << check[i].GetPhoneNumber() << "\t" << check[i].GetIDCard() << "\t" << check[i].GetEmail() << "\t" << check[i].GetAddress() << endl;
    }
}